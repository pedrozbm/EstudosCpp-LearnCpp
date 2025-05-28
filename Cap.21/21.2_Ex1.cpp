#include <iostream>

int gcd(int a, int b) {
    return (b == 0) ? std::abs(a) : gcd(b, a % b);
}

class Fraction
{
private:
    int m_numerator{};   // Numerador
    int m_denominator{}; // Denominador

public:
//usamos explicit aqui para evitar conversões automáticas de int para Fraction
// As conversões automaticas podem causar confusão e erros inesperados
// E custam mais processamento
    explicit Fraction(int numerator, int denominator)
        : m_numerator{ numerator }, m_denominator{ denominator } {};
    // Função para imprimir a fração

    void print() const
    {   
        // Reduz a fração antes de imprimir
        Fraction::Reduce(*this);
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }

    friend Fraction operator+(const Fraction& f1, const Fraction& f2)
    {
        // Cria um novo objeto Fraction com o resultado da soma
        return Fraction{ f1.m_numerator * f2.m_denominator + f2.m_numerator * f1.m_denominator,
                         f1.m_denominator * f2.m_denominator };
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2)
    {
        // Cria um novo objeto Fraction com o resultado da multiplicação
        return Fraction{ f1.m_numerator * f2.m_numerator,
                         f1.m_denominator * f2.m_denominator };
    }
    friend Fraction operator*(const Fraction& f, int value)
    {
        // Cria um novo objeto Fraction com o resultado da multiplicação
        return Fraction{ f.m_numerator * value, f.m_denominator };
    }

    friend Fraction operator*(int value, const Fraction& f)
    {
        // Chama o operador * com os argumentos invertidos
        return f * value;
    }

    Fraction Reduce(const Fraction& f) const
    {
        // Reduz a fração ao seu menor termo
        int divisor{ gcd(f.m_numerator, f.m_denominator) };
        return Fraction{ f.m_numerator / divisor, f.m_denominator / divisor };
    }   
};

int main()
{
    // Fraction f1{ 1, 4 }; // Cria um objeto da classe Fraction
    // Fraction f2{ 1, 2 }; // Cria outro objeto da classe Fraction
    // f1.print(); 
    // f2.print(); 
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();


    return 0;
}