#include <math.h>
#include <functional>
#include <vector>
#include <map>
#include <array>
#include <string>
#include <iostream>

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

#include "eye_assets.hpp"

#if defined(STAMPS3)
#include <lgfx_round_lcd_stamp_s3.hpp>
#elif defined(STAMPC3)
#include <lgfx_round_lcd_stamp_c3.hpp>
#endif

class EmotionManager
{
private:
    EyeManager& eyeManager; // EyeManager の参照を保持
    int eye_status = -1;
    int frame = 0;

public:
  // コンストラクタで EyeManager の参照を受け取る
    EmotionManager(EyeManager& manager) : eyeManager(manager) {}

  // emotionに応じて画像セットを読み込む
    void set_emotion(int received_eye_status = 0) {
      if (eye_status != received_eye_status && eye_assets_map.find(received_eye_status) != eye_assets_map.end()) {
        eye_status = received_eye_status;
        eyeManager.set_picture_files_asset(eye_assets_map[eye_status]);
        frame = 0;
      }
    }

    int get_emotion(){
      return eye_status;
    }

    void update_emotion() {
      float upperlid_y = upperlid_position_map[eye_status][frame % upperlid_position_map[eye_status].size()];
      eyeManager.set_upperlid_position(upperlid_y);
      eyeManager.update();
      frame ++;
    }
};
