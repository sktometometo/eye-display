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
    int current_eye_status = -1;
    int frame = 0;

public:
    // コンストラクタで EyeManager の参照を受け取る
    EmotionManager(EyeManager& manager) : eyeManager(manager) {}

    // 感情ごとの表示設定
    void set_emotion(int eye_status) {
      if (current_eye_status != eye_status && eye_assets_map.find(eye_status) != eye_assets_map.end()) {
        current_eye_status = eye_status;
        eyeManager.set_picture_files_asset(eye_assets_map[eye_status]);
        frame = 0;
      }
    }

    void update_emotion() {
      float upperlid_y = upperlid_position_map[current_eye_status][frame % upperlid_position_map[current_eye_status].size()];
      eyeManager.set_upperlid_position(upperlid_y);
      eyeManager.update();
      frame ++;
    }
};