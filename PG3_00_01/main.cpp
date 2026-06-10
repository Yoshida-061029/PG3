#include<stdio.h>
#include<Windows.h>

int Power2(int n) {
    if (n == 0) return 1;
    return Power2(n - 1) * 2;
}

int RecursiveWage(int a) {
    if (a == 1) {
        return 100;
    }
    return RecursiveWage(a - 1) + 50 * Power2(a - 2);
}

int main() {
    SetConsoleOutputCP(65001);

    int baseWage = 1072;

    printf(" 時間  | 一般賃金 | 再帰賃金\n");
    printf(" ----- |----------|----------\n");

    for (int h = 1; h <= 10; h++) {
        int normalWage = baseWage * h;
        int recursiveWage = RecursiveWage(h);
        printf("%3d時間 |%6d円 |%6d円\n", h, normalWage, recursiveWage);
    }

    int lastNormalWage = baseWage * 10;
    int lastRecursiveWage = RecursiveWage(10);
    if (lastNormalWage > lastRecursiveWage) {
        printf("一般賃金の方が高い\n");
    }
    else if (lastRecursiveWage > lastNormalWage) {
        printf("再帰賃金の方が高い\n");
    }
    else {
        printf("同じ\n");
    }

    return 0;
}