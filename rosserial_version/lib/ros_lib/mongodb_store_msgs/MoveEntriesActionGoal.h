#ifndef _ROS_mongodb_store_msgs_MoveEntriesActionGoal_h
#define _ROS_mongodb_store_msgs_MoveEntriesActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "mongodb_store_msgs/MoveEntriesGoal.h"

namespace mongodb_store_msgs
{

  class MoveEntriesActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef mongodb_store_msgs::MoveEntriesGoal _goal_type;
      _goal_type goal;

    MoveEntriesActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "mongodb_store_msgs/MoveEntriesActionGoal"; };
    virtual const char * getMD5() override { return "8cd0c3d38e1c3ed7bce235f7ebbaf759"; };

  };

}
#endif
