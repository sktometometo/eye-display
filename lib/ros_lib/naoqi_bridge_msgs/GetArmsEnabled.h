#ifndef _ROS_SERVICE_GetArmsEnabled_h
#define _ROS_SERVICE_GetArmsEnabled_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/Arms.h"

namespace naoqi_bridge_msgs
{

static const char GETARMSENABLED[] = "naoqi_bridge_msgs/GetArmsEnabled";

  class GetArmsEnabledRequest : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::Arms _arm_type;
      _arm_type arm;

    GetArmsEnabledRequest():
      arm()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->arm.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->arm.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETARMSENABLED; };
    virtual const char * getMD5() override { return "dcd8da167db8abe1c9f516c1b22a4278"; };

  };

  class GetArmsEnabledResponse : public ros::Msg
  {
    public:
      typedef bool _status_type;
      _status_type status;

    GetArmsEnabledResponse():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return GETARMSENABLED; };
    virtual const char * getMD5() override { return "3a1255d4d998bd4d6585c64639b5ee9a"; };

  };

  class GetArmsEnabled {
    public:
    typedef GetArmsEnabledRequest Request;
    typedef GetArmsEnabledResponse Response;
  };

}
#endif
