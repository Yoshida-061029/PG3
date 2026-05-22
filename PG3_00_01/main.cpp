#include<stdio.h>
#include<Windows.h>

int RecursiveWage(int a) {
    if (a == 1) {
        return 100;
    }
    return RecursiveWage(a - 1) * 2 - 50;
}

int main() {
    SetConsoleOutputCP(65001);

    int normalWage = 1072;

    printf(" 時間  | 一般賃金 | 再帰賃金\n");
    printf(" ----- |----------|----------\n");

    for (int h = 1; h <= 10; h++) {
        int recursiveWage = RecursiveWage(h);
        printf("%3d時間 |%6d円 |%6d円\n", h, normalWage, recursiveWage);
    }

    int lastRecursiveWage = RecursiveWage(10);
    if (normalWage > lastRecursiveWage) {
        printf("一般賃金の方が高い\n");
    }
    else if (lastRecursiveWage > normalWage) {
        printf("再帰賃金の方が高い\n");
    }
    else {
        printf("同じ\n");
    }

    return 0;
}