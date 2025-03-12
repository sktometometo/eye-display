#pragma once

extern const int image_width;
extern const int image_height;

extern EyeManager eye;
extern std::map<std::string, EyeAsset> eye_asset_map;
extern std::string current_eye_status;

#include <Wire.h>
#include <WireSlave.h>

constexpr int SDA_PIN = 8;
constexpr int SCL_PIN = 9;
constexpr int I2C_SLAVE_ADDR = 0x42;

void receiveEvent(int howMany) {
  // lastReceiveTime = millis();  // Update the last received time
  String str;
  while (0 < WireSlave.available()) {
    char c = WireSlave.read();  // receive byte as a character
    str += c;
  }
  current_eye_status = std::string(str.c_str());
  auto it = eye_asset_map.find(current_eye_status);
  if (it != eye_asset_map.end()) {
    eye.set_emotion(it->second);
  }
}

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

void setup_asset()  // returns initial status
{
  eye_asset_map["normal"] = EyeAsset();
  eye_asset_map["normal"].name = "normal";
  eye_asset_map["normal"].upperlid_position = {9};
  eye_asset_map["normal"].direction = 1;
#if defined(EYE_RIGHT)
  eye_asset_map["normal"].direction = true;
#else
  eye_asset_map["normal"].invert_rl = false;
#endif

  eye_asset_map["blink"] = EyeAsset();
  eye_asset_map["blink"].name = "blink";
  eye_asset_map["blink"].upperlid_position = {9, 9, 130, 130, 9, 9};
  eye_asset_map["blink"].direction = 1;
#if defined(EYE_RIGHT)
  eye_asset_map["blink"].direction = true;
#else
  eye_asset_map["blink"].invert_rl = false;
#endif

  current_eye_status = std::string("blink");
}

void setup_i2c()
{
  xTaskCreatePinnedToCore(I2CTask, "I2C Task", 1024, NULL, 24, NULL, 0);
}
