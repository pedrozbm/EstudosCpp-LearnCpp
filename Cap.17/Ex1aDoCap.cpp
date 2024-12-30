#include <iostream>
#include <array>

int main(){ 
    std::array<int, 4> arr{ 0, 1, 2, 3};

    for(std::size_t count {0}; count < std::size(arr); ++count){
        std::cout << arr[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}