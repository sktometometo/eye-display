#ifndef _ROS_eye_display_EyeStatus_h
#define _ROS_eye_display_EyeStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace eye_display
{

  class EyeStatus : public ros::Msg
  {
    public:
      enum { EYE_STATUS_NORMAL = 0 };
      enum { EYE_STATUS_BLINK = 1 };
      enum { EYE_STATUS_SURPRISED = 2 };
      enum { EYE_STATUS_SLEEPY = 3 };
      enum { EYE_STATUS_ANGRY = 4 };
      enum { EYE_STATUS_SAD = 5 };
      enum { EYE_STATUS_HAPPY = 6 };
      enum { EYE_STATUS_TROUBLED = 7 };
      enum { EYE_STATUS_DELIGHTED = 8 };
      enum { EYE_STATUS_EXPECTING = 9 };
      enum { EYE_STATUS_HEART = 10 };
      enum { EYE_STATUS_SHINE = 11 };
      enum { EYE_STATUS_FLUSTRATED = 12 };
      enum { EYE_STATUS_BORING = 13 };

    EyeStatus()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return "eye_display/EyeStatus"; };
    virtual const char * getMD5() override { return "78f98b2a6b27818c86e9e651a10b9bef"; };

  };

}
#endif
