#ifndef _ROS_SERVICE_AudioRecorder_h
#define _ROS_SERVICE_AudioRecorder_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Char.h"
#include "std_msgs/Int32.h"

namespace nao_interaction_msgs
{

static const char AUDIORECORDER[] = "nao_interaction_msgs/AudioRecorder";

  class AudioRecorderRequest : public ros::Msg
  {
    public:
      typedef std_msgs::String _file_path_type;
      _file_path_type file_path;
      typedef std_msgs::Int32 _secs_type;
      _secs_type secs;
      typedef std_msgs::Char _audio_type_type;
      _audio_type_type audio_type;
      typedef std_msgs::Bool _left_channel_type;
      _left_channel_type left_channel;
      typedef std_msgs::Bool _right_channel_type;
      _right_channel_type right_channel;
      typedef std_msgs::Bool _front_channel_type;
      _front_channel_type front_channel;
      typedef std_msgs::Bool _rear_channel_type;
      _rear_channel_type rear_channel;
      typedef std_msgs::Int32 _samplerate_type;
      _samplerate_type samplerate;

    AudioRecorderRequest():
      file_path(),
      secs(),
      audio_type(),
      left_channel(),
      right_channel(),
      front_channel(),
      rear_channel(),
      samplerate()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->file_path.serialize(outbuffer + offset);
      offset += this->secs.serialize(outbuffer + offset);
      offset += this->audio_type.serialize(outbuffer + offset);
      offset += this->left_channel.serialize(outbuffer + offset);
      offset += this->right_channel.serialize(outbuffer + offset);
      offset += this->front_channel.serialize(outbuffer + offset);
      offset += this->rear_channel.serialize(outbuffer + offset);
      offset += this->samplerate.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->file_path.deserialize(inbuffer + offset);
      offset += this->secs.deserialize(inbuffer + offset);
      offset += this->audio_type.deserialize(inbuffer + offset);
      offset += this->left_channel.deserialize(inbuffer + offset);
      offset += this->right_channel.deserialize(inbuffer + offset);
      offset += this->front_channel.deserialize(inbuffer + offset);
      offset += this->rear_channel.deserialize(inbuffer + offset);
      offset += this->samplerate.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return AUDIORECORDER; };
    virtual const char * getMD5() override { return "b211df69b24b5ed7b95654b151a08b5c"; };

  };

  class AudioRecorderResponse : public ros::Msg
  {
    public:

    AudioRecorderResponse()
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

    virtual const char * getType() override { return AUDIORECORDER; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AudioRecorder {
    public:
    typedef AudioRecorderRequest Request;
    typedef AudioRecorderResponse Response;
  };

}
#endif
