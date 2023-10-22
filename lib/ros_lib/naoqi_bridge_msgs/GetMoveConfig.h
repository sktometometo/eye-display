#ifndef _ROS_SERVICE_GetMoveConfig_h
#define _ROS_SERVICE_GetMoveConfig_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/MoveConfigNames.h"
#include "naoqi_bridge_msgs/MoveConfig.h"

namespace naoqi_bridge_msgs
{

static const char GETMOVECONFIG[] = "naoqi_bridge_msgs/GetMoveConfig";

  class GetMoveConfigRequest : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::MoveConfigNames _move_config_name_type;
      _move_config_name_type move_config_name;

    GetMoveConfigRequest():
      move_config_name()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->move_config_name.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->move_config_name.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETMOVECONFIG; };
    virtual const char * getMD5() override { return "ff173e809a9d4a8d6d5c5f6f68345e98"; };

  };

  class GetMoveConfigResponse : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::MoveConfig _move_config_type;
      _move_config_type move_config;

    GetMoveConfigResponse():
      move_config()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->move_config.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->move_config.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETMOVECONFIG; };
    virtual const char * getMD5() override { return "bf4f429f83df251a6a9b66ffab503c74"; };

  };

  class GetMoveConfig {
    public:
    typedef GetMoveConfigRequest Request;
    typedef GetMoveConfigResponse Response;
  };

}
#endif
