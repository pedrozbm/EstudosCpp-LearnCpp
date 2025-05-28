#include <iostream> 
// Existem maneiras diferentes de sobrecarregar operadores em C++
// Uma delas é usando funções amigas (friend functions).
// Uma função amiga é uma função que não é membro de uma classe, mas tem acesso aos membros privados e protegidos dessa classe.
// Isso é útil quando você deseja sobrecarregar um operador que envolve dois objetos de diferentes classes ou quando você não quer tornar a função um membro da classe.

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents) : m_cents{cents} {};

    // Aqui estamos sobrecarregando o operador +, que é um operador binário
    friend Cents operator+(const Cents& c1, const Cents& c2);

    friend Cents operator-(const Cents& c1, const Cents& c2);

    int getCents() const {return m_cents;}    
};

Cents operator+(const Cents& c1, const Cents& c2){
    return c1.m_cents + c2.m_cents;
}

Cents operator-(const Cents& c1, const Cents& c2){
    return c1.m_cents - c2.m_cents;
}   

int main()
{   
    Cents cents1 {6};
    Cents cents2{8};
    Cents centsSum{cents1 + cents2};
    Cents centsSub{cents1 - cents2}; // Aqui estamos usando a sobrecarga do operador -
    Cents centsMultply{cents1 * cents2}; // Note que por não sobrecarregaramos o operador, temos erro.
    // Lembrar também que a ordem dos parametros importa
    // Se fizermos Cents centsSum{cents1 + 2}; não vai funcionar, pois não existe sobrecarga para o operador + com um inteiro.
    // Para isso, teriamos que fazer uma sobrecarga do operador + para o tipo inteiro também.

    std::cout << "I have " << centsSum.getCents() << " cents. \n";

    return 0;
}