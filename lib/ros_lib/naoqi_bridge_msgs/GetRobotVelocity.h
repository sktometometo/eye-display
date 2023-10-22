#ifndef _ROS_SERVICE_GetRobotVelocity_h
#define _ROS_SERVICE_GetRobotVelocity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace naoqi_bridge_msgs
{

static const char GETROBOTVELOCITY[] = "naoqi_bridge_msgs/GetRobotVelocity";

  class GetRobotVelocityRequest : public ros::Msg
  {
    public:

    GetRobotVelocityRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETROBOTVELOCITY; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetRobotVelocityResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _velocity_type;
      _velocity_type velocity;

    GetRobotVelocityResponse():
      velocity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->velocity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->velocity.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETROBOTVELOCITY; };
    virtual const char * getMD5() override { return "c7efbe4dfb780c96cc3a4fd21d1bc573"; };

  };

  class GetRobotVelocity {
    public:
    typedef GetRobotVelocityRequest Request;
    typedef GetRobotVelocityResponse Response;
  };

}
#endif
