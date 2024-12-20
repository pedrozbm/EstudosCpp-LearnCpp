#include <iostream>
#include <array>

template <std::size_t N>
void passByRef(const std::array<int, N>& arr)// nao aceita CTAD
{
    static_assert(N !=0);

    std::cout << arr[0] << '\n';
}

int main(){
    std::array<int, 5> arr{ 9, 7, 5, 3, 1};
    passByRef(arr);

    std::array<int, 5> arr2{ 1, 2, 5, 3, 1};
    passByRef(arr2);

    std::array<double, 5> arr3{ 1.2, 3.4, 5.6, 7.8, 8.9 };
    passByRef(arr3); // compilador nao encontra a funcao correspondente
    return 0;

}