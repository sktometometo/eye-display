#ifndef _ROS_SERVICE_SetStimulusDetectionEnabled_h
#define _ROS_SERVICE_SetStimulusDetectionEnabled_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

static const char SETSTIMULUSDETECTIONENABLED[] = "naoqi_bridge_msgs/SetStimulusDetectionEnabled";

  class SetStimulusDetectionEnabledRequest : public ros::Msg
  {
    public:
      typedef const char* _data_type;
      _data_type data;
      typedef bool _status_type;
      _status_type status;

    SetStimulusDetectionEnabledRequest():
      data(""),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_data = strlen(this->data);
      varToArr(outbuffer + offset, length_data);
      offset += 4;
      memcpy(outbuffer + offset, this->data, length_data);
      offset += length_data;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_data;
      arrToVar(length_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_data-1]=0;
      this->data = (char *)(inbuffer + offset-1);
      offset += length_data;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return SETSTIMULUSDETECTIONENABLED; };
    virtual const char * getMD5() override { return "22c8c7d3bde9abf68f09df7d02fd2240"; };

  };

  class SetStimulusDetectionEnabledResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetStimulusDetectionEnabledResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return SETSTIMULUSDETECTIONENABLED; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetStimulusDetectionEnabled {
    public:
    typedef SetStimulusDetectionEnabledRequest Request;
    typedef SetStimulusDetectionEnabledResponse Response;
  };

}
#endif
