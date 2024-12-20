#include <iostream>

class Fruit{
    public:

        enum Type
        {
            apple,
            banana, 
            cherry
        };
    
    private:
        Type m_type{};
        int m_percentageEaten{0};
    public:
        Fruit(Type type):
        m_type{type}
        {            
        }
    
    Type getType(){return m_type;}
    int getPercentageEaten(){return m_percentageEaten;}

    bool isCherry(){return m_type == cherry;}
};
int main(){
    Fruit apple {Fruit::apple};
    if(apple.getType() == Fruit::apple)
        std::cout << "I am an apple";
    else
        std::cout << "I am not an apple";

    return 0;
}