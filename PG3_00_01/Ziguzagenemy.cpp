#include "ZiguZagEnemy.h"

void ZiguZagEnemy::Move(Vector2& position, float deltaTime) {
	// 下方向には常に一定速度で進む
	position.y += speedY_ * deltaTime;

	// 一定時間ごとに左右の方向を反転させてジグザグに見せる
	timer_ += deltaTime;
	if (timer_ >= switchInterval_) {
		timer_ = 0.0f;
		direction_ *= -1.0f;
	}
	position.x += speedX_ * direction_ * deltaTime;
}