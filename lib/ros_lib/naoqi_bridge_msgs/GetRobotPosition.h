#ifndef _ROS_SERVICE_GetRobotPosition_h
#define _ROS_SERVICE_GetRobotPosition_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace naoqi_bridge_msgs
{

static const char GETROBOTPOSITION[] = "naoqi_bridge_msgs/GetRobotPosition";

  class GetRobotPositionRequest : public ros::Msg
  {
    public:
      typedef bool _use_sensors_values_type;
      _use_sensors_values_type use_sensors_values;

    GetRobotPositionRequest():
      use_sensors_values(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_use_sensors_values;
      u_use_sensors_values.real = this->use_sensors_values;
      *(outbuffer + offset + 0) = (u_use_sensors_values.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_sensors_values);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_use_sensors_values;
      u_use_sensors_values.base = 0;
      u_use_sensors_values.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_sensors_values = u_use_sensors_values.real;
      offset += sizeof(this->use_sensors_values);
     return offset;
    }

    virtual const char * getType() override { return GETROBOTPOSITION; };
    virtual const char * getMD5() override { return "130d66500b7994a351a87ffc11ef04a7"; };

  };

  class GetRobotPositionResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _pose_type;
      _pose_type pose;

    GetRobotPositionResponse():
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETROBOTPOSITION; };
    virtual const char * getMD5() override { return "271cb12677c4cd9bccbc642cd9258d1f"; };

  };

  class GetRobotPosition {
    public:
    typedef GetRobotPositionRequest Request;
    typedef GetRobotPositionResponse Response;
  };

}
#endif
