#ifndef _ROS_SERVICE_TriggerStimulus_h
#define _ROS_SERVICE_TriggerStimulus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace naoqi_bridge_msgs
{

static const char TRIGGERSTIMULUS[] = "naoqi_bridge_msgs/TriggerStimulus";

  class TriggerStimulusRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _position_type;
      _position_type position;

    TriggerStimulusRequest():
      position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TRIGGERSTIMULUS; };
    virtual const char * getMD5() override { return "e7bb0ef028c744b081acdc57743b11d8"; };

  };

  class TriggerStimulusResponse : public ros::Msg
  {
    public:
      typedef int32_t _people_id_type;
      _people_id_type people_id;

    TriggerStimulusResponse():
      people_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_people_id;
      u_people_id.real = this->people_id;
      *(outbuffer + offset + 0) = (u_people_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_people_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_people_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_people_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->people_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_people_id;
      u_people_id.base = 0;
      u_people_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_people_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_people_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_people_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->people_id = u_people_id.real;
      offset += sizeof(this->people_id);
     return offset;
    }

    virtual const char * getType() override { return TRIGGERSTIMULUS; };
    virtual const char * getMD5() override { return "7c9e6726201cbf6822a62cbfd44572e4"; };

  };

  class TriggerStimulus {
    public:
    typedef TriggerStimulusRequest Request;
    typedef TriggerStimulusResponse Response;
  };

}
#endif
