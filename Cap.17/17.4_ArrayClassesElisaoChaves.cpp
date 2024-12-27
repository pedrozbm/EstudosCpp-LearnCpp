#include <iostream>
#include <array>

struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};


int main(){
    std::array<House, 3> houses{};

    houses[0] = {13, 1, 7};
    houses[1] = {14, 2, 5};
    houses[2] = {15, 2, 4};
    // Podemos usar o CTAD para fazer a inicializacao
    // constexpr std::array<House, 3> houses{
    //     {
    //         {13, 4, 30},
    //         {14, 3, 10},
    //         {15, 3, 40},
    //     }
    // };

    for(const auto& house: houses){
        std::cout << "House number " << house.number
                << " has " << (house.stories *house.roomsPerStory)
                << " rooms. \n";
    }

    return 0;
}