#include <iostream>
#include <Windows.h>
using namespace std;


template <typename T>
T Min(T a, T b) {
    return (a < b) ? a : b;
}


template <>
char Min(char a, char b) {
    cout << "数字以外は代入できません" << endl;
    return a;
}

int main() {
    SetConsoleOutputCP(65001);


    int i1 = 10, i2 = 20;
    cout << "int: Min(" << i1 << ", " << i2 << ") = " << Min(i1, i2) << endl;


    float f1 = 3.14f, f2 = 2.71f;
    cout << "float: Min(" << f1 << ", " << f2 << ") = " << Min(f1, f2) << endl;

    double d1 = 1.234, d2 = 5.678;
    cout << "double: Min(" << d1 << ", " << d2 << ") = " << Min(d1, d2) << endl;


    char c1 = 'A', c2 = 'B';
    Min(c1, c2);

    return 0;
}