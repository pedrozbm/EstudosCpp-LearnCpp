#include <iostream>

int getInteger(void)
{
    static bool isFirstCall{true}; // --> obj não destruido ao final da função  

    if (isFirstCall)
    {
        std::cout << "Enter a integer" << std::endl;
        isFirstCall = false;
    }
    else
    {
        std::cout << "enter with other integer" << '\n';
    }

    int i{};
    std::cin >> i;
    return i;
}

int main()
{
    int a{getInteger()};
    int b{getInteger()};

    std::cout << a + b << '\n';
}