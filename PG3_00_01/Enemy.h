#pragma once
#include "Vector2.h"
#include "MovePattern.h"
#include <memory>

// ---------------------------------------------
// Enemy
// クラス図の Enemy に対応
// 移動アルゴリズムは MovePattern に委譲する（Strategyパターン）
// ---------------------------------------------
class Enemy {
public:
	// movePattern の所有権を Enemy に譲渡する
	Enemy(std::unique_ptr<MovePattern> movePattern, Vector2 position, int hp = 10, int hitDamage = 1);

	// 移動パターンに従って自身の座標を更新する
	void Move(float deltaTime);

	// 弾が命中したときの処理（hpを減らす）
	void HitBullet(int damage);

	// 撃破時にアイテムをドロップする
	void DropItem();

	// 出現演出などが必要な場合の初期化処理
	void Spawn(const Vector2& spawnPosition);

	// hpが0以下かどうかを判定する
	bool IsDeath() const;

	const Vector2& GetPosition() const { return position_; }

private:
	int hp_;              // - hp
	int hitDamage_;       // - hitDamage（衝突時にプレイヤーへ与えるダメージ）
	Vector2 position_;    // - position
	bool itemDrop_ = false; // - itemDrop（撃破時にアイテムを落とすか）

	std::unique_ptr<MovePattern> movePattern_; // Enemy --> MovePattern
};