#!/usr/bin/env python
import rospy
from std_msgs.msg import UInt16


def main():
    rospy.init_node("pub_eye_status")
    msg = UInt16()
    
    # 送信者を作成する。
    pub = rospy.Publisher("/serial_node/eye_status", UInt16, queue_size=10)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        msg.data = 1
        pub.publish(msg)

        rospy.loginfo("Message '{}' published".format(msg.data))

        # 0.1 秒スリープする。
        rate.sleep()


if __name__ == "__main__":
    main()
