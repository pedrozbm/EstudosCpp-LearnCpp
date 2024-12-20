#include <iostream>
#include <vector>

void printCapLen(const std::vector<int> v){
    std::cout << "Capacity: " << v.capacity() << " Length:" << v.size() << '\n';
}

int main(){

    std::vector<int> v{0, 1, 2};
    printCapLen(v);

    for(auto i: v){
        std::cout<< i << ' ';
    }
    std::cout << '\n';

    v.resize(5); // Realocação -> É um processo caro, pois copia os valores do vetor para um
    //novo endereço

    printCapLen(v);

    for(auto i:v)   
        std::cout<< i <<' ';
    
    std::cout << '\n';

    // Redimensionar um vetor para ser menor, diminuirá seu comprimento,
    //não capacidade, Para resolver, temos shrink_to_fit(), (cpp 20)

    return 0;
}