#ifndef _ROS_naoqi_bridge_msgs_ExpressionProperties_h
#define _ROS_naoqi_bridge_msgs_ExpressionProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class ExpressionProperties : public ros::Msg
  {
    public:
      typedef float _neutral_type;
      _neutral_type neutral;
      typedef float _happy_type;
      _happy_type happy;
      typedef float _surprised_type;
      _surprised_type surprised;
      typedef float _angry_type;
      _angry_type angry;
      typedef float _sad_type;
      _sad_type sad;

    ExpressionProperties():
      neutral(0),
      happy(0),
      surprised(0),
      angry(0),
      sad(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->neutral);
      offset += serializeAvrFloat64(outbuffer + offset, this->happy);
      offset += serializeAvrFloat64(outbuffer + offset, this->surprised);
      offset += serializeAvrFloat64(outbuffer + offset, this->angry);
      offset += serializeAvrFloat64(outbuffer + offset, this->sad);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->neutral));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->happy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->surprised));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angry));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sad));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/ExpressionProperties"; };
    virtual const char * getMD5() override { return "b74c34b9a54ded7dcbc8532c010d2029"; };

  };

}
#endif
