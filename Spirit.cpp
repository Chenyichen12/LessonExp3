//
// Created by 陈依澄 on 2023/11/27.
//

#include "Spirit.h"

using namespace std;
int Spirit::number = 0;
int Spirit::aliveNumber = 0;

Spirit::Spirit() {
    name = "未命名";
    x = 0;
    y = 0;
    health = 1000;
    aliveState = true;
    number++;
    aliveNumber++;
}

Spirit::Spirit(string name, int x, int y) {
    this->name = name;
    this->x = x;
    this->y = y;
    health = 1000;
    aliveState = true;
    number++;
    aliveNumber++;
}

bool Spirit::takeDamage(int damage) {
    if (aliveState) {
        if (health > damage) {
            health -= damage;
            return true;
        } else {
            health = 0;
            aliveState = false;
            aliveNumber--;
            return true;
        }
    } else {
        return false;
    }
}

bool Spirit::setPosition(int x, int y) {
    if (x <= 200 && x >= 0 && y <= 200 && y >= 0) {
        this->x = x;
        this->y = y;
        return true;
    } else {
        return false;
    }
}

int Spirit::getPositionX() {
    return this->x;
}

int Spirit::getPositionY() {
    return this->y;
}

std::string Spirit::getName() {
    return this->name;
}

int Spirit::getHealth() {
    return this->health;
}

int Spirit::getNumber() {
    return Spirit::number;
}

int Spirit::getAliveNumber() {
    return Spirit::aliveNumber;
}

void Spirit::getInfo() {
    cout << "该精灵的信息如下" << '\n'
         << "姓名:" << this->name << '\n'
         << "生命值:" << this->health << '\n'
         << "生存状态:" << (this->aliveState ? "存活" : "死亡") << '\n'
         << "坐标:" << this->x << ',' << this->y << '\n';
}

