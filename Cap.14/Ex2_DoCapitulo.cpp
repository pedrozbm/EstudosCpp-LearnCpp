// https://www.learncpp.com/cpp-tutorial/chapter-14-summary-and-quiz/

#include <iostream>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{1};

public:
    explicit Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator}
    {
    }
    void getFraction()
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> m_numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> m_denominator;
        std::cout << '\n';
    }
    Fraction multiply(const Fraction& temp)const{ 
        return Fraction{m_numerator * temp.m_numerator ,m_denominator * temp.m_denominator};
    }
    void printFraction(){
        std::cout << m_numerator << '\n' << m_denominator << '\n';
    }
};

int main()
{
    Fraction f1{};
    f1.getFraction();
    Fraction f2 {};
    f2.getFraction();

    std::cout << "Fracoes multiplicadas: ";
    f1.multiply(f2).printFraction();

    return 0; 
}