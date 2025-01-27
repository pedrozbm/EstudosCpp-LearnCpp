//Vamos rever o algoritimo feito em 18.3 - biblioteca padrao

#include <iostream>
#include <algorithm> // lib com os algoritimos
#include <array>
#include <string>

bool contemString(std::string str)
{

    return str.find("elan") != std::string::npos;
}

int main()
{   // Lambdas assumem a seguinte forma:
    // [clausula de captura] (parametros) -> returnType
    // {
    //     declaracoes
    // }

    std::array<std::string, 4> arrStrings{"maca", "peraelan", "abacaxi", "melancia"};

    // Definimos a função exatamente onde a usamos: 
    auto procuraPalavra{std::find_if(arrStrings.begin(), arrStrings.end(),
            [](std::string str){
                return str.find("elan") != std::string::npos;
    })};
    // nao sabemos o tipo de uma lambda

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

    
    return 0;
}