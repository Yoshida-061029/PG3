#include "GameScene.h"
#include "RandomSpawn.h"
#include <algorithm>

GameScene::GameScene() = default;

void GameScene::Initialize() {
	player_ = std::make_unique<Player>(Vector2{ 640.0f, 600.0f });
	spawnPattern_ = std::make_unique<RandomSpawn>(1280.0f);

	enemies_.clear();
	level_ = 1;
	score_ = 0;
	isStageClear_ = false;
}

void GameScene::Update(float deltaTime) {
	if (player_) {
		player_->Move(deltaTime);
	}

	for (auto& enemy : enemies_) {
		enemy->Move(deltaTime);
	}

	// 撃破された敵を取り除く
	enemies_.erase(
		std::remove_if(enemies_.begin(), enemies_.end(),
			[](const std::unique_ptr<Enemy>& e) { return e->IsDeath(); }),
		enemies_.end());

	CheckAllCollision();

	if (checkStageClear()) {
		ChangeStage();
	}
}

void GameScene::Draw() {
	// TODO: Novice::DrawBox などを使用して player_ / enemies_ を描画する
}

void GameScene::CheckAllCollision() {
	if (!player_) {
		return;
	}

	// TODO: 実際の衝突判定（矩形や円の当たり判定）に置き換える
	for (auto& enemy : enemies_) {
		const Vector2& enemyPos = enemy->GetPosition();
		const Vector2& playerPos = player_->GetPosition();

		float dx = enemyPos.x - playerPos.x;
		float dy = enemyPos.y - playerPos.y;
		float distanceSq = dx * dx + dy * dy;

		const float hitRadius = 20.0f;
		if (distanceSq <= hitRadius * hitRadius) {
			player_->TakeDamage(10.0f);
			enemy->HitBullet(9999); // 接触した敵を撃破扱いにする（例）
		}
	}
}

void GameScene::ChangeStage() {
	level_++;
	isStageClear_ = false;
	enemies_.clear();
	// TODO: レベルに応じて SpawnPattern を切り替える処理を追加する
}

void GameScene::updateScore(int points) {
	score_ += points;
}

bool GameScene::checkStageClear() {
	// 例：一定スコアに到達したらクリアとする
	isStageClear_ = (score_ >= level_ * 1000);
	return isStageClear_;
}