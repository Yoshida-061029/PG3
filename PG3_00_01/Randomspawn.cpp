#include "RandomSpawn.h"
#include "Enemy.h"
#include "StarigthEnemy.h"
#include <cstdlib>

RandomSpawn::RandomSpawn(float screenWidth, float spawnY)
	: screenWidth_(screenWidth), spawnY_(spawnY) {}

void RandomSpawn::Spawn(std::vector<std::unique_ptr<Enemy>>& enemies) {
	// X座標を画面幅内でランダムに決定する
	float randomX = static_cast<float>(std::rand() % static_cast<int>(screenWidth_));
	Vector2 spawnPosition{ randomX, spawnY_ };

	// 移動パターンは例として直進（StarigthEnemy）を使用
	// 実際の運用では出現させたい種類を引数などで切り替える
	auto movePattern = std::make_unique<StarigthEnemy>();
	enemies.push_back(std::make_unique<Enemy>(std::move(movePattern), spawnPosition));
}