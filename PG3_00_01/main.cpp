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
    return '\0'; 
}

int main() {
    SetConsoleOutputCP(65001);

    int i1 = 10, i2 = 20;
    cout << "int: Min(" << i1 << ", " << i2 << ") = " << Min(i1, i2) << endl;
    int i3 = 5, i4 = 3;
    cout << "int: Min(" << i3 << ", " << i4 << ") = " << Min(i3, i4) << endl;

    float f1 = 3.14f, f2 = 2.71f;
    cout << "float: Min(" << f1 << ", " << f2 << ") = " << Min(f1, f2) << endl;
    float f3 = 1.11f, f4 = 9.99f;
    cout << "float: Min(" << f3 << ", " << f4 << ") = " << Min(f3, f4) << endl;

    double d1 = 1.234, d2 = 5.678;
    cout << "double: Min(" << d1 << ", " << d2 << ") = " << Min(d1, d2) << endl;
    double d3 = 9.999, d4 = 0.001;
    cout << "double: Min(" << d3 << ", " << d4 << ") = " << Min(d3, d4) << endl;

   
    char c1 = 'A', c2 = 'B';
    cout << "char: Min(" << c1 << ", " << c2 << ") = ";
    Min(c1, c2);
    char c3 = 'Z', c4 = 'M';
    cout << "char: Min(" << c3 << ", " << c4 << ") = ";
    Min(c3, c4);

    return 0;
}