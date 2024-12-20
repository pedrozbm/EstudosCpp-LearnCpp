#include <iostream>

int main(){
    enum class Color{
        red,
        blue,
    };

    enum class Fruit{
        banana,
        apple,
    };
    
    std::cout << color::red << '\n';//nao compila
    
    Color color{Color::blue};

    return 0; 
}