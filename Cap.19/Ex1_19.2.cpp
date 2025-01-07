#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

size_t tamanhoArr(){
    std::cout << "Quantos nomes voce deseja inserir? " << '\n';
    std::size_t tamanho{};
    std::cin >> tamanho;
    return tamanho;
}
void nome(std::string* nomes ,size_t tamanho){

    for(int i{0}; i < static_cast<int>(tamanho); i++){
        std::cout << "Nome #" << i << ": " ;
        std::cin >> nomes[i];
    }
}
void imprimeNomes(int tamanho, std::string* nomes){
    std::cout << "Aqui esta a lista ordenada: \n"; 
    for(int i{0}; i < tamanho; i++){
        std::cout << "Nome #" << i << ": " ;
        std::cout << nomes[i] << '\n';
    }   
}

int main(){
    
    std::size_t tamanho{ tamanhoArr() };

    std::string* nomes{new std::string [tamanho]{}};   

    nome(nomes, tamanho);

    std::sort(nomes, nomes + tamanho);

    imprimeNomes(tamanho, nomes);

}