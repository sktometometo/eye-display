#ifndef _ROS_SERVICE_VisionMotionSensitivity_h
#define _ROS_SERVICE_VisionMotionSensitivity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float32.h"

namespace nao_interaction_msgs
{

static const char VISIONMOTIONSENSITIVITY[] = "nao_interaction_msgs/VisionMotionSensitivity";

  class VisionMotionSensitivityRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Float32 _sensitivity_type;
      _sensitivity_type sensitivity;

    VisionMotionSensitivityRequest():
      sensitivity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->sensitivity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->sensitivity.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return VISIONMOTIONSENSITIVITY; };
    virtual const char * getMD5() override { return "ef4dcf0f6275a2f726c89cb40c7fcf0f"; };

  };

  class VisionMotionSensitivityResponse : public ros::Msg
  {
    public:

    VisionMotionSensitivityResponse()
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

    virtual const char * getType() override { return VISIONMOTIONSENSITIVITY; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class VisionMotionSensitivity {
    public:
    typedef VisionMotionSensitivityRequest Request;
    typedef VisionMotionSensitivityResponse Response;
  };

}
#endif
