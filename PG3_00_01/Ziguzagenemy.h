#pragma once
#include "MovePattern.h"

// ---------------------------------------------
// ZiguZagEnemy（ジグザグ移動）
// ---------------------------------------------
class ZiguZagEnemy : public MovePattern {
public:
	void Move(Vector2& position, float deltaTime) override;

private:
	float speedY_ = 80.0f;   // 下方向への速度
	float speedX_ = 150.0f;  // 左右への速度
	float direction_ = 1.0f; // 現在の左右方向（+1 or -1）
	float timer_ = 0.0f;     // 方向転換用タイマー
	float switchInterval_ = 0.5f; // 何秒ごとに左右を切り替えるか
};