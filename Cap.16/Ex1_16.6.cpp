#include <iostream>
#include <vector>
#include <limits>

int getArray()
{
    while (true)
    {

        int x{};
        do
        {
            std::cout << "enter a integer number: ";
            std::cin >> x;
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

        } while (x < 1 || x > 9);

        return x;
    }
}

template <typename T>
void printArray(const std::vector<T> &arr, size_t &length)
{

    for (int index{0}; index < (int)length; ++index)
    {
        std::cout << arr[index] << " ";
    }
}
template <typename T>
int findMax(const std::vector<T> arr)
{
    std::size_t length{arr.size()};

    int num{0};
    for (int index{0}; index < (int)length; ++index)
    {
        if (num < arr[index])
        {
            num = arr[index];
        }

    }
    return num;
}
int main()
{
    std::vector<float> arr{4.4, 6.8, 7, 3, 8, 2, 1, 9};
    std::size_t length{arr.size()};

    std::vector<int> data1 {84, 92, 150, 81, 151};

    std::cout << findMax(data1) << '\n';

    auto x{getArray()};


        for (int index{0}; index < (int)length; ++index)
    {
        if (arr[index] == x)
        {
            printArray(arr, length);
            std::cout << "o Numero " << x << " tem indice " << index;
            return 0;
        }
    }
    std::cout << "O numero não foi encontrado \n";

    return 0;
}