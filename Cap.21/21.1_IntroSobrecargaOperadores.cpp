#include <iostream>
#include <string>

// Qualquer operador existente em c++ pode ser sobrecarregado. exceto:
// condicional (?:) ;
// sizeof, escopo (::) ;
// member selector  (.)

// Só pode-se criar operadores que já existem, não podemos sobrecarregar ** por exemplo

class MyString
{
public:
    std::string s;
};

int main()
{
    int x{2};
    int y{3};

    MyString s1{"Hello"};
    MyString s2{"World"};

    std::cout << x + y << '\n'; // cout já tem uma sobrecarga para o operador + para os tipos

    std::cout << s1 + s2 << '\n'; // Porém não sabe como lidar com tipos definidos pelo usuário

    
}