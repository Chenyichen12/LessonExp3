#include "GenerateSpirit.h"

int main() {
    GenerateSpirit s = GenerateSpirit();
    s.takeDamages();
    s.showAllSpirits();
    s.printAllSpirt();
    std::cout << '\n' << "输入要造成伤害的精灵序号" << '\n';
    while (true) {
        int a = 0;
        std::cin >> a;
        s.takeDamage(a);
    }
}
