#ifndef _ROS_denso_robot_core_DriveValueActionGoal_h
#define _ROS_denso_robot_core_DriveValueActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "denso_robot_core/DriveValueGoal.h"

namespace denso_robot_core
{

  class DriveValueActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef denso_robot_core::DriveValueGoal _goal_type;
      _goal_type goal;

    DriveValueActionGoal():
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

    virtual const char * getType() override { return "denso_robot_core/DriveValueActionGoal"; };
    virtual const char * getMD5() override { return "8d0f48522e69efbc403bf78d2b18ab7c"; };

  };

}
#endif
