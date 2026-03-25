#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
// #include <string_view>
#include "point2d.h"

class Creature{
    private: 
        std::string m_name;
        Point2D m_location;

    public:
        enum class Sinal{
            batata = 0,
            abacaxi
        };
        Sinal sinal;
        Creature(std::string name, const Point2D& location): m_name{name}, m_location {location}{}

        friend std::ostream& operator<<(std::ostream&out, const Creature& creature){
            out << creature.m_name << " is at " << creature.m_location;
            return out;
        }
    
        void moveTo(int x, int y){
            m_location.setPoint(x, y);
        }
};
/*
Creature também usa composição em suas partes, o nome e a localização tem um progenitor,
e seus tempos de vida estão ligados ao da creature.

*/

#endif