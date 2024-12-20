#include <iostream>
#include <array>



int main(){

constexpr std::array<int, 5> prime{2, 3, 5, 7, 11};

std::cout << std::get<3>(prime);

}