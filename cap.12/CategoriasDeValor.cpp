#include <iostream>

int main()
{
    int x{ 5 }; // 5 é uma expressao rvalue, pois tem valor 
    const double d{ 1.2 }; // 1.2 é uma expressao rvalue

    int y { x }; // x is a modifiable lvalue expression, pois não tem valor definido diretamente. 
    const double e { d }; // d is a non-modifiable lvalue expression
    int z { return 5() }; // return5() is an rvalue expression (since the result is returned by value)

    int w { x + 1 }; // x + 1 is an rvalue expression
    int q { static_cast<int>(d) }; // the result of static casting d to an int is an rvalue expression

    //Se vc não tiver certeza que um expressão é 
    //lvalue ou rvalue, tente pegar seu endereço 
    //usando operator&, se compila, a expressao deve
    //ser um lvalue 

    //  int x { 5 };
    // &x;  compiles: x is an lvalue expression
    // &5; doesn't compile: 5 is an rvalue expression
    // &foo();  doesn't compile: foo() is an rvalue expression

}