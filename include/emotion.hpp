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
    int eye_status = -1;
    int frame = 0;

public:
  // コンストラクタで EyeManager の参照を受け取る
    EmotionManager(EyeManager& manager) : eyeManager(manager) {}

  // emotionに応じて画像セットを読み込む
    int set_emotion(int received_eye_status = 0) {
      if (eye_status == received_eye_status || eye_assets_map.find(received_eye_status) == eye_assets_map.end()) {
        return 1;
      }
      eye_status = received_eye_status;
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
      frame = 0;
      return 0;
    }

    int get_emotion(){
      return eye_status;
    }

    void update_emotion() {
      float upperlid_y = upperlid_position_map[eye_status][frame % upperlid_position_map[eye_status].size()];
      eyeManager.update_look(0, 0, 0, upperlid_y);  // dx, dy, dx_upperlid, dy_upperlid, dtheta_upperlid
      frame ++;
    }
};
