#ifndef _ROS_SERVICE_LearnFace_h
#define _ROS_SERVICE_LearnFace_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

namespace nao_interaction_msgs
{

static const char LEARNFACE[] = "nao_interaction_msgs/LearnFace";

  class LearnFaceRequest : public ros::Msg
  {
    public:
      typedef std_msgs::String _name_type;
      _name_type name;

    LearnFaceRequest():
      name()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->name.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->name.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return LEARNFACE; };
    virtual const char * getMD5() override { return "0fce35bd9f5b27a63eb9b0e831759a0b"; };

  };

  class LearnFaceResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Bool _result_type;
      _result_type result;

    LearnFaceResponse():
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return LEARNFACE; };
    virtual const char * getMD5() override { return "c2420602a83d8ccc0f3664e0daafab6c"; };

  };

  class LearnFace {
    public:
    typedef LearnFaceRequest Request;
    typedef LearnFaceResponse Response;
  };

}
#endif
