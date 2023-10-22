#ifndef _ROS_naoqi_bridge_msgs_FaceDetected_h
#define _ROS_naoqi_bridge_msgs_FaceDetected_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "naoqi_bridge_msgs/FaceInfo.h"
#include "naoqi_bridge_msgs/TimeFilteredRecoInfo.h"
#include "geometry_msgs/Twist.h"

namespace naoqi_bridge_msgs
{

  class FaceDetected : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef naoqi_bridge_msgs::FaceInfo _face_info_type;
      _face_info_type face_info;
      typedef naoqi_bridge_msgs::TimeFilteredRecoInfo _time_filtered_reco_info_type;
      _time_filtered_reco_info_type time_filtered_reco_info;
      typedef geometry_msgs::Twist _camera_pose_in_torso_frame_type;
      _camera_pose_in_torso_frame_type camera_pose_in_torso_frame;
      typedef geometry_msgs::Twist _camera_pose_in_robot_frame_type;
      _camera_pose_in_robot_frame_type camera_pose_in_robot_frame;
      typedef uint8_t _camera_id_type;
      _camera_id_type camera_id;

    FaceDetected():
      header(),
      face_info(),
      time_filtered_reco_info(),
      camera_pose_in_torso_frame(),
      camera_pose_in_robot_frame(),
      camera_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->face_info.serialize(outbuffer + offset);
      offset += this->time_filtered_reco_info.serialize(outbuffer + offset);
      offset += this->camera_pose_in_torso_frame.serialize(outbuffer + offset);
      offset += this->camera_pose_in_robot_frame.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->camera_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->camera_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->face_info.deserialize(inbuffer + offset);
      offset += this->time_filtered_reco_info.deserialize(inbuffer + offset);
      offset += this->camera_pose_in_torso_frame.deserialize(inbuffer + offset);
      offset += this->camera_pose_in_robot_frame.deserialize(inbuffer + offset);
      this->camera_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->camera_id);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/FaceDetected"; };
    virtual const char * getMD5() override { return "12ccceac01f09221ca80a68716954c6c"; };

  };

}
#endif
