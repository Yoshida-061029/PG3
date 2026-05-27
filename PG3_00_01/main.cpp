#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


typedef void (*ResultCallback)(int dice, int user_choice);


void judge_result(int dice, int user_choice) {
    int is_odd = dice % 2; 

    printf("\n--- 結果発表 ---\n");
    printf("サイコロの目: %d (%s)\n", dice, is_odd ? "半（奇数）" : "丁（偶数）");

    if (is_odd == user_choice) {
        printf("正解！\n");
    }
    else {
        printf("不正解...\n");
    }
}


void reveal_after_delay(int dice, int user_choice, ResultCallback callback) {
    printf("結果を確認中");
    for (int i = 0; i < 3; i++) {
        Sleep(1000);
        printf(".");
        fflush(stdout);
    }
    printf("\n");
    callback(dice, user_choice);
}

int main(void) {
    SetConsoleOutputCP(65001);

    srand((unsigned int)time(NULL));

    int dice = (rand() % 6) + 1;

    printf("=== 丁半ゲーム ===\n");
    printf("サイコロを振りました！\n");
    printf("丁（偶数）か半（奇数）か当ててください。\n");
    printf("  1: 半（奇数）\n");
    printf("  0: 丁（偶数）\n");
    printf("あなたの予想: ");

    int user_choice;
    scanf_s("%d", &user_choice);

    if (user_choice != 0 && user_choice != 1) {
        printf("無効な入力です。0か1を入力してください。\n");
        return 1;
    }

    reveal_after_delay(dice, user_choice, judge_result);

    return 0;
}