#include <iostream>
#include <array>
#include <functional>


int main(){
    int x{ 1 };
    int y{ 2 };
    int z{ 3 };

    //reference wrapper referencia o objeto,
    //Portanto, não temos custos com cópias
    std::array<std::reference_wrapper<int>, 3> arr{x ,y, z};
    arr[1].get() = 5;

    std::cout << arr[1] << y << '\n';

    return 0;
}