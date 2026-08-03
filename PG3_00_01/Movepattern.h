#pragma once
#include "Vector2.h"

// ---------------------------------------------
// MovePattern
// 敵の移動アルゴリズムを切り替えるためのStrategyパターン基底クラス
// ---------------------------------------------
class MovePattern {
public:
	virtual ~MovePattern() = default;

	// 座標を移動パターンに従って更新する
	// position : 更新対象の座標（参照渡しで直接書き換える）
	// deltaTime: 前フレームからの経過時間
	virtual void Move(Vector2& position, float deltaTime) = 0;
};