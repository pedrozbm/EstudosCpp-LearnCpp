#include <iostream>

void printArray(const int array[])
{
    for (const auto &element : array)
    {
        std::cout << element << ' ';
    }
}

int main()
{
    int array[5] { 9, 7, 5, 3, 1 };

    printArray(array);

    std::cout << '\n';

    return 0;
}