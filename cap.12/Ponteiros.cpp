#include <iostream>

main(){

    int x{5};

    std::cout<< &x << '\n';// exibe o endereço da var 
    std::cout<< *(&x) << '\n'; // esse é um operador de desreferencia 
    //ele exibe a var guardada no endereço 
    
    int* ptr{&x}; // incializa o ponteiro com o endereço da var x
    std::cout<< *ptr << '\n';// exibe o endereço da var 

    *ptr = 6; // altera o valor da variavel pelo ponteiro 

    std::cout << x << '\n';
    int y {8};
    ptr = &y; // muda para onde o ponteiro está apontando
    std::cout<< *ptr << '\n';

}