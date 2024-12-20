#include <iostream>
#include "C:\Repositorios\Estudos\c++\Cap.8\Random.h"

class Monster
{
public:
    enum Type
    {
        Dragao,
        Globin,
        Ogre,
        Orc,
        Esqueleto,
        Troll,
        Vampiro,
        Zumbi,
        MaxMonsterType
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_rugido{};
    int m_ptsVida{};

public:
    Monster(Type type, std::string name, std::string rugido, int ptsVida) : m_type{type}, m_name{name}, m_rugido{rugido}, m_ptsVida{ptsVida}
    {
    }

    static std::string getTypeString(const Monster::Type &tipo)
    {
        switch (tipo)
        {
        case Dragao:
            return "Dragão";
        case Globin:
            return "Globin";
        case Ogre:
            return "Ogre";
        case Orc:
            return "Orc";
        case Esqueleto:
            return "Esqueleto";
        case Troll:
            return "Troll";
        case Vampiro:
            return "Vampiro";
        case Zumbi:
            return "Zumbi";

        default:
            return "????";
        }
    }

    void print() const
    {
        std::cout << "O " << getTypeString(Monster::m_type) << " " << m_name;
        if (m_ptsVida > 0)
            std::cout << ", tem " << m_ptsVida << " e diz " << m_rugido << '\n';
        else
            std::cout << ", esta morto " << '\n';
    }
};

namespace MonsterGenerator
{

    std::string getName(int randomNumber)
    {
        switch (randomNumber)
        {
        case 1:
            return "Ronaldo fenomeno";

        case 2:
            return "Craque neto";

        case 3:
            return "Casagrande";

        case 4:
            return "Fagner";

        case 5:
            return "DEPAY";

        default:
            return "????????";
        }
    }
    std::string getRoar(int randomNumber)
    {
        switch (randomNumber)
        {
        case 1:
            return "arfgh \n";

        case 2:
            return "vai curintia \n";

        case 3:
            return "Eu gosto de batata";

        case 4:
            return "QUERO CAFEEEEEEE";

        case 5:
            return "MAS O CE EH CRAQUE? ";

        default:
            return "????????";
        }
    }
    Monster generate()
    {
        Monster monster{static_cast<Monster::Type>(Random::get(0, Monster::MaxMonsterType -1)),
                        getName(Random::get(1, 5)),
                        getRoar(Random::get(1, 5)),
                        Random::get(0, 100)};

        return monster;
    }
}

int main()
{
    Monster skeleton{Monster::Esqueleto, "Bones", "*rattle*", 4};
    skeleton.print();

    Monster vampire{Monster::Vampiro, "Nibblez", "*hiss*", 0};
    vampire.print();

    Monster monster{MonsterGenerator::generate()};
    monster.print();

    return 0;
}