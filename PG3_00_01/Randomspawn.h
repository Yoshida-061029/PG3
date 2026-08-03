#pragma once
#include "SpawnPattern.h"

// ---------------------------------------------
// RandomSpawn
// 画面上部のランダムなX座標に敵を出現させる
// ---------------------------------------------
class RandomSpawn : public SpawnPattern {
public:
	RandomSpawn(float screenWidth, float spawnY = 0.0f);

	void Spawn(std::vector<std::unique_ptr<Enemy>>& enemies) override;

private:
	float screenWidth_;
	float spawnY_;
};