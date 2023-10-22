#ifndef _ROS_naoqi_bridge_msgs_EyePoints_h
#define _ROS_naoqi_bridge_msgs_EyePoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class EyePoints : public ros::Msg
  {
    public:
      typedef float _eye_center_x_type;
      _eye_center_x_type eye_center_x;
      typedef float _eye_center_y_type;
      _eye_center_y_type eye_center_y;
      typedef float _nose_side_limit_x_type;
      _nose_side_limit_x_type nose_side_limit_x;
      typedef float _nose_side_limit_y_type;
      _nose_side_limit_y_type nose_side_limit_y;
      typedef float _ear_side_limit_x_type;
      _ear_side_limit_x_type ear_side_limit_x;
      typedef float _ear_side_limit_y_type;
      _ear_side_limit_y_type ear_side_limit_y;

    EyePoints():
      eye_center_x(0),
      eye_center_y(0),
      nose_side_limit_x(0),
      nose_side_limit_y(0),
      ear_side_limit_x(0),
      ear_side_limit_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->eye_center_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->eye_center_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->nose_side_limit_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->nose_side_limit_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->ear_side_limit_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->ear_side_limit_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eye_center_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eye_center_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->nose_side_limit_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->nose_side_limit_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ear_side_limit_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ear_side_limit_y));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/EyePoints"; };
    virtual const char * getMD5() override { return "ce420619433f65576fc77ec7a7fa0ba2"; };

  };

}
#endif
