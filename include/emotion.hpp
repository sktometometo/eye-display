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

extern void print_log(const char *);

class EmotionManager
{
private:
    EyeManager& eyeManager; // EyeManager の参照を保持
    int eye_status = -1;
    std::string eye_status_str;
    int frame = 0;

public:
  // コンストラクタで EyeManager の参照を受け取る
    EmotionManager(EyeManager& manager) : eyeManager(manager) {}

  // emotionに応じて画像セットを読み込む
    int set_emotion(int received_eye_status = 0) {
      if (eye_status == received_eye_status) {
        return 1;
      }
      eye_status = received_eye_status;
      switch ( eye_status ) {
      case eye_display::EyeStatus::EYE_STATUS_NORMAL:
        eye_status_str = "normal";
	break;
      case eye_display::EyeStatus::EYE_STATUS_BLINK:
        eye_status_str = "blink";
	break;
      case eye_display::EyeStatus::EYE_STATUS_SURPRISED:
        eye_status_str = "surprised";
	break;
      case eye_display::EyeStatus::EYE_STATUS_SLEEPY:
        eye_status_str = "sleepy";
	break;
      case eye_display::EyeStatus::EYE_STATUS_ANGRY:
        eye_status_str = "angry";
	break;
      case eye_display::EyeStatus::EYE_STATUS_SAD:
        eye_status_str = "sad";
	break;
      case eye_display::EyeStatus::EYE_STATUS_HAPPY:
        eye_status_str = "happy";
	break;
      case eye_display::EyeStatus::EYE_STATUS_TROUBLED:
        eye_status_str = "troubled";
	break;
      case eye_display::EyeStatus::EYE_STATUS_DELIGHTED:
        eye_status_str = "delighted";
	break;
      case eye_display::EyeStatus::EYE_STATUS_EXPECTING:
        eye_status_str = "expecting";
        break;
      case eye_display::EyeStatus::EYE_STATUS_HEART:
        eye_status_str = "heart";
	break;
      case eye_display::EyeStatus::EYE_STATUS_SHINE1:
        eye_status_str = "shine1";
	break;
      case eye_display::EyeStatus::EYE_STATUS_SHINE2:
        eye_status_str = "shine2";
	break;
      case eye_display::EyeStatus::EYE_STATUS_FLUSTRATED:
        eye_status_str = "flustrated";
	break;
      case eye_display::EyeStatus::EYE_STATUS_BORING:
        eye_status_str = "boring";
        break;
      case eye_display::EyeStatus::EYE_STATUS_SERIOUS:
        eye_status_str = "serious";
	break;
      case eye_display::EyeStatus::EYE_STATUS_REGRET1:
        eye_status_str = "regret1";
	break;
      case eye_display::EyeStatus::EYE_STATUS_REGRET2:
        eye_status_str = "regret2";
        break;

      default:
	return -1;
      }
      frame = 0;
      print_log(eye_status_str.c_str());
      EyeAsset* asset = &(eye_asset_map[eye_status_str.c_str()]);
      eyeManager.load_eye_images(asset->path_outline,
                                 asset->path_iris,
                                 asset->path_pupil,
                                 asset->path_reflex,
                                 asset->path_upperlid);
      return 0;
    }

    int get_emotion(){
      return eye_status;
    }

    void update_emotion() {
      EyeAsset* asset = &(eye_asset_map[eye_status_str.c_str()]);
      float upperlid_y;
      if (asset->upperlid_position.size() > 0) {
        upperlid_y = asset->upperlid_position[frame % asset->upperlid_position.size()];
      }else{
        upperlid_y = 0;
      }
      eyeManager.update_look(0, 0, 0, upperlid_y);  // dx, dy, dx_upperlid, dy_upperlid, dtheta_upperlid
      frame ++;
    }
};
