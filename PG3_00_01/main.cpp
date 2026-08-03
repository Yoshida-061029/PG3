#include <iostream>
#include <string>
#include <chrono>

int main() {

	std::string a(1000000, 'a');  // 100,000 → 1,000,000 に修正


	auto start_copy = std::chrono::high_resolution_clock::now();
	std::string b = a;
	auto end_copy = std::chrono::high_resolution_clock::now();
	auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

	auto start_move = std::chrono::high_resolution_clock::now();
	std::string c = std::move(a);
	auto end_move = std::chrono::high_resolution_clock::now();
	auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

	std::cout << "1,000,000文字を移動とコピーで比較しました。" << std::endl;
	std::cout << "コピー: " << copy_duration << " μs" << std::endl;
	std::cout << "移動  : " << move_duration << " μs" << std::endl;

	std::cout << "続行するには何かキーを押してください . . .";
	std::cin.get();

	return 0;
}