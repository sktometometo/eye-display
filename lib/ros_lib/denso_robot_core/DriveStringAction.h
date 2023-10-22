#ifndef _ROS_denso_robot_core_DriveStringAction_h
#define _ROS_denso_robot_core_DriveStringAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "denso_robot_core/DriveStringActionGoal.h"
#include "denso_robot_core/DriveStringActionResult.h"
#include "denso_robot_core/DriveStringActionFeedback.h"

namespace denso_robot_core
{

  class DriveStringAction : public ros::Msg
  {
    public:
      typedef denso_robot_core::DriveStringActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef denso_robot_core::DriveStringActionResult _action_result_type;
      _action_result_type action_result;
      typedef denso_robot_core::DriveStringActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    DriveStringAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "denso_robot_core/DriveStringAction"; };
    virtual const char * getMD5() override { return "446b8ecb6aeefb993c7727d425f91d5d"; };

  };

}
#endif
