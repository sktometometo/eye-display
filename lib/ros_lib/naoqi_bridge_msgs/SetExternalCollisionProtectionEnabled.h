#ifndef _ROS_SERVICE_SetExternalCollisionProtectionEnabled_h
#define _ROS_SERVICE_SetExternalCollisionProtectionEnabled_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/ExternalCollisionProtectionNames.h"

namespace naoqi_bridge_msgs
{

static const char SETEXTERNALCOLLISIONPROTECTIONENABLED[] = "naoqi_bridge_msgs/SetExternalCollisionProtectionEnabled";

  class SetExternalCollisionProtectionEnabledRequest : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::ExternalCollisionProtectionNames _name_type;
      _name_type name;
      typedef bool _status_type;
      _status_type status;

    SetExternalCollisionProtectionEnabledRequest():
      name(),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->name.serialize(outbuffer + offset);
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
      offset += this->name.deserialize(inbuffer + offset);
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

    virtual const char * getType() override { return SETEXTERNALCOLLISIONPROTECTIONENABLED; };
    virtual const char * getMD5() override { return "d76dfb063b264cea3bf6dc9d994cebb5"; };

  };

  class SetExternalCollisionProtectionEnabledResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetExternalCollisionProtectionEnabledResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return SETEXTERNALCOLLISIONPROTECTIONENABLED; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetExternalCollisionProtectionEnabled {
    public:
    typedef SetExternalCollisionProtectionEnabledRequest Request;
    typedef SetExternalCollisionProtectionEnabledResponse Response;
  };

}
#endif
