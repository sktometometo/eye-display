#ifndef _ROS_jsk_recognition_msgs_QuestionAndAnswerText_h
#define _ROS_jsk_recognition_msgs_QuestionAndAnswerText_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class QuestionAndAnswerText : public ros::Msg
  {
    public:
      typedef const char* _question_type;
      _question_type question;
      typedef const char* _answer_type;
      _answer_type answer;

    QuestionAndAnswerText():
      question(""),
      answer("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_question = strlen(this->question);
      varToArr(outbuffer + offset, length_question);
      offset += 4;
      memcpy(outbuffer + offset, this->question, length_question);
      offset += length_question;
      uint32_t length_answer = strlen(this->answer);
      varToArr(outbuffer + offset, length_answer);
      offset += 4;
      memcpy(outbuffer + offset, this->answer, length_answer);
      offset += length_answer;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_question;
      arrToVar(length_question, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_question; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_question-1]=0;
      this->question = (char *)(inbuffer + offset-1);
      offset += length_question;
      uint32_t length_answer;
      arrToVar(length_answer, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_answer; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_answer-1]=0;
      this->answer = (char *)(inbuffer + offset-1);
      offset += length_answer;
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/QuestionAndAnswerText"; };
    virtual const char * getMD5() override { return "a27d8629aeefd2b315942fe4a74ab143"; };

  };

}
#endif
