#ifndef _ROS_mongodb_store_msgs_MoveEntriesActionResult_h
#define _ROS_mongodb_store_msgs_MoveEntriesActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "mongodb_store_msgs/MoveEntriesResult.h"

namespace mongodb_store_msgs
{

  class MoveEntriesActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef mongodb_store_msgs::MoveEntriesResult _result_type;
      _result_type result;

    MoveEntriesActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "mongodb_store_msgs/MoveEntriesActionResult"; };
    virtual const char * getMD5() override { return "1eb06eeff08fa7ea874431638cb52332"; };

  };

}
#endif
