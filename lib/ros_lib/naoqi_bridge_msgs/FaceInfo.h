#ifndef _ROS_naoqi_bridge_msgs_FaceInfo_h
#define _ROS_naoqi_bridge_msgs_FaceInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/FaceDetectionShapeInfo.h"
#include "naoqi_bridge_msgs/FaceDetectionExtraInfo.h"

namespace naoqi_bridge_msgs
{

  class FaceInfo : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::FaceDetectionShapeInfo _shape_info_type;
      _shape_info_type shape_info;
      typedef naoqi_bridge_msgs::FaceDetectionExtraInfo _extra_info_type;
      _extra_info_type extra_info;

    FaceInfo():
      shape_info(),
      extra_info()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->shape_info.serialize(outbuffer + offset);
      offset += this->extra_info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->shape_info.deserialize(inbuffer + offset);
      offset += this->extra_info.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/FaceInfo"; };
    virtual const char * getMD5() override { return "2e2d9a0f337e4a0e817ee314a040eafa"; };

  };

}
#endif
