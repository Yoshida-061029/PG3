#pragma once
#include "Player.h"
#include "Enemy.h"
#include "SpawnPattern.h"
#include <vector>
#include <memory>

// ---------------------------------------------
// GameScene
// クラス図の GameScene に対応
// Player・Enemy・SpawnPattern を統括するシーン全体の管理クラス
// ---------------------------------------------
class GameScene {
public:
	GameScene();

	void Initialize();
	void Update(float deltaTime);
	void Draw();

	// 自機と敵、敵弾などの当たり判定をまとめてチェックする
	void CheckAllCollision();

	// ステージを進める（敵の出現パターンなどを切り替える）
	void ChangeStage();

	// スコアを加算する
	void updateScore(int points);

	// クリア条件を満たしたかどうかを判定する
	bool checkStageClear();

private:
	std::unique_ptr<Player> player_;                 // - player: Player
	std::vector<std::unique_ptr<Enemy>> enemies_;     // - enemies: List<Enemy>
	// - items: List<Item>
	// ※クラス図には Item クラス自体が定義されていないため、
	//   このリストは未実装（コード化の対象外）
	std::unique_ptr<SpawnPattern> spawnPattern_;      // 敵の出現方法（Strategy）

	int level_ = 1;             // - level: int
	int score_ = 0;             // - score: int
	bool isStageClear_ = false; // - isStageClear: bool
};