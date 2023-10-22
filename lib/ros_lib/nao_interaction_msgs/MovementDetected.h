#ifndef _ROS_nao_interaction_msgs_MovementDetected_h
#define _ROS_nao_interaction_msgs_MovementDetected_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace nao_interaction_msgs
{

  class MovementDetected : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _gravity_center_type;
      _gravity_center_type gravity_center;
      typedef geometry_msgs::Point _mean_velocity_type;
      _mean_velocity_type mean_velocity;
      uint32_t points_poses_length;
      typedef geometry_msgs::Point _points_poses_type;
      _points_poses_type st_points_poses;
      _points_poses_type * points_poses;
      uint32_t points_speeds_length;
      typedef geometry_msgs::Point _points_speeds_type;
      _points_speeds_type st_points_speeds;
      _points_speeds_type * points_speeds;

    MovementDetected():
      header(),
      gravity_center(),
      mean_velocity(),
      points_poses_length(0), st_points_poses(), points_poses(nullptr),
      points_speeds_length(0), st_points_speeds(), points_speeds(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->gravity_center.serialize(outbuffer + offset);
      offset += this->mean_velocity.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->points_poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_poses_length);
      for( uint32_t i = 0; i < points_poses_length; i++){
      offset += this->points_poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->points_speeds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_speeds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_speeds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_speeds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_speeds_length);
      for( uint32_t i = 0; i < points_speeds_length; i++){
      offset += this->points_speeds[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->gravity_center.deserialize(inbuffer + offset);
      offset += this->mean_velocity.deserialize(inbuffer + offset);
      uint32_t points_poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_poses_length);
      if(points_poses_lengthT > points_poses_length)
        this->points_poses = (geometry_msgs::Point*)realloc(this->points_poses, points_poses_lengthT * sizeof(geometry_msgs::Point));
      points_poses_length = points_poses_lengthT;
      for( uint32_t i = 0; i < points_poses_length; i++){
      offset += this->st_points_poses.deserialize(inbuffer + offset);
        memcpy( &(this->points_poses[i]), &(this->st_points_poses), sizeof(geometry_msgs::Point));
      }
      uint32_t points_speeds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_speeds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_speeds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_speeds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_speeds_length);
      if(points_speeds_lengthT > points_speeds_length)
        this->points_speeds = (geometry_msgs::Point*)realloc(this->points_speeds, points_speeds_lengthT * sizeof(geometry_msgs::Point));
      points_speeds_length = points_speeds_lengthT;
      for( uint32_t i = 0; i < points_speeds_length; i++){
      offset += this->st_points_speeds.deserialize(inbuffer + offset);
        memcpy( &(this->points_speeds[i]), &(this->st_points_speeds), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    virtual const char * getType() override { return "nao_interaction_msgs/MovementDetected"; };
    virtual const char * getMD5() override { return "ae24dbf38f441d6f1cae72eb224ecd17"; };

  };

}
#endif
