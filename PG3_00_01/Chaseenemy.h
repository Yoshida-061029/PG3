#pragma once
#include "MovePattern.h"

// ---------------------------------------------
// ChaseEnemy（追尾移動）
// プレイヤー座標を追いかけて移動する
// ---------------------------------------------
class ChaseEnemy : public MovePattern {
public:
	void Move(Vector2& position, float deltaTime) override;

	// 追尾対象（プレイヤー座標）を設定する
	// GameScene・Enemy側で生成時に呼び出しておく
	void SetTarget(const Vector2* target) { target_ = target; }

private:
	const Vector2* target_ = nullptr; // 追尾対象の座標へのポインタ
	float speed_ = 90.0f;
};