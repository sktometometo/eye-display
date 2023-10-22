#ifndef _ROS_naoqi_bridge_msgs_MouthPoints_h
#define _ROS_naoqi_bridge_msgs_MouthPoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class MouthPoints : public ros::Msg
  {
    public:
      typedef float _left_limit_x_type;
      _left_limit_x_type left_limit_x;
      typedef float _left_limit_y_type;
      _left_limit_y_type left_limit_y;
      typedef float _right_limit_x_type;
      _right_limit_x_type right_limit_x;
      typedef float _right_limit_y_type;
      _right_limit_y_type right_limit_y;
      typedef float _top_limit_x_type;
      _top_limit_x_type top_limit_x;
      typedef float _top_limit_y_type;
      _top_limit_y_type top_limit_y;

    MouthPoints():
      left_limit_x(0),
      left_limit_y(0),
      right_limit_x(0),
      right_limit_y(0),
      top_limit_x(0),
      top_limit_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->left_limit_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_limit_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_limit_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_limit_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->top_limit_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->top_limit_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_limit_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_limit_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_limit_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_limit_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->top_limit_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->top_limit_y));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/MouthPoints"; };
    virtual const char * getMD5() override { return "ff2cf51755dd2c88d774f8f228fae943"; };

  };

}
#endif
