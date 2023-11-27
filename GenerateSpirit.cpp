//
// Created by 陈依澄 on 2023/11/27.
//

#include "GenerateSpirit.h"

GenerateSpirit::GenerateSpirit() {
    this->spiritNumber = 0;
    for (int i = 0; i < 10; ++i) {
        std::string thisNamr = "";
        char name = (char) (rand() % 26 + 'a');
        thisNamr.push_back(name);
        int x = rand() % 200;
        int y = rand() % 200;
        spirits[spiritNumber++] = Spirit(thisNamr, x, y);
    }
}

void GenerateSpirit::takeDamages() {
    for (int i = 0; i < 10; ++i) {
        int index = (int) rand() % 10;
        int damage = (int) rand() % 1000;
        this->spirits[index].takeDamage(damage);
//        std::cout << "对精灵" << spirits[index].getName() << "进行伤害为" << damage << "的攻击";
//        bool a = this->spirits[index].takeDamage(damage);
//        if (a && this->spirits[index].getHealth() == 0) {
//            printAllSpirt();
//        }
    }
}


void GenerateSpirit::printAllSpirt() {
    //需要获得全部精灵的位置，y高的排在前面，相同的话比较x，x小的排在前面
    system("clear");
    Spirit temp[10]; // 选择排序
    memcpy(temp, spirits, sizeof(spirits));
    for (int i = 0; i < spiritNumber - 1; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (temp[i].getPositionY() / 10 < temp[j].getPositionY() / 10) {
                std::swap(temp[i], temp[j]);
            } else if (temp[i].getPositionY() / 10 == temp[j].getPositionY() / 10) {
                if (temp[i].getPositionX() > temp[j].getPositionX()) {
                    std::swap(temp[i], temp[j]);
                }
            }
        }

    }
    //200x200的范围画布有限，在就压缩成20x20
    int ysuojin = 20 - (temp[0].getPositionY() / 10 + 1);
    for (int i = 0; i < ysuojin; ++i) {
        std::cout << '\n';
    }
    for (int i = 0; i < spiritNumber; ++i) {
        int y = temp[i].getPositionY();
        for (int j = 0; j < (20 - (y / 10 + 1)) - ysuojin; ++j) {
            std::cout << '\n';
        }
        ysuojin = 20 - (y / 10 + 1);
        int index = 0;
        int j = i;
        while (temp[j].getPositionY() / 10 == temp[i].getPositionY() / 10) {
            index++;
            j++;
        }
        int suojin = temp[i].getPositionX() / 10;
        for (int k = 0; k < temp[i].getPositionX() / 10; ++k) {
            std::cout << '\t';
        }
        for (int k = 0; k < index; ++k) {
            int x = temp[k + i].getPositionX() / 10 - suojin;
            suojin += x;
            for (int l = 0; l < x; ++l) {
                std::cout << '\t';
            }
            if (temp[k + i].getHealth() != 0) {
                std::cout << '*';
            }
        }
    }
}

void GenerateSpirit::addASpirit() {
    char name[] = {(char) (rand() % 26 + 'a')};
    int x = rand() % 200;
    int y = rand() % 200;
    spirits[spiritNumber++] = Spirit(std::string(name), x, y);
    printAllSpirt();
}

void GenerateSpirit::moveASpirit(int index) {
    int x = rand() % 200;
    int y = rand() % 200;
    spirits[index].setPosition(x, y);
    printAllSpirt();
}

void GenerateSpirit::takeDamage(int index) {
    if (index < 0 || index > spiritNumber) {
        std::cout << "不在范围内" << '\n';
        return;
    }
    int damage = (int) rand() % 1000;

    bool a = this->spirits[index].takeDamage(damage);
    if (a && this->spirits[index].getHealth() == 0) {
        printAllSpirt();
        std::cout << '\n' << "对精灵" << spirits[index].getName() << "进行伤害为" << damage << "的攻击";
    } else {
        if (spirits[index].getHealth() == 0) {
            std::cout << "这只精灵HP已经为0辣" << '\n';
        } else {
            std::cout << "对精灵" << spirits[index].getName() << "进行伤害为" << damage << "的攻击";
        }
    }
}

void GenerateSpirit::showAllSpirits() {
    std::cout << '\n';
    for (int i = 0; i < spiritNumber; ++i) {
        spirits[i].getInfo();
        std::cout << '\n';
    }
}