#!/usr/bin/env python3

import sys
import io
import fcntl
import time
import rospy

from i2c_for_esp32 import WirePacker  # pip3 install i2c-for-esp32
from std_msgs.msg import UInt16

I2C_SLAVE = 0x0703

if sys.hexversion < 0x03000000:
   def _b(x):
      return x
else:
   def _b(x):
      return x.encode('latin-1')


class I2C(object):

   def __init__(self, device=0x42, bus=0):
      self.fr = io.open("/dev/i2c-"+str(bus), "rb", buffering=0)
      self.fw = io.open("/dev/i2c-"+str(bus), "wb", buffering=0)
      # set device address
      fcntl.ioctl(self.fr, I2C_SLAVE, device)
      fcntl.ioctl(self.fw, I2C_SLAVE, device)

   def write(self, data):
      if type(data) is list:
         data = bytearray(data)
      elif type(data) is str:
         data = _b(data)
      self.fw.write(data)

   def read(self, count):
      return self.fr.read(count)

   def close(self):
      self.fw.close()
      self.fr.close()


i2c = I2C(bus=0)


def send_eye_status(eye_status=0):
   sent_str = str(eye_status)
   packer = WirePacker(buffer_size=len(sent_str) + 8)
   for s in sent_str:
      packer.write(ord(s))
   packer.end()
   if packer.available():
      packet = packer.buffer[:packer.available()]
      try:
         i2c.write(packet)
      except OSError as e:
         print(e)


def sub_eye_status_cb(msg):
   global eye_status
   eye_status = msg.data
   send_eye_status(eye_status)
   time.sleep(0.1)

if __name__ == '__main__':
   rospy.init_node('eye_status_to_I2C')
   rospy.Subscriber('/eye_status',UInt16,sub_eye_status_cb)
   rospy.spin()


# while True:
#     eye_status += 1
#     send_eye_status(eye_status)
#     time.sleep(5.0)
#     if eye_status > 6:
#         eye_status = 0
