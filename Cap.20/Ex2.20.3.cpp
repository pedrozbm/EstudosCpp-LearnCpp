#include <iostream>

int fncRecursiva(int n)
{
    if (n < 10)
        return n;

    return fncRecursiva(n / 10) + n % 10;
}

int main()
{
    std::cout << "Entre com o numero a ser calculado: ";

    int n{0};

    std::cin >> n;

    std::cout << fncRecursiva(n) << '\n';
}
