#pragma once

class Enemy;
#include <vector>
#include <memory>

// ---------------------------------------------
// SpawnPattern
// 敵の出現方法を切り替えるためのStrategyパターン基底クラス
// ---------------------------------------------
class SpawnPattern {
public:
	virtual ~SpawnPattern() = default;

	// 敵を生成し、enemies に追加する
	virtual void Spawn(std::vector<std::unique_ptr<Enemy>>& enemies) = 0;
};