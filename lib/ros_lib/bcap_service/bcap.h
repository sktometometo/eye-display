#ifndef _ROS_SERVICE_bcap_h
#define _ROS_SERVICE_bcap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "bcap_service/variant.h"

namespace bcap_service
{

static const char BCAP[] = "bcap_service/bcap";

  class bcapRequest : public ros::Msg
  {
    public:
      typedef int32_t _func_id_type;
      _func_id_type func_id;
      uint32_t vntArgs_length;
      typedef bcap_service::variant _vntArgs_type;
      _vntArgs_type st_vntArgs;
      _vntArgs_type * vntArgs;

    bcapRequest():
      func_id(0),
      vntArgs_length(0), st_vntArgs(), vntArgs(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_func_id;
      u_func_id.real = this->func_id;
      *(outbuffer + offset + 0) = (u_func_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_func_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_func_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_func_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->func_id);
      *(outbuffer + offset + 0) = (this->vntArgs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vntArgs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vntArgs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vntArgs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vntArgs_length);
      for( uint32_t i = 0; i < vntArgs_length; i++){
      offset += this->vntArgs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_func_id;
      u_func_id.base = 0;
      u_func_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_func_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_func_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_func_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->func_id = u_func_id.real;
      offset += sizeof(this->func_id);
      uint32_t vntArgs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vntArgs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vntArgs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vntArgs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vntArgs_length);
      if(vntArgs_lengthT > vntArgs_length)
        this->vntArgs = (bcap_service::variant*)realloc(this->vntArgs, vntArgs_lengthT * sizeof(bcap_service::variant));
      vntArgs_length = vntArgs_lengthT;
      for( uint32_t i = 0; i < vntArgs_length; i++){
      offset += this->st_vntArgs.deserialize(inbuffer + offset);
        memcpy( &(this->vntArgs[i]), &(this->st_vntArgs), sizeof(bcap_service::variant));
      }
     return offset;
    }

    virtual const char * getType() override { return BCAP; };
    virtual const char * getMD5() override { return "e2e62a99900f0dacb6b7c7114cde3983"; };

  };

  class bcapResponse : public ros::Msg
  {
    public:
      typedef int32_t _HRESULT_type;
      _HRESULT_type HRESULT;
      typedef bcap_service::variant _vntRet_type;
      _vntRet_type vntRet;

    bcapResponse():
      HRESULT(0),
      vntRet()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_HRESULT;
      u_HRESULT.real = this->HRESULT;
      *(outbuffer + offset + 0) = (u_HRESULT.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_HRESULT.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_HRESULT.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_HRESULT.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->HRESULT);
      offset += this->vntRet.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_HRESULT;
      u_HRESULT.base = 0;
      u_HRESULT.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_HRESULT.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_HRESULT.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_HRESULT.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->HRESULT = u_HRESULT.real;
      offset += sizeof(this->HRESULT);
      offset += this->vntRet.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return BCAP; };
    virtual const char * getMD5() override { return "71670d22c1b3a79073449b5cc4047e38"; };

  };

  class bcap {
    public:
    typedef bcapRequest Request;
    typedef bcapResponse Response;
  };

}
#endif
