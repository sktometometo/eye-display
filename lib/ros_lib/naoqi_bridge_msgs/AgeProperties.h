#ifndef _ROS_naoqi_bridge_msgs_AgeProperties_h
#define _ROS_naoqi_bridge_msgs_AgeProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class AgeProperties : public ros::Msg
  {
    public:
      typedef float _age_type;
      _age_type age;
      typedef float _confidence_type;
      _confidence_type confidence;

    AgeProperties():
      age(0),
      confidence(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->age);
      offset += serializeAvrFloat64(outbuffer + offset, this->confidence);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->age));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->confidence));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/AgeProperties"; };
    virtual const char * getMD5() override { return "5b55ed2179c20a2950a3645b24011abb"; };

  };

}
#endif
