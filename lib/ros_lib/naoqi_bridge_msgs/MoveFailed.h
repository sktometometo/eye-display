#ifndef _ROS_naoqi_bridge_msgs_MoveFailed_h
#define _ROS_naoqi_bridge_msgs_MoveFailed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace naoqi_bridge_msgs
{

  class MoveFailed : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _cause_type;
      _cause_type cause;
      typedef int32_t _status_type;
      _status_type status;
      typedef geometry_msgs::Point _position_type;
      _position_type position;

    MoveFailed():
      header(),
      cause(""),
      status(0),
      position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_cause = strlen(this->cause);
      varToArr(outbuffer + offset, length_cause);
      offset += 4;
      memcpy(outbuffer + offset, this->cause, length_cause);
      offset += length_cause;
      union {
        int32_t real;
        uint32_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_status.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_status.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_status.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status);
      offset += this->position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_cause;
      arrToVar(length_cause, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_cause; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_cause-1]=0;
      this->cause = (char *)(inbuffer + offset-1);
      offset += length_cause;
      union {
        int32_t real;
        uint32_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->status = u_status.real;
      offset += sizeof(this->status);
      offset += this->position.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/MoveFailed"; };
    virtual const char * getMD5() override { return "54157c1351bf67b9c48b4d370671d597"; };

  };

}
#endif
