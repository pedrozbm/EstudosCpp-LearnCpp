#include <iostream>

// Qualquer operador existente em c++ pode ser sobrecarregado. exceto:
// condicional (?:) ;
// sizeof, escopo (::) ;
// member selector  (.)

// Só pode-se criar operadores que já existem, não podemos sobrecarregar ** por exemplo 



int main()
{
    int x{2};
    int y{3};
    std::cout << x + y << '\n';
    // std::cout << 4 + 3^2 << '\n';
    
}