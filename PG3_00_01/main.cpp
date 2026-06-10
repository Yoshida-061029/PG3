#include <stdio.h>
#include <Windows.h>

int RecursiveWage(int n) {
    if (n <= 1) {
        return 100;
    }
    return RecursiveWage(n - 1) * 2 - 50;
}

int RecursiveTotal(int n) {
    if (n <= 0) {
        return 0;
    }
    return RecursiveTotal(n - 1) + RecursiveWage(n);
}

int main() {
    SetConsoleOutputCP(65001);

    const int baseWage = 1072;

    printf("   時間 |　 一般賃金  | 再帰賃金\n");
    printf("  ------|-------------|------------\n");

    for (int h = 1; h <= 10; h++) {
        int normalTotal = baseWage * h;
        int recursiveTotal = RecursiveTotal(h);
        printf("%3d時間 |%10d円 |%10d円\n", h, normalTotal, recursiveTotal);
    }

    int lastNormal = baseWage * 10;
    int lastRecursive = RecursiveTotal(10);
    if (lastNormal > lastRecursive) {
        printf("一般賃金の方が高い\n");
    }
    else if (lastRecursive > lastNormal) {
        printf("再帰賃金の方が高い\n");
    }
    else {
        printf("同じ\n");
    }

    return 0;
}