#pragma once
#if 0
struct EyeAsset {
    const char* eyeball;  // static
    const char* iris;     // set_gaze_direction(x,y) to set position
    const char* pupil;    //  move along with iris
    const char* reflex;   //  move along with puppil + random motion
    const char* upperlid; // use upperlid_position_map to set y-axis motoin
};
#endif

// EDIT HERE: まぶたのアニメーションを設定
/*
std::map<int, std::vector<float>> upperlid_position_map = {
  {0, {-130}},
  //  {1, {-130, -130, 0, 0, -130, -130}},
  {1, {9, 9, 130, 130, 9, 9}},
  {2, {- 130, - 130, -130, -130, 0, 0, -130, -130, -130, -130, 0, -130, -130, 0, -130, -130}},
  {3, {- 70, - 70, -60, 0, 0, 0, -60, -70, -70, - 70}},
  {4, {- 10}},
  {5, {0}},
  {6, {0}},
};
*/

struct EyeAsset {
  const char* dummy = nullptr;
  const char* path_outline = "/outline.jpg";    // static
  const char* path_iris = "/iris.jpg";          // set_gaze_direction(x,y) to set position
  const char* path_pupil = "/pupil.jpg";        //  move along with iris
  const char* path_reflex = "/reflex.jpg" ;     //  move along with puppil + random motion
  const char* path_upperlid = "/upperlid.jpg";  // use upperlid_position_map to set y-axis motoin
  std::vector<float> upperlid_position = {0}; // upperlid = motion layer
};
// std::map<std::string, EyeAsset> eye_asset_map = {{"normal", EyeAsset()},
// 						 {"blink", EyeAsset()},
// 						 {"surprised", EyeAsset()},
// 						 {"sleepy", EyeAsset()},
// 						 {"angry", EyeAsset()},
// 						 {"sad", EyeAsset()},
// 						 {"happy", EyeAsset()}};
std::map<std::string, EyeAsset> eye_asset_map = {};

