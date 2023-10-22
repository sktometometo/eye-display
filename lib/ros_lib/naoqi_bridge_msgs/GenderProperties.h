#ifndef _ROS_naoqi_bridge_msgs_GenderProperties_h
#define _ROS_naoqi_bridge_msgs_GenderProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class GenderProperties : public ros::Msg
  {
    public:
      typedef uint8_t _gender_type;
      _gender_type gender;
      typedef float _confidence_type;
      _confidence_type confidence;
      enum { FEMALE = 0 };
      enum { MALE = 1 };

    GenderProperties():
      gender(0),
      confidence(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->gender >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gender);
      offset += serializeAvrFloat64(outbuffer + offset, this->confidence);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->gender =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gender);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->confidence));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/GenderProperties"; };
    virtual const char * getMD5() override { return "1c9b9966c32a90087402a785abff5645"; };

  };

}
#endif
