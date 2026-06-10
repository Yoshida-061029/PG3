#include <iostream>
#include <windows.h>

template <typename T1, typename T2>
class Comparer {
public:
    
    T1 Min(T1 a, T2 b) {
        return (a < static_cast<T1>(b)) ? a : static_cast<T1>(b);
    }
};

int main() {
    SetConsoleOutputCP(65001);

    Comparer<int, int> c1;
    std::cout << "[int,    int   ] Min(3, 5)       = " << c1.Min(3, 5) << std::endl;

    Comparer<float, float> c2;
    std::cout << "[float,  float ] Min(1.5f, 2.5f) = " << c2.Min(1.5f, 2.5f) << std::endl;

    Comparer<double, double> c3;
    std::cout << "[double, double] Min(3.14, 2.71) = " << c3.Min(3.14, 2.71) << std::endl;

    Comparer<int, float> c4;
    std::cout << "[int,    float ] Min(4, 3.7f)    = " << c4.Min(4, 3.7f) << std::endl;

    Comparer<int, double> c5;
    std::cout << "[int,    double] Min(7, 6.99)    = " << c5.Min(7, 6.99) << std::endl;

    Comparer<float, double> c6;
    std::cout << "[float,  double] Min(1.1f, 1.05) = " << c6.Min(1.1f, 1.05) << std::endl;

    return 0;
}