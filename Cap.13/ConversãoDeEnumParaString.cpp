#include <iostream>
#include <string>

enum Color
{
    red,
    green,
    blue,
};

constexpr char* getColorName(Color color){
    switch (color)
    {
    case red:
        return "red";
    
    case green:
        return "green";
    
    case blue:
        return "blue";

    default:
        break;
    }
}

int main()
{
    constexpr Color shirt{blue};

    std::cout << "Your shirt is " << getColorName(shirt) << '\n'; 

    return 0;
}