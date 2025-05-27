#include <iostream>

// Os operadores postivo(+), negativo(-), e lógico(!) são unários
// Que siginifica que eles operam em apenas um operando
// Como são apenas um operando, eles podem ser sobrecarregados como funções membro
// Todos são implementados de forma identica

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents) : m_cents{cents} {};

    Cents operator-() const;

    int getCents() const { return m_cents; }
};

Cents Cents::operator-() const
{
    return -m_cents;
}

int main()
{
    const Cents nickle{5};

    std::cout << "A Niclke of debt is worth " << (-nickle).getCents() << " cents\n";
    // Ele opera no objeto *this, por isso não precisamos passar o objeto como argumento

    return 0;

}

// Há uma continuação com outro código desse tópico ainda, ele está no exercicio 21.6_Ex1.cpp
