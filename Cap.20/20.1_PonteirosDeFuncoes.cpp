#include <iostream>

// Ponteiro é uma var que aponta para um end. 
// Ponteiros de funções, apontam para end. de funções

// funções tem seus proprios enderercos
// quando sao chamadas, a execução salta para o end da funcao
int foo(){ // codigo começa em um end de mem.
    return 5;
}
int goo(){
    return 6;
}
int main(){
    foo(); // Pula para o end

    std::cout << foo << '\n'; // Quando uma funcao é referenciada pelo nome(sem parenteses) 
    // c++ converte em um ponteiro de função.
    // Mas o operador << não sabe como imprimir isso
    // Então foo é converida para bool (Assim << sabe imprimir)
    //Como foo é um ponteiro não nulo, ela é impressa como true
    std::cout << reinterpret_cast<void*>(foo) << '\n'; // podemos verificar o end. dessa forma

    //int (*fncPtr)(); // Ponteiro de uma funcao que nao tem parametros e retorna int 
    // const antes de int, significa que a funcao retorna um const int -> int(*const int foo)()
    int (*fncPtr)(){&foo}; // aponta para foo
    fncPtr = &goo; // Agora aponta para goo
    // O tipo de retorno  
    return 0; 
}