#ifndef _ROS_naoqi_bridge_msgs_PeopleDetected_h
#define _ROS_naoqi_bridge_msgs_PeopleDetected_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace naoqi_bridge_msgs
{

  class PeopleDetected : public ros::Msg
  {
    public:
      typedef int64_t _people_id_type;
      _people_id_type people_id;
      typedef float _distance_type;
      _distance_type distance;
      typedef float _yaw_type;
      _yaw_type yaw;
      typedef float _pitch_type;
      _pitch_type pitch;
      typedef int64_t _camera_id_type;
      _camera_id_type camera_id;
      typedef geometry_msgs::Twist _camera_pose_in_torso_frame_type;
      _camera_pose_in_torso_frame_type camera_pose_in_torso_frame;
      typedef geometry_msgs::Twist _camera_pose_in_robot_frame_type;
      _camera_pose_in_robot_frame_type camera_pose_in_robot_frame;
      typedef geometry_msgs::Point _head_position_in_torso_frame_type;
      _head_position_in_torso_frame_type head_position_in_torso_frame;
      typedef geometry_msgs::Point _head_position_in_robot_frame_type;
      _head_position_in_robot_frame_type head_position_in_robot_frame;
      typedef geometry_msgs::Point _head_position_in_world_frame_type;
      _head_position_in_world_frame_type head_position_in_world_frame;
      typedef bool _is_face_detected_type;
      _is_face_detected_type is_face_detected;
      typedef bool _is_visible_type;
      _is_visible_type is_visible;
      typedef int64_t _not_seen_since_type;
      _not_seen_since_type not_seen_since;
      typedef int64_t _present_since_type;
      _present_since_type present_since;
      typedef float _real_height_type;
      _real_height_type real_height;
      typedef const char* _shirt_color_type;
      _shirt_color_type shirt_color;
      typedef geometry_msgs::Vector3 _hsv_type;
      _hsv_type hsv;

    PeopleDetected():
      people_id(0),
      distance(0),
      yaw(0),
      pitch(0),
      camera_id(0),
      camera_pose_in_torso_frame(),
      camera_pose_in_robot_frame(),
      head_position_in_torso_frame(),
      head_position_in_robot_frame(),
      head_position_in_world_frame(),
      is_face_detected(0),
      is_visible(0),
      not_seen_since(0),
      present_since(0),
      real_height(0),
      shirt_color(""),
      hsv()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_people_id;
      u_people_id.real = this->people_id;
      *(outbuffer + offset + 0) = (u_people_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_people_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_people_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_people_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_people_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_people_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_people_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_people_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->people_id);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->pitch);
      union {
        int64_t real;
        uint64_t base;
      } u_camera_id;
      u_camera_id.real = this->camera_id;
      *(outbuffer + offset + 0) = (u_camera_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_camera_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_camera_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_camera_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_camera_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_camera_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_camera_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_camera_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->camera_id);
      offset += this->camera_pose_in_torso_frame.serialize(outbuffer + offset);
      offset += this->camera_pose_in_robot_frame.serialize(outbuffer + offset);
      offset += this->head_position_in_torso_frame.serialize(outbuffer + offset);
      offset += this->head_position_in_robot_frame.serialize(outbuffer + offset);
      offset += this->head_position_in_world_frame.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_face_detected;
      u_is_face_detected.real = this->is_face_detected;
      *(outbuffer + offset + 0) = (u_is_face_detected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_face_detected);
      union {
        bool real;
        uint8_t base;
      } u_is_visible;
      u_is_visible.real = this->is_visible;
      *(outbuffer + offset + 0) = (u_is_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_visible);
      union {
        int64_t real;
        uint64_t base;
      } u_not_seen_since;
      u_not_seen_since.real = this->not_seen_since;
      *(outbuffer + offset + 0) = (u_not_seen_since.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_not_seen_since.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_not_seen_since.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_not_seen_since.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_not_seen_since.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_not_seen_since.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_not_seen_since.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_not_seen_since.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->not_seen_since);
      union {
        int64_t real;
        uint64_t base;
      } u_present_since;
      u_present_since.real = this->present_since;
      *(outbuffer + offset + 0) = (u_present_since.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_present_since.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_present_since.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_present_since.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_present_since.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_present_since.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_present_since.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_present_since.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->present_since);
      offset += serializeAvrFloat64(outbuffer + offset, this->real_height);
      uint32_t length_shirt_color = strlen(this->shirt_color);
      varToArr(outbuffer + offset, length_shirt_color);
      offset += 4;
      memcpy(outbuffer + offset, this->shirt_color, length_shirt_color);
      offset += length_shirt_color;
      offset += this->hsv.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_people_id;
      u_people_id.base = 0;
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->people_id = u_people_id.real;
      offset += sizeof(this->people_id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pitch));
      union {
        int64_t real;
        uint64_t base;
      } u_camera_id;
      u_camera_id.base = 0;
      u_camera_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_camera_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_camera_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_camera_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_camera_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_camera_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_camera_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_camera_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->camera_id = u_camera_id.real;
      offset += sizeof(this->camera_id);
      offset += this->camera_pose_in_torso_frame.deserialize(inbuffer + offset);
      offset += this->camera_pose_in_robot_frame.deserialize(inbuffer + offset);
      offset += this->head_position_in_torso_frame.deserialize(inbuffer + offset);
      offset += this->head_position_in_robot_frame.deserialize(inbuffer + offset);
      offset += this->head_position_in_world_frame.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_face_detected;
      u_is_face_detected.base = 0;
      u_is_face_detected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_face_detected = u_is_face_detected.real;
      offset += sizeof(this->is_face_detected);
      union {
        bool real;
        uint8_t base;
      } u_is_visible;
      u_is_visible.base = 0;
      u_is_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_visible = u_is_visible.real;
      offset += sizeof(this->is_visible);
      union {
        int64_t real;
        uint64_t base;
      } u_not_seen_since;
      u_not_seen_since.base = 0;
      u_not_seen_since.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_not_seen_since.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_not_seen_since.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_not_seen_since.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_not_seen_since.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_not_seen_since.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_not_seen_since.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_not_seen_since.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->not_seen_since = u_not_seen_since.real;
      offset += sizeof(this->not_seen_since);
      union {
        int64_t real;
        uint64_t base;
      } u_present_since;
      u_present_since.base = 0;
      u_present_since.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_present_since.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_present_since.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_present_since.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_present_since.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_present_since.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_present_since.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_present_since.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->present_since = u_present_since.real;
      offset += sizeof(this->present_since);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->real_height));
      uint32_t length_shirt_color;
      arrToVar(length_shirt_color, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_shirt_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_shirt_color-1]=0;
      this->shirt_color = (char *)(inbuffer + offset-1);
      offset += length_shirt_color;
      offset += this->hsv.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/PeopleDetected"; };
    virtual const char * getMD5() override { return "2e0e481ae3b815b73bc001a1ee5094d9"; };

  };

}
#endif
