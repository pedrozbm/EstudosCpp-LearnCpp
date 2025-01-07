#include <array>
#include <cstddef>
#include <iostream>

//Iterador eh um objeto projetado para percorrer 
// um conteiner


int main(){
    std::array<int, 7> data{0, 1, 2, 3, 4, 5, 6};
    std::size_t length {sizeof(data) / sizeof(data[0])};

    std::size_t index {0 };
    while (index < length){
        std::cout << data [index] << ' ';
        ++index;
    }
    std::cout << '\n';

    for(auto ptr { &data[0]}; ptr != (&data[0] + length); ++ptr){
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    for (int i : data){
        std::cout << i << ' ';
    }
    std::cout << '\n';

    //Ponteiro como iterador:
    
    auto begin { &data[0]};
    auto end {begin + (sizeof(data)/ sizeof(data[0]))};
    for(auto ptr{begin}; ptr != end; ++ptr){
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    return 0; 
}