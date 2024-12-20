#include <iostream>
#include <cstddef>
#include <C:\Repositorios\Estudos\c++\Cap.8\Random.h>

int main(){

    std::cout << Random::get(1,6) << '\n' ;
    std::cout << Random::get(1u,6u) << '\n';

    std::cout << Random::get<std::size_t>(1, 6u) << '\n';

    std::uniform_int_distribution <int> die6 {1, 6};
    for (int count {1}; count <= 10; ++count){

        std::cout << die6(Random::mt) << '\t';
    }
    std::cout <<'\n';

    return 0; 
 }