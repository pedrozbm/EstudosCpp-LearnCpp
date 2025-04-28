#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using vetor = std::vector<int>;

void calcBinario(vetor& bin, int n)
{
     // vetor para armazenar os digitos do binario

    if (n > 1)              // se n for maior que 1
        calcBinario(bin, n / 2); // chama a funcao recursivamente, dividindo n por 2

    n % 2 == 0 ? bin.push_back(0) : bin.push_back(1); // se o resto da divisao for 0, adiciona 0 ao vetor, se for 1, adiciona 1    
}

int main()
{
    vetor bin{}; // vetor para armazenar os digitos do binario
    std::cout << "Entre com o numero a ser calculado: ";

    int n{0};

    std::cin >> n;

    calcBinario(bin, n); // chama a funcao calcBinario com o numero lido

    
    for (auto i : bin) // percorre o vetor e imprime os digitos do binario
        std::cout << i; // imprime o digito    

    std::cout << "\n"; // pula linha

    return 0;
} // Fim do programa