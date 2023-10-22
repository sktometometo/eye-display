#ifndef _ROS_image_cb_detector_ConfigAction_h
#define _ROS_image_cb_detector_ConfigAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "image_cb_detector/ConfigActionGoal.h"
#include "image_cb_detector/ConfigActionResult.h"
#include "image_cb_detector/ConfigActionFeedback.h"

namespace image_cb_detector
{

  class ConfigAction : public ros::Msg
  {
    public:
      typedef image_cb_detector::ConfigActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef image_cb_detector::ConfigActionResult _action_result_type;
      _action_result_type action_result;
      typedef image_cb_detector::ConfigActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    ConfigAction():
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

    virtual const char * getType() override { return "image_cb_detector/ConfigAction"; };
    virtual const char * getMD5() override { return "1ddd846910edb1716470805de600567f"; };

  };

}
#endif
