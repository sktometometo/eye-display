#include <Arduino.h>
#include <math.h>

#if defined(USE_I2C)
#include <Wire.h>
#include <WireSlave.h>
#endif

#include "eye.hpp"
#include "emotion.hpp"

#if defined(STAMPS3)
#include "ArduinoHWCDCHardware.h"
#elif defined(STAMPC3)
#include "ArduinoHardware.h"
#endif
#include <ArduinoJson.h>

#include "ros/node_handle.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/UInt16.h"
#include "eye_display/EyeStatus.h"

#include <numeric> // accumulate

namespace ros
{
template<class Hardware,
         int MAX_SUBSCRIBERS = 25,
         int MAX_PUBLISHERS = 25,
         int INPUT_SIZE = 512,
         int OUTPUT_SIZE = 512>
class NodeHandleEx : public NodeHandle_<Hardware, MAX_SUBSCRIBERS, MAX_PUBLISHERS, INPUT_SIZE, OUTPUT_SIZE>
{
  typedef NodeHandle_<Hardware, MAX_SUBSCRIBERS, MAX_PUBLISHERS, INPUT_SIZE, OUTPUT_SIZE> super;
public:
  bool getParam(const char* name, int* param, int length = 1, int timeout = 1000) {
    return super::getParam(name, param, length, timeout);
  }
  bool getParam(const char* name, float* param, int length = 1, int timeout = 1000) {
    return super::getParam(name, param, length, timeout);
  }
  bool getParam(const char* name, char** param, int length = 1, int timeout = 1000) {
    return super::getParam(name, param, length, timeout);
  }
  bool getParam(const char* name, bool* param, int length = 1, int timeout = 1000) {
    return super::getParam(name, param, length, timeout);
  }
  bool getParam(const char* name, std::vector<std::string> &param, int timeout = 1000) {
    if (!super::requestParam(name, timeout)) return false;
    param.resize(super::req_param_resp.strings_length);
    //copy it over
    for (int i = 0; i < super::req_param_resp.strings_length; i++)
      param[i] = std::string(super::req_param_resp.strings[i]);
    return true;
  }
  bool getParam(const char* name, std::string &param, int timeout = 1000) {
    if (!super::requestParam(name, timeout)) return false;
    if (super::req_param_resp.strings_length == 1) {
      param = std::string(super::req_param_resp.strings[0]);
      return true;
    } else {
      logwarn("Failed to get param: length mismatch");
      return false;
    }
  }

#define def_log_formatter(funcname)                             \
  void funcname(const char *format, ...) {                      \
    char *string;                                               \
    va_list args;                                               \
    va_start(args, format);                                     \
    if (0 > vasprintf(&string, format, args)) string == NULL;   \
    va_end(args);                                               \
    if(string) {                                                \
      super::logwarn(string);                                   \
      free(string);                                             \
    }                                                           \
  }
  def_log_formatter(logebug)
  def_log_formatter(loginfo)
  def_log_formatter(logwarn)
  def_log_formatter(logerror)
  def_log_formatter(logfatal)
};
}
///

#define TFT_BL 10

constexpr int SDA_PIN = 8;
constexpr int SCL_PIN = 9;
constexpr int I2C_SLAVE_ADDR = 0x42;

const int image_width = 139;
const int image_height = 139;

const char path_image_outline[] = "/outline.jpg";
const char path_image_iris[] = "/iris.jpg";
const char path_image_pupil[] = "/pupil.jpg";
const char path_image_reflex[] = "/reflex.jpg";
const char path_image_upperlid[] = "/upperlid.jpg";

const char path_image_iris_surprised[] = "/iris_surprised.jpg";
const char path_image_pupil_surprised[] = "/pupil_surprised.jpg";
const char path_image_reflex_surprised[] = "/reflex_surprised.jpg";

const char path_image_reflex_happy[] = "/reflex_happy.jpg";

// eye_status ... 0: 通常, 1: 瞬き, 2: 驚き, 3: 眠い, 4: 怒る, 5: 悲しむ・困る, 6: 嬉しい...
int eye_status = 0;
int pre_eye_status = -1;
int blink_level = 0; int max_blink_level = 6;
int surprised_level = 0; int max_surprised_level = 16;
int sleepy_level = 0; int max_sleepy_level = 10;
int angry_level = 0; int max_angry_level = 20;
int sad_level = 0; int max_sad_level = 20;
int happy_level = 0; int max_happy_level = 20;

