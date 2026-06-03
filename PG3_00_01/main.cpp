#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <windows.h>


void setTimeout(int seconds, std::function<void()> callback) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    callback();
}

int main() {
    SetConsoleOutputCP(65001); 

    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "===== 丁半ゲーム =====" << std::endl;
    std::cout << "サイコロを振ります！" << std::endl;

    int diceResult = (rand() % 6) + 1;

  
    int userInput;
    std::cout << "半(奇数)なら 1、丁(偶数)なら 2 を入力してください: ";
    std::cin >> userInput;

    if (userInput != 1 && userInput != 2) {
        std::cout << "無効な入力です。1か2を入力してください。" << std::endl;
        return 1;
    }

    std::cout << "判定中..." << std::endl;

    
    auto judgeResult = [userInput, diceResult]() {
        std::cout << "\nサイコロの目: " << diceResult << std::endl;

        bool isOdd = (diceResult % 2 != 0); 

        if (isOdd) {
            std::cout << "結果: 半（奇数）" << std::endl;
        }
        else {
            std::cout << "結果: 丁（偶数）" << std::endl;
        }

      
        bool userGuessedOdd = (userInput == 1);

        if (userGuessedOdd == isOdd) {
            std::cout << "あたり" << std::endl;
        }
        else {
            std::cout << "はずれ" << std::endl;
        }
        };

    setTimeout(3, judgeResult);

    return 0;
}