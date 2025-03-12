#include <Arduino.h>
#include <math.h>

#include "eye.hpp"

#if defined(USE_I2C)
#include "i2c_lib.h"
#endif
#if defined(USE_ROS)
#include "ros_lib.h"
#endif

#if defined(STAMPS3)
#include "ArduinoHWCDCHardware.h"
#elif defined(STAMPC3)
#include "ArduinoHardware.h"
#endif

#include <map>
#include <string>

#define TFT_BL 10

const int image_width = 139;
const int image_height = 139;

EyeManager eye;
std::map<std::string, EyeAsset> eye_asset_map = {};
std::string current_eye_status;

#if !defined(USE_I2C) && !defined(USE_ROS) // sample code for eye asset
void setup_asset()  // returns initial status
{
  eye_asset_map["normal"] = EyeAsset();
  eye_asset_map["normal"].name = "normal";
  eye_asset_map["normal"].upperlid_position = {9};
  eye_asset_map["normal"].direction = 1;
  eye_asset_map["normal"].direction = true;

  eye_asset_map["blink"] = EyeAsset();
  eye_asset_map["blink"].name = "blink";
  eye_asset_map["blink"].upperlid_position = {9, 9, 130, 130, 9, 9};
  eye_asset_map["blink"].direction = 1;
  eye_asset_map["blink"].direction = true;

  eye_asset_map["happy"] = EyeAsset();
  eye_asset_map["happy"].name = "happy";
  eye_asset_map["happy"].path_iris = "/white.jpg";
  eye_asset_map["happy"].path_pupil = "/white.jpg";
  eye_asset_map["happy"].path_reflex = "/white.jpg";
  eye_asset_map["happy"].path_upperlid = "/reflex_happy.jpg";
  eye_asset_map["happy"].upperlid_position = {130, 131, 132, 133, 134, 135};
  eye_asset_map["happy"].direction = 1;
  eye_asset_map["happy"].direction = true;

  current_eye_status = std::string("happy");
}
#endif

void setup()
{
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  SPIFFS.begin();
  Serial.begin(115200);

#if defined(USE_ROS)  // USE_ROS
  setup_ros();
#endif

  setup_asset();
  eye.init(eye_asset_map[current_eye_status], image_width, image_height);
  eye.update_look();

#if defined(USE_I2C)
  setup_i2c();
#endif
}

void loop()
{
#if defined(USE_ROS)  // USE_ROS
  reconnect_ros();
#endif
  delay(100);

  int frame = eye.update_emotion();

#if defined(USE_ROS)
  nh.spinOnce();
  nh.loginfo("Eye status: %s (%d)", eye.get_emotion().c_str(), frame);
#endif

#if !defined(USE_I2C) && !defined(USE_ROS) // sample code for eye asset
  static float look_x = 0;
  static float look_y = 0;
  look_x = 10.0 * sin(frame * 0.1);
  look_y = 10.0 * cos(frame * 0.1) ;
  eye.set_gaze_direction(look_x, look_y);

  if (frame % 10 == 0) {
    static auto eye_asset = eye_asset_map.begin();
    eye_asset++;
    if (eye_asset == eye_asset_map.end()) eye_asset = eye_asset_map.begin();
    eye.set_emotion(eye_asset->second);
  }
#endif
}