//char upperlid_position_string[16];


float look_x = 0;
float look_y = 0;

static EyeManager eye;
static EmotionManager emotion(eye);

void callback_look_at(const geometry_msgs::Point &msg);
void callback_emotion(const std_msgs::UInt16 &msg);

void receiveEvent(int howMany);

ros::NodeHandleEx<ArduinoHardware> nh;
ros::Subscriber<geometry_msgs::Point> sub_point("~look_at", &callback_look_at);
ros::Subscriber<std_msgs::UInt16> sub_eye_status("eye_status", &callback_emotion);

#if defined(USE_I2C)
void I2CTask(void *parameter) {
  bool success = WireSlave.begin(SDA_PIN, SCL_PIN, I2C_SLAVE_ADDR);

  Serial.println("I2C slave start");
  if (!success) {
    Serial.println("I2C slave init failed");
    while (1) delay(100);
  }
  WireSlave.onReceive(receiveEvent);
  while (true) {
    WireSlave.update();
    delay(1);  // let I2C and other ESP32 peripherals interrupts work
  }
}
#endif

void callback_look_at(const geometry_msgs::Point &msg)
{
  look_x = (float)msg.x;
  look_y = (float)msg.y;
  char buf[128];
  snprintf(buf, sizeof(buf), "Look at (%f, %f)", look_x, look_y);
  nh.loginfo(buf);
}

void callback_emotion(const std_msgs::UInt16 &msg)
{
  emotion.set_emotion(msg.data);
  char buf[128];
  snprintf(buf, sizeof(buf), "Status updated: %d", msg.data);
  nh.loginfo(buf);
}

