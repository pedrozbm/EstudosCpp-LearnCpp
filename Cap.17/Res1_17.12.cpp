#include <iostream>

int main(){
    constexpr int numLinhas{10};
    constexpr int numColunas{10};

    int produto [numLinhas] [numColunas]{};

    for(std::size_t linha{1}; linha < numLinhas; ++linha){
        for(std::size_t coluna{1}; coluna < numColunas; ++coluna){
            produto [linha] [coluna] = static_cast<int>(linha * coluna);
        }
    }
    for(std::size_t linha{1}; linha < numLinhas; ++linha){
        for(std::size_t coluna{1}; coluna < numColunas; ++coluna){
            std::cout << produto [linha] [coluna] << '\t';
        }
        std::cout << '\n';
    }
}