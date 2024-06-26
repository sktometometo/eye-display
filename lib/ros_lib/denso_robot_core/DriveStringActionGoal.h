#ifndef _ROS_denso_robot_core_DriveStringActionGoal_h
#define _ROS_denso_robot_core_DriveStringActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "denso_robot_core/DriveStringGoal.h"

namespace denso_robot_core
{

  class DriveStringActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef denso_robot_core::DriveStringGoal _goal_type;
      _goal_type goal;

    DriveStringActionGoal():
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

    virtual const char * getType() override { return "denso_robot_core/DriveStringActionGoal"; };
    virtual const char * getMD5() override { return "774ce965a05a8f6968acfa6cb14b995c"; };

  };

}
#endif
