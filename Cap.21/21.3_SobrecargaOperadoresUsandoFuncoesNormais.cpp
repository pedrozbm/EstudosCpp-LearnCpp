#include <iostream>

// Para sorecarregar os operadores usando funções normais,
// Precisamos de metodos get em nossa classe
// Para obter os valores dos atributos privados
class Cents
{
private:
  int m_cents{};

public:
  Cents(int cents)
    : m_cents{ cents }
  {}

  int getCents() const { return m_cents; }
};

// nota: esta função não é uma função membro nem uma função amiga!
Cents operator+(const Cents& c1, const Cents& c2)
{
// use o construtor de Cents e o operador+(int, int)
// não precisamos de acesso direto aos membros privados aqui
  return Cents{ c1.getCents() + c2.getCents() };
}

int main()
{
  Cents cents1{ 6 };
  Cents cents2{ 8 };
  Cents centsSum{ cents1 + cents2 };
  std::cout << "I have " << centsSum.getCents() << " cents.\n";

  return 0;
}