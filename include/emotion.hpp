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

#include "eye_display/EyeStatus.h" // define EysStatus::EYE_STATUS_NORMAL

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
    int set_emotion(int eye_status) {
      if ( current_eye_status == eye_status ) {
	return 1;
      }
      switch ( eye_status ) {
      case eye_display::EyeStatus::EYE_STATUS_NORMAL:
	eyeManager.ready_for_normal_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_BLINK:
	eyeManager.ready_for_blink_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_SURPRISED:
	eyeManager.ready_for_surprised_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_SLEEPY:
	eyeManager.ready_for_sleepy_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_ANGRY:
	eyeManager.ready_for_angry_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_SAD:
	eyeManager.ready_for_sad_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_HAPPY:
	eyeManager.ready_for_happy_eye();
	break;
      default:
	return -1;
      }
      current_eye_status = eye_status;
      frame = 0;
      return 0;
    }

    void update_emotion() {
      float upperlid_y = upperlid_position_map[current_eye_status][frame % upperlid_position_map[current_eye_status].size()];
      eyeManager.update_look(0, 0, 0, upperlid_y);  // dx, dy, dx_upperlid, dy_upperlid, dtheta_upperlid
      frame ++;
    }
};
