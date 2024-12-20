#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;
};
Fraction getFraction()
{

    Fraction fraction{};
    std::cout << "Entre com o numerador: " << '\n';
    std::cin >> fraction.numerator;
    std::cout << "Entre com o denominador: " << '\n';
    std::cin >> fraction.denominator;

    return fraction;
}

Fraction multiplicaFraction()
{
    Fraction fraction1{getFraction()};
    Fraction fraction2{getFraction()};
    Fraction fractionResult{fraction1.numerator * fraction2.numerator, fraction1.denominator * fraction2.denominator};
    return fractionResult;
}

void printFractionResult(const Fraction &fractionResult)
{
    std::cout << " As fracoes multiplicadas entre si: " << fractionResult.numerator << " / " << fractionResult.denominator;
}
int main()
{
    printFractionResult(multiplicaFraction());
}