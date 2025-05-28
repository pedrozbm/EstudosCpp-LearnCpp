#include <iostream>
// sobrecarregar os operadores de incremento e decremento é bem simples
//  Devemos lembrar que o operador pode ter 2 variações, o prefixo e o posfixo
// São sobrecarregados exatamente da mesma forma que os operadores unarios

class Digit
{
private:
    int m_digit{};

public:
    Digit(int digit) : m_digit{digit} {}

    // Normamente, funções podem ter o mesmo nome, e serem sobrecarregadas
    // com um numero diferente de argumentos
    // No caso de operadores incremento e decremento prefixado e posfixado
    // eles tem o mesmo numero de argumentos, sã unarios e recebem um parâmetro do mesmo tipo
    // Podemos diferenciar os dois com o parâmetro int:

    Digit &operator++(); // prefixo não tem parâmetro
    Digit &operator--();

    Digit operator++(int); // posfixado tem um parâmetro int
    Digit operator--(int); 

    friend std::ostream &operator<<(std::ostream &out, const Digit &d);
};

Digit &Digit::operator++()
{
    if (m_digit == 9)
        m_digit = 0;
    else
        ++m_digit;

    return *this;
}

Digit &Digit::operator--()
{
    if (m_digit == 0)
        m_digit = 9;
    else
        --m_digit;

    return *this;
}

Digit Digit::operator++(int)
{
    Digit temp{*this}; // cria uma cópia do objeto atual
    ++(*this);        // chama o operador prefixado
    return temp;     // retorna a cópia
}

Digit Digit::operator--(int)
{
    Digit temp{*this}; // cria uma cópia do objeto atual
    --(*this);        // chama o operador prefixado
    return temp;     // retorna a cópia
}

std::ostream &operator<<(std::ostream &out, const Digit &d)
{
    out << d.m_digit;
    return out;
}

int main()
{

    Digit digit { 5 };

    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;

    //Podemos observar aqui que:
    // Forncemos um parametro ficticio inteiro na versão posfixada
    // O parametro forncecido não é usado na implementação do operador
    // nem sequer lhe damos um nome, isso indica para o compilador para tratar
    // a variavel como um espaço reservado. 
    // Observe que os operadores pre e pos fazem a mesma coisa
    // A diferenca está no valor que retornam 
    // Os operadores prefixados retornam o objeto atual, sua implementação é simples
    // Já os pos precisam retornar o objeto antes da operação, por isso criamos uma cópia do objeto atual
    // e retornamos a cópia.
 
    return 0;
}