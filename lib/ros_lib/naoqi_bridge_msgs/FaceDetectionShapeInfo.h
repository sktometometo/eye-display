#ifndef _ROS_naoqi_bridge_msgs_FaceDetectionShapeInfo_h
#define _ROS_naoqi_bridge_msgs_FaceDetectionShapeInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class FaceDetectionShapeInfo : public ros::Msg
  {
    public:
      typedef float _alpha_type;
      _alpha_type alpha;
      typedef float _beta_type;
      _beta_type beta;
      typedef float _size_x_type;
      _size_x_type size_x;
      typedef float _size_y_type;
      _size_y_type size_y;

    FaceDetectionShapeInfo():
      alpha(0),
      beta(0),
      size_x(0),
      size_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->alpha);
      offset += serializeAvrFloat64(outbuffer + offset, this->beta);
      offset += serializeAvrFloat64(outbuffer + offset, this->size_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->size_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->alpha));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->beta));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->size_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->size_y));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/FaceDetectionShapeInfo"; };
    virtual const char * getMD5() override { return "21c4e8fbf229f3e5ab6971b421e3510f"; };

  };

}
#endif
