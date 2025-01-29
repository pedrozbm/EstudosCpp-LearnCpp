// https://www.learncpp.com/cpp-tutorial/lambda-captures/
#include <iostream>

int main(){

    int municao{10};
    
    auto tiro{
        [municao](){ 
            --municao; // a lambda nao tem permissao para alterar a captura
            // municao é tratado como uma const dentro da lambda, podemos resolver isso usando mutable:
            // [municao]()mutable{

            std::cout << "Pew! " << municao << " shot(s) left. \n"; 
        }
    };
    tiro();
    tiro();

    std::cout<<municao << " tiro(s) sobrando\n"; // observe que aqui o valor ainda é mantido
    // foi alterado apenas na lambda
    // Para capturar o valor por referencia usamos o &:
    // [&municao](){} 

    return 0;
}