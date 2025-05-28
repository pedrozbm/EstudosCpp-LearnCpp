#include <iostream>

// Ponteiro é uma var que aponta para um end.
// Ponteiros de funções, apontam para end. de funções

// funções tem seus proprios enderercos
// quando sao chamadas, a execução salta para o end da funcao
int foo()
{ // codigo começa em um end de mem.
    return 5;
}
int fooComArg(int a)
{ // codigo começa em um end de mem.
    return a + 5;
} // o end da funcao é o mesmo, mas o valor do argumento muda
int goo()
{
    return 6;
}
int main()
{
    foo(); // Pula para o end

    std::cout << foo << '\n'; // Quando uma funcao é referenciada pelo nome(sem parenteses)
    // c++ converte em um ponteiro de função.
    // Mas o operador << não sabe como imprimir isso
    // Então foo é converida para bool (Assim << sabe imprimir)
    // Como foo é um ponteiro não nulo, ela é impressa como true
    std::cout << reinterpret_cast<void *>(foo) << '\n'; // podemos verificar o end. dessa forma
    int (*p)() = &foo;

    // int (*fncPtr)(); // Ponteiro de uma funcao que nao tem parametros e retorna int
    //  const antes de int, significa que a funcao retorna um const int -> int(*const int foo)()
    int (*fncPtr)(){&foo}; // aponta para foo
    fncPtr = &goo;         // Agora aponta para goo
    // O tipo de retorno

    // Usando um ponteiro para chamar uma funcao

    int (*fncPtr2)(int){&fooComArg}; // Desferencia explicita 
    (*fncPtr2)(5);    

    std::cout << "Valor do ponteiro de função explicita: " << (*fncPtr2)(5) << '\n'; // 10

    int (*fncPtr3)(int){&fooComArg}; // Desferencia implicita - Alguns compiladores não aceitam isso, mas os modernos devem aceitar
    std::cout <<" valor do ponteiro com função implicita: " <<  fncPtr3(5) << '\n'; 
    
    return 0;
}