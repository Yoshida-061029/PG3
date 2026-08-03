#pragma once
#include "MovePattern.h"

// ---------------------------------------------
// StarigthEnemy（直進移動）
// クラス図の名称をそのまま踏襲（Straight のスペル注意）
// ---------------------------------------------
class StarigthEnemy : public MovePattern {
public:
	void Move(Vector2& position, float deltaTime) override;

private:
	float speed_ = 100.0f; // 下方向への移動速度
};