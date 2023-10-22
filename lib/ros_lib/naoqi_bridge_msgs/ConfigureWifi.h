#ifndef _ROS_SERVICE_ConfigureWifi_h
#define _ROS_SERVICE_ConfigureWifi_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

static const char CONFIGUREWIFI[] = "naoqi_bridge_msgs/ConfigureWifi";

  class ConfigureWifiRequest : public ros::Msg
  {
    public:
      typedef const char* _security_type;
      _security_type security;
      typedef const char* _ssid_type;
      _ssid_type ssid;
      typedef const char* _key_type;
      _key_type key;

    ConfigureWifiRequest():
      security(""),
      ssid(""),
      key("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_security = strlen(this->security);
      varToArr(outbuffer + offset, length_security);
      offset += 4;
      memcpy(outbuffer + offset, this->security, length_security);
      offset += length_security;
      uint32_t length_ssid = strlen(this->ssid);
      varToArr(outbuffer + offset, length_ssid);
      offset += 4;
      memcpy(outbuffer + offset, this->ssid, length_ssid);
      offset += length_ssid;
      uint32_t length_key = strlen(this->key);
      varToArr(outbuffer + offset, length_key);
      offset += 4;
      memcpy(outbuffer + offset, this->key, length_key);
      offset += length_key;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_security;
      arrToVar(length_security, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_security; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_security-1]=0;
      this->security = (char *)(inbuffer + offset-1);
      offset += length_security;
      uint32_t length_ssid;
      arrToVar(length_ssid, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ssid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ssid-1]=0;
      this->ssid = (char *)(inbuffer + offset-1);
      offset += length_ssid;
      uint32_t length_key;
      arrToVar(length_key, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_key; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_key-1]=0;
      this->key = (char *)(inbuffer + offset-1);
      offset += length_key;
     return offset;
    }

    virtual const char * getType() override { return CONFIGUREWIFI; };
    virtual const char * getMD5() override { return "07ddeff42cb40a360e5789a4f4dd330a"; };

  };

  class ConfigureWifiResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ConfigureWifiResponse():
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

    virtual const char * getType() override { return CONFIGUREWIFI; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ConfigureWifi {
    public:
    typedef ConfigureWifiRequest Request;
    typedef ConfigureWifiResponse Response;
  };

}
#endif
