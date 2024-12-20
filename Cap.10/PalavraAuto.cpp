#include <iostream>
#include <typeinfo>

///Dedução de tipo; Ao definir uma variavel
// a dedução de tipo pode ser invocada atraves 
// da palavra auto

auto foo(){
    return 5;
}
main(){
auto teste {5.0}; // é um double literal, é uma dedução de tipo 
auto soma {1 + 2}; // deduz ser um inteiro 
// Não funciona com variaveis vazias
std::cout << typeid(soma).name() << std::endl; 
std:: cout << foo() << std::endl;
return 0;

}
