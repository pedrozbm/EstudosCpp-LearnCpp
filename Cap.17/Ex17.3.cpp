#include <iostream>
#include <array>

template <std::size_t N, typename T>
void printArray(const std::array<T, N>& arr){

    std::cout << "A matriz ( " ;

    auto separator {""};
    for(auto j : arr){
        std::cout << separator << j;
        separator = {", "};
    }
    std::cout << ") tem comprimento " << N <<'\n';

}


int main(){

    constexpr std::array<int, 4> arr1 {1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array<char, 5> arr2 {'h', 'e', 'l', 'l', 'o'};
    printArray(arr2);

    return 0;
}