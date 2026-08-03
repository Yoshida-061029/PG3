#include "ChaseEnemy.h"
#include <cmath>

void ChaseEnemy::Move(Vector2& position, float deltaTime) {
	if (!target_) {
		return; // 追尾対象が未設定なら何もしない
	}

	// 対象への方向ベクトルを計算して正規化
	Vector2 diff{ target_->x - position.x, target_->y - position.y };
	float length = std::sqrt(diff.x * diff.x + diff.y * diff.y);
	if (length > 0.0001f) {
		diff.x /= length;
		diff.y /= length;
	}

	position.x += diff.x * speed_ * deltaTime;
	position.y += diff.y * speed_ * deltaTime;
}