#include <iostream>
#include <string>

class Ball{
    private: 
        std::string m_color{"black"};
        double m_raio{10.0};

    public:

        std::string getColor(std::string color)const {return m_color;};
        double getRaio(double raio)const {return m_raio;};

        Ball(){
            std::cout << m_color <<", " << m_raio << "\n";
        }
        Ball(std::string cor):m_color{cor}{
            std::cout << m_color <<", " << m_raio << "\n";
        }
        Ball(double raio):m_raio{raio}{
            std::cout << m_color <<", " << getRaio(raio) << "\n";
        }
        Ball(std::string cor, double raio):m_color{cor}, m_raio{raio}{
            std::cout << getColor(m_color) <<", " << getRaio(raio) << "\n";          
        }
};

int main(){
    Ball def{};
    Ball blue{"blue"};
    Ball twenty{20.0};
    Ball blueTwenty{"blue", 20.0}; 

}