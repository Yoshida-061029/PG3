#include <iostream>
#include <windows.h>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& name) : name(name) {}

    virtual void Speak() {
        std::cout << name << "は鳴きます。" << std::endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}

    void Speak() override {
        std::cout << name << "は「ワン!」と吠えます。" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}

    void Speak() override {
        std::cout << name << "は「ニャー」と鳴きます。" << std::endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);

    Animal* animals[3];
    animals[0] = new Dog("ポチ");
    animals[1] = new Cat("ミケ");
    animals[2] = new Animal("名無し");

    for (int i = 0; i < 3; i++) {
        animals[i]->Speak();
    }

    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }

    return 0;
}