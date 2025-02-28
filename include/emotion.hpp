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
	//eyeManager.ready_for_normal_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_BLINK:
        eye_status_str = "blink";
	//eyeManager.ready_for_blink_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_SURPRISED:
        eye_status_str = "surprised";
	//eyeManager.ready_for_surprised_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_SLEEPY:
        eye_status_str = "sleepy";
	//eyeManager.ready_for_sleepy_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_ANGRY:
        eye_status_str = "angry";
	//eyeManager.ready_for_angry_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_SAD:
        eye_status_str = "sad";
	//eyeManager.ready_for_sad_eye();
	break;
      case eye_display::EyeStatus::EYE_STATUS_HAPPY:
        eye_status_str = "happy";
	//eyeManager.ready_for_happy_eye();
	break;
      default:
	return -1;
      }
      frame = 0;
      print_log(eye_status_str.c_str());
      //eyeManager.ready_for_normal_eye();
      EyeAsset* asset = &(eye_asset_map[eye_status_str.c_str()]);
      // eyeManager.load_eye_images(NULL, NULL, NULL, NULL, NULL);
      eyeManager.load_eye_images(asset->path_outline,
                                 asset->path_iris,
                                 asset->path_pupil,
                                 asset->path_reflex,
                                 asset->path_upperlid);
      return 0;
      // eyeManager.ready_for_normal_eye();
      // return 0;
      // eyeManager.load_eye_images(NULL,
      //                            NULL,
      //                            NULL,
      //                            NULL,
      //                            NULL);
      // eyeManager.load_eye_images("/outline.jpg",
      //                            "/outline.jpg",
      //                            "/outline.jpg",
      //                            "/outline.jpg",
      //                            "/outline.jpg");
      // return 0;
      // eyeManager.load_eye_images(asset->path_outline,
      //                            asset->path_iris,
      //                            asset->path_pupil,
      //                            asset->path_reflex,
      //                            asset->path_upperlid);
      return 0;
    }

    int get_emotion(){
      return eye_status;
    }

    void update_emotion() {
      //float upperlid_y = upperlid_position_map[eye_status][frame % upperlid_position_map[eye_status].size()];
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
