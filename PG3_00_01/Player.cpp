#include "Player.h"

Player::Player(Vector2 position, float hp, float speed, float attackPower)
	: position_(position), hp_(hp), speed_(speed), attackPower_(attackPower) {}

void Player::Move(float deltaTime) {
	// TODO: Novice::CheckHitKey などの入力取得処理に置き換える
	// 例）
	// char keys[256] = {0};
	// Novice::GetHitKeyStateAll(keys);
	// if (keys[DIK_LEFT])  position_.x -= speed_ * deltaTime;
	// if (keys[DIK_RIGHT]) position_.x += speed_ * deltaTime;
	(void)deltaTime;
}

void Player::Attack() {
	// TODO: 弾（Bullet）を生成する処理をここに実装する
	// （クラス図に Bullet クラスが定義されていないため未実装）
}

void Player::TakeDamage(float damage) {
	hp_ -= damage;
	if (hp_ < 0.0f) {
		hp_ = 0.0f;
	}
}

void Player::GetItem() {
	// アイテム取得で強化レベルを上げ、攻撃力に反映する
	powerUpLevel_++;
	attackPower_ += 5.0f;
}

bool Player::IsDeath() const {
	return hp_ <= 0.0f;
}