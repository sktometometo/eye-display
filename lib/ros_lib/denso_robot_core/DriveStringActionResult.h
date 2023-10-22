#ifndef _ROS_denso_robot_core_DriveStringActionResult_h
#define _ROS_denso_robot_core_DriveStringActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "denso_robot_core/DriveStringResult.h"

namespace denso_robot_core
{

  class DriveStringActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef denso_robot_core::DriveStringResult _result_type;
      _result_type result;

    DriveStringActionResult():
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

    virtual const char * getType() override { return "denso_robot_core/DriveStringActionResult"; };
    virtual const char * getMD5() override { return "5b70bf9b91fce5c335e4ebf1e187f32c"; };

  };

}
#endif
