#pragma once

struct EyeAsset {
    const char* eyeball;
    const char* iris;
    const char* pupil;
    const char* reflex;
    const char* upperlid;
};

// EDIT HERE: 目に用いる画像を変えるときや感情種類を増減するときにここを編集
constexpr EyeAsset normal_eye = {"/normal_kxr_eyeball.jpg", "/normal_kxr_iris.jpg", "/normal_kxr_pupil.png", "/normal_kxr_reflex.png", "/normal_kxr_upperlid.jpg"};
constexpr EyeAsset blink_eye = {"/normal_kxr_eyeball.jpg", "/normal_kxr_iris.jpg", "/normal_kxr_pupil.png", "/normal_kxr_reflex.png", "/normal_kxr_upperlid.jpg"};
constexpr EyeAsset surprised_eye = {"/normal_kxr_eyeball.jpg", "/normal_kxr_iris_surprised.jpg", "/normal_kxr_pupil_surprised.png", "/normal_kxr_reflex_surp.png", "/normal_kxr_upperlid.jpg"};
constexpr EyeAsset sleepy_eye = {"/normal_kxr_eyeball.jpg", "/normal_kxr_iris_sleepy.png", "/normal_kxr_pupil_sleepy.png", "/white.jpg", "/normal_kxr_upperlid.jpg"};
constexpr EyeAsset angry_eye = {"/normal_kxr_eyeball.jpg", "/normal_kxr_iris.jpg", "/normal_kxr_pupil.png", "/normal_kxr_reflex.png", "/normal_kxr_upperlid_ldown.jpg"};
constexpr EyeAsset sad_eye = {"/normal_kxr_eyeball.jpg", "/normal_kxr_iris.jpg", "/normal_kxr_pupil.png", "/normal_kxr_reflex.png", "/normal_kxr_upperlid_rdown.jpg"};
constexpr EyeAsset happy_eye = {"/normal_kxr_eyeball.jpg", "/white.jpg", "/white.png", "/white.png", "/normal_kxr_upperlid_happy.jpg"};

// EDIT HERE: eye_status（ROSトピックのメッセージ）と それぞれのEyeAssetの対応付け
std::map<int, EyeAsset> eye_assets_map = {
  {0, normal_eye},
  {1, blink_eye},
  {2, surprised_eye},
  {3, sleepy_eye},
  {4, angry_eye},
  {5, sad_eye},
  {6, happy_eye} // ← ここに新しい目を追加
};

// EDIT HERE: まぶたのアニメーションを設定
std::map<int, std::vector<float>> upperlid_position_map = {
  {0, {-130}},
  {1, {-130, -130, 0, 0, -130, -130}},
  {2, {- 130, - 130, -130, -130, 0, 0, -130, -130, -130, -130, 0, -130, -130, 0, -130, -130}},
  {3, {- 70, - 70, -60, 0, 0, 0, -60, -70, -70, - 70}},
  {4, {- 10}},
  {5, {0}},
  {6, {0}},
};  