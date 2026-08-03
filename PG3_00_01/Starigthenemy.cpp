#include "StarigthEnemy.h"

void StarigthEnemy::Move(Vector2& position, float deltaTime) {
	// まっすぐ下方向に進むだけのシンプルな移動
	position.y += speed_ * deltaTime;
}