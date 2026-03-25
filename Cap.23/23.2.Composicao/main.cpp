#include <string>
#include <iostream>
#include "creature.hpp"
#include "point2d.h"

int main()
{
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature{name, {4, 7}};

    while (true)
    {
        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x{0};
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creture (-' to quit): ";
        int y{0};
        std::cin >> y;
        if (y == -1)
            break;

        creature.moveTo(x, y);
    }

    return 0;
}