void setup()
{
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  SPIFFS.begin();
  Serial.begin(115200);

#if defined(USE_I2C)
#if defined(EYE_RIGHT)
  eye.init(path_image_outline, path_image_iris, path_image_pupil,
          path_image_reflex, path_image_upperlid,
          path_image_iris_surprised, path_image_pupil_surprised, path_image_reflex_surprised,
          path_image_reflex_happy,
          image_width, image_height, 1, true);
#else
  eye.init(path_image_outline, path_image_iris, path_image_pupil,
          path_image_reflex, path_image_upperlid,
          path_image_iris_surprised, path_image_pupil_surprised, path_image_reflex_surprised,
          path_image_reflex_happy,
          image_width, image_height, 1, false);
#endif
  eye.update_look();
  xTaskCreatePinnedToCore(I2CTask, "I2C Task", 1024, NULL, 24, NULL, 0);
#else
  nh.initNode();
  nh.subscribe(sub_point);
  nh.subscribe(sub_eye_status);
  nh.spinOnce();

  while (not nh.connected())
  {
    nh.spinOnce();
    delay(1000);
  }

  char log_msg[50];
  bool mode_right;
  int direction = 1;
  if (nh.getParam("~mode_right", &mode_right)) {
    nh.loginfo(mode_right ? "Read rosparam : mode_right is true" : "mode_right is false");
  } else {
    nh.loginfo("Failed to get mode_right parameter");
  }

  nh.getParam("~direction", &direction);
  sprintf(log_msg, "Read rosparam : direction is %d", direction);
  nh.loginfo(log_msg);

  // get eye_asset_names from rosParam
  std::vector<std::string> eye_asset_names;
  nh.getParam("~eye_asset_names", eye_asset_names);
  // initialize eye_asset_map from eye_asset_names
  for(auto name: eye_asset_names) {
    eye_asset_map[name] = EyeAsset();
    nh.logwarn("get data %s", name.c_str());
  }
  for(auto & eye_asset: eye_asset_map) {
    // ((EyeAsset *)&(eye_asset.second))->upperlid_position.resize(0); // for debug
    char eye_asset_map_key[128];
    sprintf(eye_asset_map_key, "~%s_eye_asset", eye_asset.first.c_str());
    std::string eye_asset_map_params;
    nh.getParam(eye_asset_map_key, eye_asset_map_params);
    nh.loginfo("Read rosparam : %s is %s", eye_asset_map_key, eye_asset_map_params.c_str());
    StaticJsonDocument<2049> eye_asset_map_doc;
    deserializeJson(eye_asset_map_doc, eye_asset_map_params.c_str());

    EyeAsset *asset = &(eye_asset.second);
    if ( eye_asset_map_doc["path_upperlid"] ) { String s = eye_asset_map_doc["path_upperlid"].as<String>(); asset->path_upperlid = (char *)malloc(s.length()+1); s.toCharArray((char *)(asset->path_upperlid), s.length()+1); }
    if ( eye_asset_map_doc["path_outline"] )   { String s = eye_asset_map_doc["path_outline"].as<String>(); asset->path_outline = (char *)malloc(s.length()+1); s.toCharArray((char *)(asset->path_outline), s.length()+1); }
    if ( eye_asset_map_doc["path_iris"] )   { String s = eye_asset_map_doc["path_iris"].as<String>(); asset->path_iris = (char *)malloc(s.length()+1); s.toCharArray((char *)(asset->path_iris), s.length()+1); }
    if ( eye_asset_map_doc["path_pupil"] )   { String s = eye_asset_map_doc["path_pupil"].as<String>(); asset->path_pupil = (char *)malloc(s.length()+1); s.toCharArray((char *)(asset->path_pupil), s.length()+1); }
    if ( eye_asset_map_doc["path_reflex"] )   { String s = eye_asset_map_doc["path_reflex"].as<String>(); asset->path_reflex = (char *)malloc(s.length()+1); s.toCharArray((char *)(asset->path_reflex), s.length()+1); }
    // read array
    JsonArray arr = eye_asset_map_doc["upperlid_position"].as<JsonArray>();
    if ( arr.size() > 0 ) {
      asset->upperlid_position.resize(0);
      for (JsonVariant value : arr) {
	asset->upperlid_position.push_back(value.as<float>());
      }
    } else {
      nh.logwarn("eye_asset_map does not have '%s' data", eye_asset.first.c_str());
    }
  }

  // display map data
  for(auto const& eye_asset: eye_asset_map) {
    char log_msg[256];
    sprintf(log_msg, "%10s :", eye_asset.first.c_str());
    for (float pos_y : eye_asset.second.upperlid_position) {
      sprintf(log_msg, "%s %6.1f", log_msg, pos_y);
    }
    nh.loginfo(log_msg);
    nh.loginfo(eye_asset.second.path_outline);
    nh.loginfo(eye_asset.second.path_iris);
    nh.loginfo(eye_asset.second.path_pupil);
    nh.loginfo(eye_asset.second.path_reflex);
    nh.loginfo(eye_asset.second.path_upperlid);
  }
  //////

  eye.init(path_image_outline, path_image_iris, path_image_pupil,
          path_image_reflex, path_image_upperlid,
          path_image_iris_surprised, path_image_pupil_surprised, path_image_reflex_surprised,
          path_image_reflex_happy,
          image_width, image_height, direction, not mode_right);

  eye.set_gaze_direction(look_x, look_y);
  emotion.set_emotion(); // emotionの初期化
  emotion.update_emotion();
#endif
}

void loop()
{
  delay(100);

  eye.set_gaze_direction(look_x, look_y);
  emotion.update_emotion();

  nh.spinOnce();

  nh.loginfo("Eye status: %d", emotion.get_emotion());
}

void print_log(const char* str){
  nh.loginfo(str);
}


#if defined(USE_I2C)
void receiveEvent(int howMany) {
  // lastReceiveTime = millis();  // Update the last received time
  String str;
  while (0 < WireSlave.available()) {
    char c = WireSlave.read();  // receive byte as a character
    str += c;
  }
  if (str == "0") {eye_status = 0;}
  if (str == "1") {eye_status = 1;}
  if (str == "2") {eye_status = 2;}
  if (str == "3") {eye_status = 3;}
  if (str == "4") {eye_status = 4;}
  if (str == "5") {eye_status = 5;}
  if (str == "6") {eye_status = 6;}
}
#endif
