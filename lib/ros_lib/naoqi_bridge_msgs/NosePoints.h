#ifndef _ROS_naoqi_bridge_msgs_NosePoints_h
#define _ROS_naoqi_bridge_msgs_NosePoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class NosePoints : public ros::Msg
  {
    public:
      typedef float _bottom_center_limit_x_type;
      _bottom_center_limit_x_type bottom_center_limit_x;
      typedef float _bottom_center_limit_y_type;
      _bottom_center_limit_y_type bottom_center_limit_y;
      typedef float _bottom_left_limit_x_type;
      _bottom_left_limit_x_type bottom_left_limit_x;
      typedef float _bottom_left_limit_y_type;
      _bottom_left_limit_y_type bottom_left_limit_y;
      typedef float _bottom_right_limit_x_type;
      _bottom_right_limit_x_type bottom_right_limit_x;
      typedef float _bottom_right_limit_y_type;
      _bottom_right_limit_y_type bottom_right_limit_y;

    NosePoints():
      bottom_center_limit_x(0),
      bottom_center_limit_y(0),
      bottom_left_limit_x(0),
      bottom_left_limit_y(0),
      bottom_right_limit_x(0),
      bottom_right_limit_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->bottom_center_limit_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->bottom_center_limit_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->bottom_left_limit_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->bottom_left_limit_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->bottom_right_limit_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->bottom_right_limit_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bottom_center_limit_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bottom_center_limit_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bottom_left_limit_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bottom_left_limit_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bottom_right_limit_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bottom_right_limit_y));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/NosePoints"; };
    virtual const char * getMD5() override { return "12420504353d25416aa5ca37ed2bf21b"; };

  };

}
#endif
