#include <iostream>
#include <array>
//Nao existe uma classe de array bidimensional na biblioteca padrao

template <typename T, std::size_t linha, std::size_t coluna>
using Array2d = std::array<std::array<T, coluna>, linha>;

//Aqui obtemos os tamanhos da linha e coluna:
template <typename T, std::size_t linha, std::size_t coluna>
constexpr int tamanhoLinha(const std::array<std::array<T, coluna>, linha>&arr){
    return linha;
}
template <typename T, std::size_t linha, std::size_t coluna>
constexpr int tamanhoColuna(const std::array<std::array<T, coluna>, linha>&arr){
    return coluna;
}

//podemos usar uma função: 
template <typename T, std::size_t linha, std::size_t coluna>
void printArray(const std::array<std::array<T, coluna>, linha>&arr){
    for(const auto& e: arr){
        for(const auto& t: e){
            std::cout << t << ' ';
        }
        std::cout << '\n';
    }
}



int main(){

//Poderiamos também aproveitar do alias com template criado na linha 6:
// Array2d<int, 3, 4> arr 

std::array<std::array<int, 4>, 3> arr //criamos um array dentro do outro aqui... 
 {{
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
}};
std::cout << tamanhoColuna(arr) << '\n';
std::cout << tamanhoLinha(arr) << '\n';

printArray(arr);

}