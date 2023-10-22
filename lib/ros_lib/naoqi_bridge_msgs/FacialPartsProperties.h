#ifndef _ROS_naoqi_bridge_msgs_FacialPartsProperties_h
#define _ROS_naoqi_bridge_msgs_FacialPartsProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace naoqi_bridge_msgs
{

  class FacialPartsProperties : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _left_eye_center_point_type;
      _left_eye_center_point_type left_eye_center_point;
      typedef float _left_eye_center_confidence_type;
      _left_eye_center_confidence_type left_eye_center_confidence;
      typedef geometry_msgs::Pose2D _right_eye_center_point_type;
      _right_eye_center_point_type right_eye_center_point;
      typedef float _right_eye_center_confidence_type;
      _right_eye_center_confidence_type right_eye_center_confidence;
      typedef geometry_msgs::Pose2D _mouth_center_point_type;
      _mouth_center_point_type mouth_center_point;
      typedef float _mouth_center_confidence_type;
      _mouth_center_confidence_type mouth_center_confidence;
      typedef geometry_msgs::Pose2D _left_eye_inner_limit_type;
      _left_eye_inner_limit_type left_eye_inner_limit;
      typedef float _left_eye_inner_limit_confidence_type;
      _left_eye_inner_limit_confidence_type left_eye_inner_limit_confidence;
      typedef geometry_msgs::Pose2D _left_eye_outer_limit_type;
      _left_eye_outer_limit_type left_eye_outer_limit;
      typedef float _left_eye_outer_limit_confidence_type;
      _left_eye_outer_limit_confidence_type left_eye_outer_limit_confidence;
      typedef geometry_msgs::Pose2D _right_eye_inner_limit_type;
      _right_eye_inner_limit_type right_eye_inner_limit;
      typedef float _right_eye_inner_limit_confidence_type;
      _right_eye_inner_limit_confidence_type right_eye_inner_limit_confidence;
      typedef geometry_msgs::Pose2D _right_eye_outer_limit_type;
      _right_eye_outer_limit_type right_eye_outer_limit;
      typedef float _right_eye_outer_limit_confidence_type;
      _right_eye_outer_limit_confidence_type right_eye_outer_limit_confidence;
      typedef geometry_msgs::Pose2D _mouth_left_limit_type;
      _mouth_left_limit_type mouth_left_limit;
      typedef float _mouth_left_limit_confidence_type;
      _mouth_left_limit_confidence_type mouth_left_limit_confidence;
      typedef geometry_msgs::Pose2D _mouth_right_limit_type;
      _mouth_right_limit_type mouth_right_limit;
      typedef float _mouth_right_limit_confidence_type;
      _mouth_right_limit_confidence_type mouth_right_limit_confidence;
      typedef geometry_msgs::Pose2D _nose_left_limit_type;
      _nose_left_limit_type nose_left_limit;
      typedef float _nose_left_limit_confidence_type;
      _nose_left_limit_confidence_type nose_left_limit_confidence;
      typedef geometry_msgs::Pose2D _nose_right_limit_type;
      _nose_right_limit_type nose_right_limit;
      typedef float _nose_right_limit_confidence_type;
      _nose_right_limit_confidence_type nose_right_limit_confidence;
      typedef geometry_msgs::Pose2D _mouth_upper_limit_type;
      _mouth_upper_limit_type mouth_upper_limit;
      typedef float _mouth_upper_limit_confidence_type;
      _mouth_upper_limit_confidence_type mouth_upper_limit_confidence;

    FacialPartsProperties():
      left_eye_center_point(),
      left_eye_center_confidence(0),
      right_eye_center_point(),
      right_eye_center_confidence(0),
      mouth_center_point(),
      mouth_center_confidence(0),
      left_eye_inner_limit(),
      left_eye_inner_limit_confidence(0),
      left_eye_outer_limit(),
      left_eye_outer_limit_confidence(0),
      right_eye_inner_limit(),
      right_eye_inner_limit_confidence(0),
      right_eye_outer_limit(),
      right_eye_outer_limit_confidence(0),
      mouth_left_limit(),
      mouth_left_limit_confidence(0),
      mouth_right_limit(),
      mouth_right_limit_confidence(0),
      nose_left_limit(),
      nose_left_limit_confidence(0),
      nose_right_limit(),
      nose_right_limit_confidence(0),
      mouth_upper_limit(),
      mouth_upper_limit_confidence(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->left_eye_center_point.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_eye_center_confidence);
      offset += this->right_eye_center_point.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_eye_center_confidence);
      offset += this->mouth_center_point.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->mouth_center_confidence);
      offset += this->left_eye_inner_limit.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_eye_inner_limit_confidence);
      offset += this->left_eye_outer_limit.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_eye_outer_limit_confidence);
      offset += this->right_eye_inner_limit.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_eye_inner_limit_confidence);
      offset += this->right_eye_outer_limit.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_eye_outer_limit_confidence);
      offset += this->mouth_left_limit.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->mouth_left_limit_confidence);
      offset += this->mouth_right_limit.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->mouth_right_limit_confidence);
      offset += this->nose_left_limit.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->nose_left_limit_confidence);
      offset += this->nose_right_limit.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->nose_right_limit_confidence);
      offset += this->mouth_upper_limit.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->mouth_upper_limit_confidence);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->left_eye_center_point.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_eye_center_confidence));
      offset += this->right_eye_center_point.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_eye_center_confidence));
      offset += this->mouth_center_point.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mouth_center_confidence));
      offset += this->left_eye_inner_limit.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_eye_inner_limit_confidence));
      offset += this->left_eye_outer_limit.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_eye_outer_limit_confidence));
      offset += this->right_eye_inner_limit.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_eye_inner_limit_confidence));
      offset += this->right_eye_outer_limit.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_eye_outer_limit_confidence));
      offset += this->mouth_left_limit.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mouth_left_limit_confidence));
      offset += this->mouth_right_limit.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mouth_right_limit_confidence));
      offset += this->nose_left_limit.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->nose_left_limit_confidence));
      offset += this->nose_right_limit.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->nose_right_limit_confidence));
      offset += this->mouth_upper_limit.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mouth_upper_limit_confidence));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/FacialPartsProperties"; };
    virtual const char * getMD5() override { return "b29afd6a90b68507622b865d2df7f827"; };

  };

}
#endif
