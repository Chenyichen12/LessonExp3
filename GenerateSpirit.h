//
// Created by 陈依澄 on 2023/11/27.
//

#ifndef LESSONEXP3_GENERATESPIRIT_H
#define LESSONEXP3_GENERATESPIRIT_H

#include "Spirit.h"

class GenerateSpirit {
private:
    Spirit spirits[10];
    int spiritNumber;
public:
    GenerateSpirit(Spirit [10]);

    GenerateSpirit();

    void takeDamages();

    void takeDamage(int index);

    void addASpirit();

    void moveASpirit(int index);

    void printAllSpirt();

    void showAllSpirits();
    void moveSomeSpirits();
};


#endif //LESSONEXP3_GENERATESPIRIT_H
