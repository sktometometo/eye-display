#ifndef _ROS_jsk_robot_startup_Email_h
#define _ROS_jsk_robot_startup_Email_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_robot_startup/EmailBody.h"

namespace jsk_robot_startup
{

  class Email : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _subject_type;
      _subject_type subject;
      uint32_t body_length;
      typedef jsk_robot_startup::EmailBody _body_type;
      _body_type st_body;
      _body_type * body;
      typedef const char* _sender_address_type;
      _sender_address_type sender_address;
      typedef const char* _receiver_address_type;
      _receiver_address_type receiver_address;
      typedef const char* _smtp_server_type;
      _smtp_server_type smtp_server;
      typedef const char* _smtp_port_type;
      _smtp_port_type smtp_port;
      uint32_t attached_files_length;
      typedef char* _attached_files_type;
      _attached_files_type st_attached_files;
      _attached_files_type * attached_files;

    Email():
      header(),
      subject(""),
      body_length(0), st_body(), body(nullptr),
      sender_address(""),
      receiver_address(""),
      smtp_server(""),
      smtp_port(""),
      attached_files_length(0), st_attached_files(), attached_files(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_subject = strlen(this->subject);
      varToArr(outbuffer + offset, length_subject);
      offset += 4;
      memcpy(outbuffer + offset, this->subject, length_subject);
      offset += length_subject;
      *(outbuffer + offset + 0) = (this->body_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->body_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->body_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->body_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->body_length);
      for( uint32_t i = 0; i < body_length; i++){
      offset += this->body[i].serialize(outbuffer + offset);
      }
      uint32_t length_sender_address = strlen(this->sender_address);
      varToArr(outbuffer + offset, length_sender_address);
      offset += 4;
      memcpy(outbuffer + offset, this->sender_address, length_sender_address);
      offset += length_sender_address;
      uint32_t length_receiver_address = strlen(this->receiver_address);
      varToArr(outbuffer + offset, length_receiver_address);
      offset += 4;
      memcpy(outbuffer + offset, this->receiver_address, length_receiver_address);
      offset += length_receiver_address;
      uint32_t length_smtp_server = strlen(this->smtp_server);
      varToArr(outbuffer + offset, length_smtp_server);
      offset += 4;
      memcpy(outbuffer + offset, this->smtp_server, length_smtp_server);
      offset += length_smtp_server;
      uint32_t length_smtp_port = strlen(this->smtp_port);
      varToArr(outbuffer + offset, length_smtp_port);
      offset += 4;
      memcpy(outbuffer + offset, this->smtp_port, length_smtp_port);
      offset += length_smtp_port;
      *(outbuffer + offset + 0) = (this->attached_files_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->attached_files_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->attached_files_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->attached_files_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->attached_files_length);
      for( uint32_t i = 0; i < attached_files_length; i++){
      uint32_t length_attached_filesi = strlen(this->attached_files[i]);
      varToArr(outbuffer + offset, length_attached_filesi);
      offset += 4;
      memcpy(outbuffer + offset, this->attached_files[i], length_attached_filesi);
      offset += length_attached_filesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_subject;
      arrToVar(length_subject, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subject; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subject-1]=0;
      this->subject = (char *)(inbuffer + offset-1);
      offset += length_subject;
      uint32_t body_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      body_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      body_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      body_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->body_length);
      if(body_lengthT > body_length)
        this->body = (jsk_robot_startup::EmailBody*)realloc(this->body, body_lengthT * sizeof(jsk_robot_startup::EmailBody));
      body_length = body_lengthT;
      for( uint32_t i = 0; i < body_length; i++){
      offset += this->st_body.deserialize(inbuffer + offset);
        memcpy( &(this->body[i]), &(this->st_body), sizeof(jsk_robot_startup::EmailBody));
      }
      uint32_t length_sender_address;
      arrToVar(length_sender_address, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sender_address; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sender_address-1]=0;
      this->sender_address = (char *)(inbuffer + offset-1);
      offset += length_sender_address;
      uint32_t length_receiver_address;
      arrToVar(length_receiver_address, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_receiver_address; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_receiver_address-1]=0;
      this->receiver_address = (char *)(inbuffer + offset-1);
      offset += length_receiver_address;
      uint32_t length_smtp_server;
      arrToVar(length_smtp_server, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_smtp_server; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_smtp_server-1]=0;
      this->smtp_server = (char *)(inbuffer + offset-1);
      offset += length_smtp_server;
      uint32_t length_smtp_port;
      arrToVar(length_smtp_port, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_smtp_port; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_smtp_port-1]=0;
      this->smtp_port = (char *)(inbuffer + offset-1);
      offset += length_smtp_port;
      uint32_t attached_files_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      attached_files_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      attached_files_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      attached_files_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->attached_files_length);
      if(attached_files_lengthT > attached_files_length)
        this->attached_files = (char**)realloc(this->attached_files, attached_files_lengthT * sizeof(char*));
      attached_files_length = attached_files_lengthT;
      for( uint32_t i = 0; i < attached_files_length; i++){
      uint32_t length_st_attached_files;
      arrToVar(length_st_attached_files, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_attached_files; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_attached_files-1]=0;
      this->st_attached_files = (char *)(inbuffer + offset-1);
      offset += length_st_attached_files;
        memcpy( &(this->attached_files[i]), &(this->st_attached_files), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "jsk_robot_startup/Email"; };
    virtual const char * getMD5() override { return "c40c268378da118330071bffb678a351"; };

  };

}
#endif
