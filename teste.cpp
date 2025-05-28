#include <iostream>

int main()
{

    int raio_roldana{144};
    int resolucao{360};

    double centimetros_por_pulso = (((raio_roldana / 10.0f) * 3.14159) / resolucao);
    std::cout << centimetros_por_pulso << "\n";

    float raioDvi = raio_roldana / 10;
    // raioDvi = raio_roldana;

    std::cout << raioDvi << "\n";

    float res = (raioDvi * 3.14159);
    std::cout << res << "\n";

    float resposta = (res / resolucao);

    float teste = resposta * 3600;

    std::cout << teste;
}