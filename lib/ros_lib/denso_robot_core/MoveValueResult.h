#ifndef _ROS_denso_robot_core_MoveValueResult_h
#define _ROS_denso_robot_core_MoveValueResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace denso_robot_core
{

  class MoveValueResult : public ros::Msg
  {
    public:
      typedef int32_t _HRESULT_type;
      _HRESULT_type HRESULT;

    MoveValueResult():
      HRESULT(0)
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
     return offset;
    }

    virtual const char * getType() override { return "denso_robot_core/MoveValueResult"; };
    virtual const char * getMD5() override { return "0e844160689200392730e0ad31896226"; };

  };

}
#endif
