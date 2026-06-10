#include <iostream>
#include <string>


class Enemy {
public:
   
    using StateFunc = void (Enemy::*)();

    Enemy() : stateName_("接近"), stateFunc_(&Enemy::StateApproach) {}

 
    void Update() {
        (this->*stateFunc_)();
    }

private:
    std::string stateName_;
    StateFunc   stateFunc_;

 
    void StateApproach() {
        std::cout << "[敵の状態] " << stateName_ << " : 敵がプレイヤーに近づいている..." << std::endl;
   
        stateName_ = "射撃";
        stateFunc_ = &Enemy::StateShoot;
    }

  
    void StateShoot() {
        std::cout << "[敵の状態] " << stateName_ << " : 敵が射撃している！" << std::endl;
     
        stateName_ = "離脱";
        stateFunc_ = &Enemy::StateRetreat;
    }

    
    void StateRetreat() {
        std::cout << "[敵の状態] " << stateName_ << " : 敵が離脱している..." << std::endl;
      
        stateName_ = "接近";
        stateFunc_ = &Enemy::StateApproach;
    }
};

int main() {
    Enemy enemy;

    std::cout << "=== 敵の状態遷移デモ ===" << std::endl;

    for (int i = 0; i < 9; i++) {
        enemy.Update();
    }

    return 0;
}