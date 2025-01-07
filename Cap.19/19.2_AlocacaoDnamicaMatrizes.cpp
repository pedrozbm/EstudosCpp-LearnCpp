#include <iostream>
#include <cstddef>

// Podemos alocar arrays dinamicamente, o que permite escolher 
// O tamanho do array em tempo de execução
// Este algoritimo aloca no estilo C

int main(){
    std::cout << "Entre com um positivo inteiro: ";
    std::size_t length;
    std::cin >> length;

    int* array {new int [length]{}};

    //Podemos inicializar um array dinamico com inicializadores
    int* arr{new int[5]{9, 7,5,3,1}};
    //declarar explicitamente o tamanho da matriz é opcional
    
    std::cout << "Eu aloquei uma matriz de comprimento: " << length << '\n';

    array[0] = 5;

    delete[] array;
    // Para arrays usamos delete[]
    
    return 0;
}