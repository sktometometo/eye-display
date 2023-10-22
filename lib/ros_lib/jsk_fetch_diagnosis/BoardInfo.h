#ifndef _ROS_jsk_fetch_diagnosis_BoardInfo_h
#define _ROS_jsk_fetch_diagnosis_BoardInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_fetch_diagnosis
{

  class BoardInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _board_id_type;
      _board_id_type board_id;
      typedef const char* _board_info_type;
      _board_info_type board_info;

    BoardInfo():
      header(),
      board_id(0),
      board_info("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_board_id;
      u_board_id.real = this->board_id;
      *(outbuffer + offset + 0) = (u_board_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_board_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_board_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_board_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->board_id);
      uint32_t length_board_info = strlen(this->board_info);
      varToArr(outbuffer + offset, length_board_info);
      offset += 4;
      memcpy(outbuffer + offset, this->board_info, length_board_info);
      offset += length_board_info;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_board_id;
      u_board_id.base = 0;
      u_board_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_board_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_board_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_board_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->board_id = u_board_id.real;
      offset += sizeof(this->board_id);
      uint32_t length_board_info;
      arrToVar(length_board_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_board_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_board_info-1]=0;
      this->board_info = (char *)(inbuffer + offset-1);
      offset += length_board_info;
     return offset;
    }

    virtual const char * getType() override { return "jsk_fetch_diagnosis/BoardInfo"; };
    virtual const char * getMD5() override { return "91e23add1e30168e0512fbd4b94f5003"; };

  };

}
#endif
