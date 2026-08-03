#include "GameScene.h"
#include <iostream>
#include <windows.h>

int main() {
	GameScene scene;
	scene.Initialize();

	// 疑似的に数フレーム分だけ更新してみる
	for (int i = 0; i < 60; ++i) {
		scene.Update(1.0f / 60.0f);
	}
	scene.Draw();

	return 0;
}