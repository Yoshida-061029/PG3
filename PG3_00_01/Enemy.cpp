#include "Enemy.h"

Enemy::Enemy(std::unique_ptr<MovePattern> movePattern, Vector2 position, int hp, int hitDamage)
	: hp_(hp), hitDamage_(hitDamage), position_(position), movePattern_(std::move(movePattern)) {}

void Enemy::Move(float deltaTime) {
	if (movePattern_) {
		movePattern_->Move(position_, deltaTime);
	}
}

void Enemy::HitBullet(int damage) {
	hp_ -= damage;
	if (hp_ < 0) {
		hp_ = 0;
	}
}

void Enemy::DropItem() {
	if (itemDrop_) {
		// TODO: アイテムの生成処理をここに実装する
		// （クラス図に Item クラスが定義されていないため未実装）
	}
}

void Enemy::Spawn(const Vector2& spawnPosition) {
	position_ = spawnPosition;
	hp_ = 10; // 出現時にhpをリセット（必要に応じて調整）
}

bool Enemy::IsDeath() const {
	return hp_ <= 0;
}