#ifndef _ROS_jsk_recognition_msgs_VQAResult_h
#define _ROS_jsk_recognition_msgs_VQAResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/QuestionAndAnswerText.h"

namespace jsk_recognition_msgs
{

  class VQAResult : public ros::Msg
  {
    public:
      uint32_t result_length;
      typedef jsk_recognition_msgs::QuestionAndAnswerText _result_type;
      _result_type st_result;
      _result_type * result;

    VQAResult():
      result_length(0), st_result(), result(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->result_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->result_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->result_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->result_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->result_length);
      for( uint32_t i = 0; i < result_length; i++){
      offset += this->result[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t result_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      result_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      result_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      result_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->result_length);
      if(result_lengthT > result_length)
        this->result = (jsk_recognition_msgs::QuestionAndAnswerText*)realloc(this->result, result_lengthT * sizeof(jsk_recognition_msgs::QuestionAndAnswerText));
      result_length = result_lengthT;
      for( uint32_t i = 0; i < result_length; i++){
      offset += this->st_result.deserialize(inbuffer + offset);
        memcpy( &(this->result[i]), &(this->st_result), sizeof(jsk_recognition_msgs::QuestionAndAnswerText));
      }
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/VQAResult"; };
    virtual const char * getMD5() override { return "8899eb6036ebfcfe80ce4291b9c06ac0"; };

  };

}
#endif
