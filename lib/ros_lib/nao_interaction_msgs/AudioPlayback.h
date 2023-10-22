#ifndef _ROS_SERVICE_AudioPlayback_h
#define _ROS_SERVICE_AudioPlayback_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace nao_interaction_msgs
{

static const char AUDIOPLAYBACK[] = "nao_interaction_msgs/AudioPlayback";

  class AudioPlaybackRequest : public ros::Msg
  {
    public:
      typedef std_msgs::String _file_path_type;
      _file_path_type file_path;

    AudioPlaybackRequest():
      file_path()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->file_path.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->file_path.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return AUDIOPLAYBACK; };
    virtual const char * getMD5() override { return "0bc1b80cbf52b04c96479758726740cc"; };

  };

  class AudioPlaybackResponse : public ros::Msg
  {
    public:

    AudioPlaybackResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return AUDIOPLAYBACK; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AudioPlayback {
    public:
    typedef AudioPlaybackRequest Request;
    typedef AudioPlaybackResponse Response;
  };

}
#endif
