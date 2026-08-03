#pragma once
#include "Vector2.h"

// ---------------------------------------------
// Player
// クラス図の Player に対応
// ---------------------------------------------
class Player {
public:
	Player(Vector2 position, float hp = 100.0f, float speed = 200.0f, float attackPower = 10.0f);

	// 入力に応じて自機の座標を移動させる
	void Move(float deltaTime);

	// 弾を発射するなどの攻撃処理
	void Attack();

	// 被弾時にダメージを受ける
	void TakeDamage(float damage);

	// アイテム取得時にステータスを強化する
	void GetItem();

	// hpが0以下かどうかを判定する
	bool IsDeath() const;

	const Vector2& GetPosition() const { return position_; }
	float GetHp() const { return hp_; }
	float GetAttackPower() const { return attackPower_; }

private:
	Vector2 position_;
	float hp_;            // - hp : float
	float speed_;         // - speed : float
	float attackPower_;   // - attackPower : float
	int powerUpLevel_ = 0; // - powerUpLevel
};