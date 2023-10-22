#ifndef _ROS_jsk_recognition_msgs_ExifGPSInfo_h
#define _ROS_jsk_recognition_msgs_ExifGPSInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class ExifGPSInfo : public ros::Msg
  {
    public:
      uint8_t gps_version_id[4];
      typedef const char* _gps_latitude_ref_type;
      _gps_latitude_ref_type gps_latitude_ref;
      float gps_latitude[3];
      typedef const char* _gps_longitude_ref_type;
      _gps_longitude_ref_type gps_longitude_ref;
      float gps_longitude[3];
      typedef uint8_t _gps_altitude_ref_type;
      _gps_altitude_ref_type gps_altitude_ref;
      typedef float _gps_altitude_type;
      _gps_altitude_type gps_altitude;
      typedef float _gps_time_stamp_type;
      _gps_time_stamp_type gps_time_stamp;
      typedef const char* _gps_satellites_type;
      _gps_satellites_type gps_satellites;
      typedef const char* _gps_status_type;
      _gps_status_type gps_status;
      typedef const char* _gps_measure_mode_type;
      _gps_measure_mode_type gps_measure_mode;
      typedef float _gpf_sdop_type;
      _gpf_sdop_type gpf_sdop;
      typedef const char* _gps_speed_ref_type;
      _gps_speed_ref_type gps_speed_ref;
      typedef float _gps_speed_type;
      _gps_speed_type gps_speed;
      typedef const char* _gps_track_ref_type;
      _gps_track_ref_type gps_track_ref;
      typedef float _gps_track_type;
      _gps_track_type gps_track;
      typedef const char* _gps_img_direction_ref_type;
      _gps_img_direction_ref_type gps_img_direction_ref;
      typedef float _gps_img_direction_type;
      _gps_img_direction_type gps_img_direction;
      typedef const char* _gps_map_datum_type;
      _gps_map_datum_type gps_map_datum;
      typedef const char* _gps_dest_latitude_ref_type;
      _gps_dest_latitude_ref_type gps_dest_latitude_ref;
      float gps_dest_latitude[3];
      typedef const char* _gps_dest_longitude_ref_type;
      _gps_dest_longitude_ref_type gps_dest_longitude_ref;
      float gps_dest_longitude[3];
      typedef const char* _gps_dest_bearing_ref_type;
      _gps_dest_bearing_ref_type gps_dest_bearing_ref;
      typedef float _gps_dest_bearing_type;
      _gps_dest_bearing_type gps_dest_bearing;
      typedef const char* _gps_dest_distance_ref_type;
      _gps_dest_distance_ref_type gps_dest_distance_ref;
      typedef float _gps_dest_distance_type;
      _gps_dest_distance_type gps_dest_distance;
      typedef const char* _gps_date_stamp_type;
      _gps_date_stamp_type gps_date_stamp;
      typedef uint16_t _gps_differential_type;
      _gps_differential_type gps_differential;
      typedef float _gps_hpositioning_error_type;
      _gps_hpositioning_error_type gps_hpositioning_error;

    ExifGPSInfo():
      gps_version_id(),
      gps_latitude_ref(""),
      gps_latitude(),
      gps_longitude_ref(""),
      gps_longitude(),
      gps_altitude_ref(0),
      gps_altitude(0),
      gps_time_stamp(0),
      gps_satellites(""),
      gps_status(""),
      gps_measure_mode(""),
      gpf_sdop(0),
      gps_speed_ref(""),
      gps_speed(0),
      gps_track_ref(""),
      gps_track(0),
      gps_img_direction_ref(""),
      gps_img_direction(0),
      gps_map_datum(""),
      gps_dest_latitude_ref(""),
      gps_dest_latitude(),
      gps_dest_longitude_ref(""),
      gps_dest_longitude(),
      gps_dest_bearing_ref(""),
      gps_dest_bearing(0),
      gps_dest_distance_ref(""),
      gps_dest_distance(0),
      gps_date_stamp(""),
      gps_differential(0),
      gps_hpositioning_error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      *(outbuffer + offset + 0) = (this->gps_version_id[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gps_version_id[i]);
      }
      uint32_t length_gps_latitude_ref = strlen(this->gps_latitude_ref);
      varToArr(outbuffer + offset, length_gps_latitude_ref);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_latitude_ref, length_gps_latitude_ref);
      offset += length_gps_latitude_ref;
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_latitude[i]);
      }
      uint32_t length_gps_longitude_ref = strlen(this->gps_longitude_ref);
      varToArr(outbuffer + offset, length_gps_longitude_ref);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_longitude_ref, length_gps_longitude_ref);
      offset += length_gps_longitude_ref;
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_longitude[i]);
      }
      *(outbuffer + offset + 0) = (this->gps_altitude_ref >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gps_altitude_ref);
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_altitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_time_stamp);
      uint32_t length_gps_satellites = strlen(this->gps_satellites);
      varToArr(outbuffer + offset, length_gps_satellites);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_satellites, length_gps_satellites);
      offset += length_gps_satellites;
      uint32_t length_gps_status = strlen(this->gps_status);
      varToArr(outbuffer + offset, length_gps_status);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_status, length_gps_status);
      offset += length_gps_status;
      uint32_t length_gps_measure_mode = strlen(this->gps_measure_mode);
      varToArr(outbuffer + offset, length_gps_measure_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_measure_mode, length_gps_measure_mode);
      offset += length_gps_measure_mode;
      offset += serializeAvrFloat64(outbuffer + offset, this->gpf_sdop);
      uint32_t length_gps_speed_ref = strlen(this->gps_speed_ref);
      varToArr(outbuffer + offset, length_gps_speed_ref);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_speed_ref, length_gps_speed_ref);
      offset += length_gps_speed_ref;
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_speed);
      uint32_t length_gps_track_ref = strlen(this->gps_track_ref);
      varToArr(outbuffer + offset, length_gps_track_ref);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_track_ref, length_gps_track_ref);
      offset += length_gps_track_ref;
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_track);
      uint32_t length_gps_img_direction_ref = strlen(this->gps_img_direction_ref);
      varToArr(outbuffer + offset, length_gps_img_direction_ref);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_img_direction_ref, length_gps_img_direction_ref);
      offset += length_gps_img_direction_ref;
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_img_direction);
      uint32_t length_gps_map_datum = strlen(this->gps_map_datum);
      varToArr(outbuffer + offset, length_gps_map_datum);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_map_datum, length_gps_map_datum);
      offset += length_gps_map_datum;
      uint32_t length_gps_dest_latitude_ref = strlen(this->gps_dest_latitude_ref);
      varToArr(outbuffer + offset, length_gps_dest_latitude_ref);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_dest_latitude_ref, length_gps_dest_latitude_ref);
      offset += length_gps_dest_latitude_ref;
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_dest_latitude[i]);
      }
      uint32_t length_gps_dest_longitude_ref = strlen(this->gps_dest_longitude_ref);
      varToArr(outbuffer + offset, length_gps_dest_longitude_ref);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_dest_longitude_ref, length_gps_dest_longitude_ref);
      offset += length_gps_dest_longitude_ref;
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_dest_longitude[i]);
      }
      uint32_t length_gps_dest_bearing_ref = strlen(this->gps_dest_bearing_ref);
      varToArr(outbuffer + offset, length_gps_dest_bearing_ref);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_dest_bearing_ref, length_gps_dest_bearing_ref);
      offset += length_gps_dest_bearing_ref;
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_dest_bearing);
      uint32_t length_gps_dest_distance_ref = strlen(this->gps_dest_distance_ref);
      varToArr(outbuffer + offset, length_gps_dest_distance_ref);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_dest_distance_ref, length_gps_dest_distance_ref);
      offset += length_gps_dest_distance_ref;
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_dest_distance);
      uint32_t length_gps_date_stamp = strlen(this->gps_date_stamp);
      varToArr(outbuffer + offset, length_gps_date_stamp);
      offset += 4;
      memcpy(outbuffer + offset, this->gps_date_stamp, length_gps_date_stamp);
      offset += length_gps_date_stamp;
      *(outbuffer + offset + 0) = (this->gps_differential >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gps_differential >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gps_differential);
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_hpositioning_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      this->gps_version_id[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gps_version_id[i]);
      }
      uint32_t length_gps_latitude_ref;
      arrToVar(length_gps_latitude_ref, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_latitude_ref; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_latitude_ref-1]=0;
      this->gps_latitude_ref = (char *)(inbuffer + offset-1);
      offset += length_gps_latitude_ref;
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_latitude[i]));
      }
      uint32_t length_gps_longitude_ref;
      arrToVar(length_gps_longitude_ref, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_longitude_ref; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_longitude_ref-1]=0;
      this->gps_longitude_ref = (char *)(inbuffer + offset-1);
      offset += length_gps_longitude_ref;
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_longitude[i]));
      }
      this->gps_altitude_ref =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gps_altitude_ref);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_altitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_time_stamp));
      uint32_t length_gps_satellites;
      arrToVar(length_gps_satellites, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_satellites; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_satellites-1]=0;
      this->gps_satellites = (char *)(inbuffer + offset-1);
      offset += length_gps_satellites;
      uint32_t length_gps_status;
      arrToVar(length_gps_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_status-1]=0;
      this->gps_status = (char *)(inbuffer + offset-1);
      offset += length_gps_status;
      uint32_t length_gps_measure_mode;
      arrToVar(length_gps_measure_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_measure_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_measure_mode-1]=0;
      this->gps_measure_mode = (char *)(inbuffer + offset-1);
      offset += length_gps_measure_mode;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gpf_sdop));
      uint32_t length_gps_speed_ref;
      arrToVar(length_gps_speed_ref, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_speed_ref; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_speed_ref-1]=0;
      this->gps_speed_ref = (char *)(inbuffer + offset-1);
      offset += length_gps_speed_ref;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_speed));
      uint32_t length_gps_track_ref;
      arrToVar(length_gps_track_ref, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_track_ref; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_track_ref-1]=0;
      this->gps_track_ref = (char *)(inbuffer + offset-1);
      offset += length_gps_track_ref;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_track));
      uint32_t length_gps_img_direction_ref;
      arrToVar(length_gps_img_direction_ref, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_img_direction_ref; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_img_direction_ref-1]=0;
      this->gps_img_direction_ref = (char *)(inbuffer + offset-1);
      offset += length_gps_img_direction_ref;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_img_direction));
      uint32_t length_gps_map_datum;
      arrToVar(length_gps_map_datum, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_map_datum; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_map_datum-1]=0;
      this->gps_map_datum = (char *)(inbuffer + offset-1);
      offset += length_gps_map_datum;
      uint32_t length_gps_dest_latitude_ref;
      arrToVar(length_gps_dest_latitude_ref, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_dest_latitude_ref; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_dest_latitude_ref-1]=0;
      this->gps_dest_latitude_ref = (char *)(inbuffer + offset-1);
      offset += length_gps_dest_latitude_ref;
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_dest_latitude[i]));
      }
      uint32_t length_gps_dest_longitude_ref;
      arrToVar(length_gps_dest_longitude_ref, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_dest_longitude_ref; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_dest_longitude_ref-1]=0;
      this->gps_dest_longitude_ref = (char *)(inbuffer + offset-1);
      offset += length_gps_dest_longitude_ref;
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_dest_longitude[i]));
      }
      uint32_t length_gps_dest_bearing_ref;
      arrToVar(length_gps_dest_bearing_ref, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_dest_bearing_ref; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_dest_bearing_ref-1]=0;
      this->gps_dest_bearing_ref = (char *)(inbuffer + offset-1);
      offset += length_gps_dest_bearing_ref;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_dest_bearing));
      uint32_t length_gps_dest_distance_ref;
      arrToVar(length_gps_dest_distance_ref, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_dest_distance_ref; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_dest_distance_ref-1]=0;
      this->gps_dest_distance_ref = (char *)(inbuffer + offset-1);
      offset += length_gps_dest_distance_ref;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_dest_distance));
      uint32_t length_gps_date_stamp;
      arrToVar(length_gps_date_stamp, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gps_date_stamp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gps_date_stamp-1]=0;
      this->gps_date_stamp = (char *)(inbuffer + offset-1);
      offset += length_gps_date_stamp;
      this->gps_differential =  ((uint16_t) (*(inbuffer + offset)));
      this->gps_differential |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->gps_differential);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_hpositioning_error));
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/ExifGPSInfo"; };
    virtual const char * getMD5() override { return "4d78b4fbebd5b498dabfce0a45f72762"; };

  };

}
#endif
