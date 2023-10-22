#ifndef _ROS_SERVICE_GetExternalCollisionProtectionEnabled_h
#define _ROS_SERVICE_GetExternalCollisionProtectionEnabled_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/ExternalCollisionProtectionNames.h"

namespace naoqi_bridge_msgs
{

static const char GETEXTERNALCOLLISIONPROTECTIONENABLED[] = "naoqi_bridge_msgs/GetExternalCollisionProtectionEnabled";

  class GetExternalCollisionProtectionEnabledRequest : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::ExternalCollisionProtectionNames _name_type;
      _name_type name;

    GetExternalCollisionProtectionEnabledRequest():
      name()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->name.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->name.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETEXTERNALCOLLISIONPROTECTIONENABLED; };
    virtual const char * getMD5() override { return "c72501179d4366beacc99364e7f7d578"; };

  };

  class GetExternalCollisionProtectionEnabledResponse : public ros::Msg
  {
    public:
      typedef bool _status_type;
      _status_type status;

    GetExternalCollisionProtectionEnabledResponse():
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

    virtual const char * getType() override { return GETEXTERNALCOLLISIONPROTECTIONENABLED; };
    virtual const char * getMD5() override { return "3a1255d4d998bd4d6585c64639b5ee9a"; };

  };

  class GetExternalCollisionProtectionEnabled {
    public:
    typedef GetExternalCollisionProtectionEnabledRequest Request;
    typedef GetExternalCollisionProtectionEnabledResponse Response;
  };

}
#endif
