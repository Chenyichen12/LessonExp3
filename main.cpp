#include "GenerateSpirit.h"

int main() {
    int mode;
    std::cout << "选择模式 1表示手动添加精灵 2表示自动生成精灵" << '\n';
    std::cin >> mode;
    switch (mode) {
        case 1 : {
            Spirit spirit[10];
            for (int i = 0; i < 10; ++i) {
                std::cout << "输入第" << i << "只精灵的名字" << '\n';
                std::string name = "";
                std::cin >> name;
                std::cout << "输入第" << i << "只精灵的x坐标" << '\n';
                int x;
                std::cin >> x;
                std::cout << "输入第" << i << "只精灵的y坐标" << '\n';
                int y;
                std::cin >> y;
                spirit[i] = Spirit(name, x, y);
            }
            GenerateSpirit s = GenerateSpirit(spirit);
            s.takeDamages();
            s.showAllSpirits();
            s.printAllSpirt();
            std::cout << '\n' << "输入要造成伤害的精灵序号" << '\n';
            while (true) {
                int a = 0;
                std::cin >> a;
                s.takeDamage(a);
            }
            break;
        }
        case 2 : {
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
            break;
        }
        default:
            return 0;
    }

}
