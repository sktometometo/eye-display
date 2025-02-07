#!/usr/bin/env python

import rospy
from std_msgs.msg import UInt16
from eye_display.msg import EyeStatus

MODES_AND_NAMES = [
        (EyeStatus.EYE_STATUS_NORMAL, "Normal"),
        (EyeStatus.EYE_STATUS_BLINK, "Blink"),
        (EyeStatus.EYE_STATUS_SURPRISED, "Surprised"),
        (EyeStatus.EYE_STATUS_SLEEPY, "Sleepy"),
        (EyeStatus.EYE_STATUS_ANGRY, "Angry"),
        (EyeStatus.EYE_STATUS_SAD, "Sad"),
        (EyeStatus.EYE_STATUS_HAPPY, "Happy"),
#        (EyeStatus.EYE_STATUS_TROUBLED, "Troubled"),
#        (EyeStatus.EYE_STATUS_DELIGHTED, "Delighted"),
#        (EyeStatus.EYE_STATUS_EXPECTING, "Expecting"),
#        (EyeStatus.EYE_STATUS_HEART, "Heart"),
#        (EyeStatus.EYE_STATUS_SHINE, "Shine"),
#        (EyeStatus.EYE_STATUS_FLUSTRATED, "Flustrated"),
#        (EyeStatus.EYE_STATUS_BORING, "Boring"),
    ]


def main():
    rospy.init_node("pub_eye_status")
    msg = UInt16()

    pub = rospy.Publisher("/eye_status", UInt16, queue_size=10)

    rate = rospy.Rate(1.0/3)
    index = 0
    while not rospy.is_shutdown():
        mode, name = MODES_AND_NAMES[index % len(MODES_AND_NAMES)]
        rospy.loginfo("mode: {}".format(name))
        msg.data = mode
        pub.publish(msg)
        rate.sleep()
        index += 1


if __name__ == "__main__":
    main()
