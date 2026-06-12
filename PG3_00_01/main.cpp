#include <iostream>
#include <cmath>
#include <windows.h>

#define M_PI 3.14159265358979323846

// 抽象クラス
class IShape {
public:
    virtual double Size() const = 0;
    virtual void Draw() const = 0;
    virtual ~IShape() {}
};

// 円クラス
class Circle : public IShape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double Size() const override {
        return M_PI * radius * radius;
    }

    void Draw() const override {
        std::cout << "円の面積: " << Size() << std::endl;
    }
};

// 矩形クラス
class Rect : public IShape {
private:
    double width;
    double height;

public:
    Rect(double width, double height) : width(width), height(height) {}

    double Size() const override {
        return width * height;
    }

    void Draw() const override {
        std::cout << "矩形の面積: " << Size() << std::endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);

    IShape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rect(4.0, 6.0);

    for (int i = 0; i < 2; i++) {
        shapes[i]->Draw();
    }

    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}