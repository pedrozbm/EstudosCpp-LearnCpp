#include <iostream>

// https://pt.stackoverflow.com/questions/10806/para-que-serve-o-construtor-de-c%C3%B3pia-do-c-como-devo-implement%C3%A1-lo
//Uma boa explicação dos conceitos

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator}
    {
    }
    // Copy constructor
    // Fraction(const Fraction& fraction)
    //     // Initialize our members using the corresponding member of the parameter
    //     : m_numerator{ fraction.m_numerator }
    //     , m_denominator{ fraction.m_denominator }
    // {
    //     std::cout << "Copy constructor called\n"; // just to prove it works
    // }
    
    // Fraction(const Fraction& fraction) = delete; // Usado quando não queremos que cópias de objetos sejam criados
    Fraction(const Fraction& fraction) = default; // Se não existir uma declaração de cópia, o compilador irá gerar, mas se mesmo assim quisermos criar, podemos usar default

    void print() const{
        std::cout << "Fraction(" <<m_numerator << ", " << m_denominator <<") \n";
    }
};

int main()
{
    Fraction f{5, 3};
    Fraction fCopy{f}; 
    // Um construtor de cópia é um construtor que é usado para inicializar um objeto
    // com um objeto existente do mesmo tipo. Após o construtor de cópia executar, 
    // o objeto recém-criado deve ser uma cópia do objeto passado como o inicializador.

    f.print();
    fCopy.print();
    }
