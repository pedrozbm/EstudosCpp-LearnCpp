#include <iostream>
#include <vector>

template <typename T>
bool isValueArray(std::vector<T> &arr, T value)
{
    bool found{false};

    for (const auto &num : arr)
    {
        if (value == static_cast<std::string>(num))
        {
            found = true;
        }
    }
    if (found)
    {
        std::cout << value << " encontrado \n";
        return found;
    }
    else
    {
        std::cout << " não encontrado";
        return found;
    }
}

int main()
{
    std::vector<std::string> nomes{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string nomeUser{};

    std::cout << "entre com o nome: ";
    std::cin >> nomeUser;

    isValueArray(nomes, nomeUser);

    // for(const auto& num: nomes){
    //     if(nomeUser == static_cast<std::string>(num)){
    //         std::cout << nomeUser << " encontrado \n";
    //         return 0;
    //     }
    // }
    // std::cout << nomeUser << " Nao foi encontrada";
}