#ifndef _ROS_naoqi_bridge_msgs_SmileProperties_h
#define _ROS_naoqi_bridge_msgs_SmileProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class SmileProperties : public ros::Msg
  {
    public:
      typedef float _smile_degree_type;
      _smile_degree_type smile_degree;
      typedef float _confidence_type;
      _confidence_type confidence;

    SmileProperties():
      smile_degree(0),
      confidence(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->smile_degree);
      offset += serializeAvrFloat64(outbuffer + offset, this->confidence);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->smile_degree));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->confidence));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/SmileProperties"; };
    virtual const char * getMD5() override { return "8ae6300d8d64c574d45abc2aad62d16d"; };

  };

}
#endif
