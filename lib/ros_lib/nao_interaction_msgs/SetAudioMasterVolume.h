#ifndef _ROS_SERVICE_SetAudioMasterVolume_h
#define _ROS_SERVICE_SetAudioMasterVolume_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Int32.h"

namespace nao_interaction_msgs
{

static const char SETAUDIOMASTERVOLUME[] = "nao_interaction_msgs/SetAudioMasterVolume";

  class SetAudioMasterVolumeRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Int32 _master_volume_type;
      _master_volume_type master_volume;

    SetAudioMasterVolumeRequest():
      master_volume()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->master_volume.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->master_volume.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETAUDIOMASTERVOLUME; };
    virtual const char * getMD5() override { return "6a2d45c5fcf9fd89299667da81b32d64"; };

  };

  class SetAudioMasterVolumeResponse : public ros::Msg
  {
    public:

    SetAudioMasterVolumeResponse()
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

    virtual const char * getType() override { return SETAUDIOMASTERVOLUME; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetAudioMasterVolume {
    public:
    typedef SetAudioMasterVolumeRequest Request;
    typedef SetAudioMasterVolumeResponse Response;
  };

}
#endif
