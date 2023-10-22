#ifndef _ROS_jsk_robot_startup_EmailBody_h
#define _ROS_jsk_robot_startup_EmailBody_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_robot_startup
{

  class EmailBody : public ros::Msg
  {
    public:
      typedef const char* _type_type;
      _type_type type;
      typedef const char* _message_type;
      _message_type message;
      typedef const char* _file_path_type;
      _file_path_type file_path;
      typedef const char* _img_data_type;
      _img_data_type img_data;
      typedef uint8_t _img_size_type;
      _img_size_type img_size;

    EmailBody():
      type(""),
      message(""),
      file_path(""),
      img_data(""),
      img_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      uint32_t length_file_path = strlen(this->file_path);
      varToArr(outbuffer + offset, length_file_path);
      offset += 4;
      memcpy(outbuffer + offset, this->file_path, length_file_path);
      offset += length_file_path;
      uint32_t length_img_data = strlen(this->img_data);
      varToArr(outbuffer + offset, length_img_data);
      offset += 4;
      memcpy(outbuffer + offset, this->img_data, length_img_data);
      offset += length_img_data;
      *(outbuffer + offset + 0) = (this->img_size >> (8 * 0)) & 0xFF;
      offset += sizeof(this->img_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      uint32_t length_file_path;
      arrToVar(length_file_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_path-1]=0;
      this->file_path = (char *)(inbuffer + offset-1);
      offset += length_file_path;
      uint32_t length_img_data;
      arrToVar(length_img_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_img_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_img_data-1]=0;
      this->img_data = (char *)(inbuffer + offset-1);
      offset += length_img_data;
      this->img_size =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->img_size);
     return offset;
    }

    virtual const char * getType() override { return "jsk_robot_startup/EmailBody"; };
    virtual const char * getMD5() override { return "ab059c8bc6829404529235fa1e050e10"; };

  };

}
#endif
