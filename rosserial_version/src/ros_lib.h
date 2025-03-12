#pragma once

#include <ArduinoJson.h>
#include <iterator>
#include <sstream>

extern const int image_width;
extern const int image_height;

extern EyeManager eye;
extern std::map<std::string, EyeAsset> eye_asset_map;
extern std::string current_eye_status;


#include "node_handle_ex.h"  // #include "ros/node_handle.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/String.h"

void callback_look_at(const geometry_msgs::Point &msg);
void callback_emotion(const std_msgs::String &msg);

ros::NodeHandleEx<ArduinoHardware> nh;
ros::Subscriber<geometry_msgs::Point> sub_point("~look_at", &callback_look_at);
ros::Subscriber<std_msgs::String> sub_eye_status("~eye_status", &callback_emotion);

void callback_look_at(const geometry_msgs::Point &msg)
{
  eye.set_gaze_direction((float)msg.x, (float)msg.y);
}

void callback_emotion(const std_msgs::String &msg)
{
  int i = 0;
  current_eye_status = std::string(msg.data);
  auto it = eye_asset_map.find(current_eye_status);
  if (it != eye_asset_map.end()) {
      nh.loginfo("Status updated: %s", msg.data);
      eye.set_emotion(it->second);
  } else {
    nh.logerror("~eye_status received unknown status %s", msg.data);
    std::ostringstream oss;
    nh.logerror("possible status are ..");
    for(auto & eye_asset: eye_asset_map) {
      nh.logerror("possible status are [%s]", eye_asset.first.c_str());
    }
  }
}

void setup_asset()  // returns initial status
{
  while (not nh.connected())
  {
    nh.spinOnce();
    delay(1000);
  }

  bool mode_right;
  int direction = 1;
  if (nh.getParam("~mode_right", &mode_right)) {
    nh.loginfo(mode_right ? "Read rosparam : mode_right is true" : "mode_right is false");
  } else {
    nh.loginfo("Failed to get mode_right parameter");
  }

  nh.getParam("~direction", &direction);
  nh.loginfo("Read rosparam : direction is %d", direction);

  // get eye_asset_names from rosParam
  std::vector<std::string> eye_asset_names;
  nh.getParam("~eye_asset/names", eye_asset_names);
  if (eye_asset_names.size() > 0) {
    std::ostringstream oss;
    std::copy(eye_asset_names.begin(), eye_asset_names.end(), std::ostream_iterator<std::string>(oss, ", "));
    std::string result = oss.str(); result.pop_back(); result.pop_back();  // remove last ","
    nh.loginfo("Read rosparam : ~eye_asset/names is [%s]", result.c_str());
  }
  // initialize eye_asset_map from eye_asset_names
  for(auto name: eye_asset_names) {
    eye_asset_map[name] = EyeAsset();
    eye_asset_map[name].name = name;
    eye_asset_map[name].direction = direction;
    eye_asset_map[name].invert_rl = not mode_right;
  }
  for(auto name: eye_asset_names) {
    char eye_asset_map_key[128];
    sprintf(eye_asset_map_key, "~eye_asset/%s", name.c_str());
    std::string eye_asset_map_params;
    nh.getParam(eye_asset_map_key, eye_asset_map_params);
    nh.loginfo("Read rosparam : %s is %s", eye_asset_map_key, eye_asset_map_params.c_str());
    StaticJsonDocument<2049> eye_asset_map_doc;
    deserializeJson(eye_asset_map_doc, eye_asset_map_params.c_str());

    EyeAsset *asset = &(eye_asset_map[name]);
    if ( eye_asset_map_doc["path_upperlid"] ) {
      asset->path_upperlid = std::string(eye_asset_map_doc["path_upperlid"].as<const char*>());
    }
    if ( eye_asset_map_doc["path_outline"] ) {
      asset->path_outline = std::string(eye_asset_map_doc["path_outline"].as<const char*>());
    }
    if ( eye_asset_map_doc["path_iris"] ) {
      asset->path_iris = std::string(eye_asset_map_doc["path_iris"].as<const char*>());
    }
    if ( eye_asset_map_doc["path_pupil"] ) {
      asset->path_pupil = std::string(eye_asset_map_doc["path_pupil"].as<const char*>());
    }
    if ( eye_asset_map_doc["path_reflex"] ) {
      asset->path_reflex = std::string(eye_asset_map_doc["path_reflex"].as<const char*>());
    }
    // read array
    JsonArray arr_pos = eye_asset_map_doc["upperlid_position"].as<JsonArray>();
    if ( arr_pos.size() > 0 ) {
      asset->upperlid_position.resize(0);
      for (JsonVariant value : arr_pos) {
        asset->upperlid_position.push_back(value.as<float>());
      }
    }
    // read default_positoin
    if (eye_asset_map_doc["upperlid_default_pos_x"] ) {
      asset->upperlid_default_pos_x = eye_asset_map_doc["upperlid_default_pos_x"].as<int>();
    }
    if (eye_asset_map_doc["upperlid_default_pos_y"] ) {
      asset->upperlid_default_pos_y = eye_asset_map_doc["upperlid_default_pos_y"].as<int>();
    }
    if (eye_asset_map_doc["upperlid_default_theta"] ) {
      asset->upperlid_default_theta = eye_asset_map_doc["upperlid_default_theta"].as<float>();
    }
  }

  // display map data
  // to show this message,
  //  call rosservice call eye_display/set_logger_level rosout DEBUG
  // or
  //  roslaunch launch file with debug:=true
  for(auto name: eye_asset_names) {
    EyeAsset &eye_asset = eye_asset_map[name];
    nh.logdebug("[%s]", name.c_str());
    nh.logdebug("  outline image : %s", eye_asset.path_outline.c_str());
    nh.logdebug("     iris image : %s", eye_asset.path_iris.c_str());
    nh.logdebug("    pupil image : %s", eye_asset.path_pupil.c_str());
    nh.logdebug("   reflex image : %s", eye_asset.path_reflex.c_str());
    nh.logdebug(" upperlid image : %s", eye_asset.path_upperlid.c_str());
    std::ostringstream oss;
    std::copy(eye_asset.upperlid_position.begin(), eye_asset.upperlid_position.end(), std::ostream_iterator<float>(oss, ", "));
    std::string result = oss.str(); result.pop_back(); result.pop_back();  // remove last ","
    nh.logdebug(" upperlid_positions: %s", result.c_str());
    nh.logdebug(" upperlid_default_pos_x : %d", eye_asset.upperlid_default_pos_x);
    nh.logdebug(" upperlid_default_pos_y : %d", eye_asset.upperlid_default_pos_y);
    nh.logdebug(" upperlid_default_theta : %d", eye_asset.upperlid_default_theta);
  }
  // eyeの初期化
  if ( eye_asset_names.size() > 0 ) {
    current_eye_status = eye_asset_names[0];
  } else {
    current_eye_status = std::string("default");
    eye_asset_map[current_eye_status] = EyeAsset();
    nh.logerror("Faile to initialize emotion, use default asset");
  }
}

void setup_ros()
{
  nh.initNode();
  nh.subscribe(sub_point);
  nh.subscribe(sub_eye_status);
  nh.spinOnce();
}

void reconnect_ros()
{
  while (not nh.connected())
  {
    // reconnected to PC node, try to get rosparam
    nh.spinOnce();
    delay(1000);
    setup_asset();
    eye.init(eye_asset_map[current_eye_status], image_width, image_height);
  }
}
