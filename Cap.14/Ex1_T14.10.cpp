#include <iostream>

class Ball
{
private:
    std::string m_color;
    double m_raio;
public:
    Ball(std::string color, double raio): 
    m_color{color},
    m_raio{raio}    
    {
    }
    std::string getColor() const{return m_color;};
    double getRaio() const {return m_raio;}
    
};

void print(const Ball& ball){
        std::cout << "Bola (" << ball.getColor() << ", " << ball.getRaio() << ") \n"; 
    }


int main(){
    Ball blue {"blue", 10.0};
    print(blue);

    Ball red{"red", 12.0};
    print(red);

    return 0;
}