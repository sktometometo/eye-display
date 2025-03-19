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
  for (int i=0; i<eye_asset_names.size(); i++) {
    nh.loginfo("~eye_asset/names[%d]: %s", i, eye_asset_names[i].c_str());
  }
  // initialize eye_asset_map from eye_asset_names
  for(auto name: eye_asset_names) {
    eye_asset_map[name] = EyeAsset();
    eye_asset_map[name].name = name;
    eye_asset_map[name].direction = direction;
    eye_asset_map[name].invert_rl = not mode_right;
  }
  for(auto name: eye_asset_names) {
    EyeAsset *asset = &(eye_asset_map[name]);
    char eye_asset_map_key[128];
    // path_upperlid
    snprintf(eye_asset_map_key, sizeof(eye_asset_map_key), "~eye_asset/%s/path_upperlid", name.c_str());
    nh.getParam(eye_asset_map_key, asset->path_upperlid);
    // path_outline
    snprintf(eye_asset_map_key, sizeof(eye_asset_map_key), "~eye_asset/%s/path_outline", name.c_str());
    nh.getParam(eye_asset_map_key, asset->path_outline);
    // path_iris
    snprintf(eye_asset_map_key, sizeof(eye_asset_map_key), "~eye_asset/%s/path_iris", name.c_str());
    nh.getParam(eye_asset_map_key, asset->path_iris);
    // path_pupil
    snprintf(eye_asset_map_key, sizeof(eye_asset_map_key), "~eye_asset/%s/path_pupil", name.c_str());
    nh.getParam(eye_asset_map_key, asset->path_pupil);
    // path_reflex
    snprintf(eye_asset_map_key, sizeof(eye_asset_map_key), "~eye_asset/%s/path_reflex", name.c_str());
    nh.getParam(eye_asset_map_key, asset->path_reflex);
    // upperlid_position
    snprintf(eye_asset_map_key, sizeof(eye_asset_map_key), "~eye_asset/%s/upperlid_position", name.c_str());
    nh.getParam(eye_asset_map_key, asset->upperlid_position);
    // upperlid_default_pos_x
    snprintf(eye_asset_map_key, sizeof(eye_asset_map_key), "~eye_asset/%s/upperlid_default_pos_x", name.c_str());
    nh.getParam(eye_asset_map_key, &(asset->upperlid_default_pos_x));
    // upperlid_default_pos_y
    snprintf(eye_asset_map_key, sizeof(eye_asset_map_key), "~eye_asset/%s/upperlid_default_pos_y", name.c_str());
    nh.getParam(eye_asset_map_key, &(asset->upperlid_default_pos_y));
    // upperlid_default_theta
    snprintf(eye_asset_map_key, sizeof(eye_asset_map_key), "~eye_asset/%s/upperlid_default_theta", name.c_str());
    nh.getParam(eye_asset_map_key, &(asset->upperlid_default_theta));
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
