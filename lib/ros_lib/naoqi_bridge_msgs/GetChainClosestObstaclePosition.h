#ifndef _ROS_SERVICE_GetChainClosestObstaclePosition_h
#define _ROS_SERVICE_GetChainClosestObstaclePosition_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/Frames.h"
#include "naoqi_bridge_msgs/Arms.h"
#include "geometry_msgs/Vector3.h"

namespace naoqi_bridge_msgs
{

static const char GETCHAINCLOSESTOBSTACLEPOSITION[] = "naoqi_bridge_msgs/GetChainClosestObstaclePosition";

  class GetChainClosestObstaclePositionRequest : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::Arms _arm_type;
      _arm_type arm;
      typedef naoqi_bridge_msgs::Frames _frame_type;
      _frame_type frame;

    GetChainClosestObstaclePositionRequest():
      arm(),
      frame()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->arm.serialize(outbuffer + offset);
      offset += this->frame.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->arm.deserialize(inbuffer + offset);
      offset += this->frame.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETCHAINCLOSESTOBSTACLEPOSITION; };
    virtual const char * getMD5() override { return "a77aef6f632c4702498892d88752d703"; };

  };

  class GetChainClosestObstaclePositionResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _obstacle_position_type;
      _obstacle_position_type obstacle_position;

    GetChainClosestObstaclePositionResponse():
      obstacle_position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->obstacle_position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->obstacle_position.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETCHAINCLOSESTOBSTACLEPOSITION; };
    virtual const char * getMD5() override { return "f3ec3b733fe31c7dae64d64e8e1afcf9"; };

  };

  class GetChainClosestObstaclePosition {
    public:
    typedef GetChainClosestObstaclePositionRequest Request;
    typedef GetChainClosestObstaclePositionResponse Response;
  };

}
#endif
