#include <iostream>
#include <algorithm> // lib com os algoritimos
#include <array>
#include <string>

// A lib padrao já inclui algoritimos eficientes para pesquisar, contar e agrupar
// Inspetores: Visualiza mas nao modifica
// Mutuadores: Modificam dados do conteiner
// Facilitadores: Geram resultados baseados nos membros de dados

bool contemString(std::string str)
{

    return str.find("elan") != std::string::npos;
}
void dobraNumero(int &i){
    i *= 2;
}

int main()
{

    std::array<int, 6> arr{13, 90, 9, 5, 40, 80};

    std::cout << "Valor para encontrar e mudar: ";
    int pesquisa{};
    int renomear{};
    std::cin >> pesquisa >> renomear; // usuario digita o elemento

    auto encontrado{std::find(arr.begin(), arr.end(), pesquisa)}; // encontramos o elemento, find() retorna um iterador apontando para o elemento;
    if (encontrado == arr.end())
    {
        std::cout << "nao encontrado" << pesquisa << '\n';
    }
    else
    {
        *encontrado = renomear;
    }
    for (int i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // Usando find_if()
    //find_if funciona da mesma forma, porém aceita objetos chamaveis
    std::array<std::string, 4> arrStrings{"maca", "peraelan", "abacaxi", "melancia"};

    auto procuraPalavra{std::find_if(arrStrings.begin(), arrStrings.end(), contemString)};
    //usando cont e cont_if para contar ocorrencias 
    auto elan{std::count_if(arrStrings.begin(), arrStrings.end(), contemString)};
    
    if (procuraPalavra == arrStrings.end())
    {
        std::cout << "nao encontrado";
    }
    else
    {
        std::cout << "Encontrado " << *procuraPalavra << '\n';
    }
    std::cout << "Contado: " << elan << '\n';    

    // usando for_each para fazer algo com todos os elementos de um conteiner
    std::for_each(arr.begin(), arr.end(), dobraNumero);
    //também permite pular elementos
    // std::for_each(std::next(arr.begin()), arr.end(), dobraNumero); // aqui pulamos o primeiro elemento

    for(int i : arr){
        std::cout << i <<' ';
    }
    std::cout << '\n';

    return 0;
}