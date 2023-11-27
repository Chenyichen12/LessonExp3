//
// Created by 陈依澄 on 2023/11/27.
//

#ifndef LESSONEXP3_SPIRIT_H
#define LESSONEXP3_SPIRIT_H
#include "iostream"
class Spirit {
private:
    std::string name;
    int x;
    int y;
    int health;
    bool aliveState;
    static int number;
    static int aliveNumber;
public:
    Spirit();
    Spirit(std::string name,int x,int y);
    bool takeDamage(int damage);
    bool setPosition(int x,int y);
    int getPositionX();
    int getPositionY();
    std::string getName();
    int getHealth();
    static int getNumber();
    static int getAliveNumber();
    void getInfo();
};


#endif //LESSONEXP3_SPIRIT_H
