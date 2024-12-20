#include <iostream>
#include <string>

struct monster
{
    enum monster_type
    {
        ogro,
        dragao,
        orc,
        slime,
    } monster_type;
    int health;
    std::string name;
};

std::string getMonster(monster &mymonster)
{
    switch (mymonster.monster_type)
    {
    case monster::monster_type::ogro:
        return "ogro";
    case monster::monster_type::dragao:
        return "dragao";
    case monster::monster_type::orc:
        return "orc";
    case monster::monster_type::slime:
        return "slime";
    default:
        return "Do not";
    }
}

void printMonster(monster &mymonster)
{
    std::cout << "Type: " << getMonster(mymonster) << '\n';
    std::cout << "Name: " << mymonster.name << '\n';
    std::cout << "health: " << mymonster.health << '\n';

}
int main()
{
    monster ogre{monster::ogro, 145, "Torg"};
    monster slime{monster::slime, 200, "Blurp"};

    printMonster(ogre);
    printMonster(slime);
}