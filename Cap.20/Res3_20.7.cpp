#include <iostream>
#include <array>
#include <algorithm>
// As lambdas também possuem capturas padrão
// Podemos usar a ajuda do compilador para gerar automaticamente uma lista de vars
// que precisamos capturar
// Para capturar todas as vars usadas por valor, use um valor de captura =.
// Para capturar todas as vars usadas por ref., use um valor de captura &.

int main()
{
    std::array<int, 5> areas{100, 25, 121, 40, 56};

    int altura{};
    int largura{};

    std::cout << "Entre com altura e largura: ";
    std::cin >> altura >> largura;

    auto found{std::find_if(areas.begin(), areas.end(),
                            [=](int areaConhecida)
                            {
                                return altura * largura == areaConhecida;
                            })};
    // Lambdas tambem permitem declarar uma nova variavel que só é visivel no escopo da lambda
    // Podemos fazer isso definindo uma variável lambda-capture sem especificar seu tipo: 
    
    // auto found{std::find_if(areas.begin(), areas.end(),
    //                         [areaUsuario{ altura * largura }](int areaConhecida)
    //                         {
    //                             return areaUsuario == areaConhecida;
    //                         })};
        
    if ( found == areas.end()){
        std::cout << "Nao conheco essa area :(\n";
    }
    else{
        std::cout << "Area encontrada :)\n";
    }

    return 0; 
}