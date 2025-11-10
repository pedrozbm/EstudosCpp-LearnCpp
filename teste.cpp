#include <iostream>
#define CONVERTER_CM_METROS 0.01f

int main()
{
    double Pi = 3.14159265359;
    double raio_roldana{100};
    double resolucao{360};
    int metrosEsticados_f = 27;



    double perimetro_f         = ((raio_roldana / 10.0f) * Pi);
    std::cout << perimetro_f << '\n';

    double distanciaPorPulso_f = perimetro_f / resolucao;
    std::cout << distanciaPorPulso_f << '\n';

    long pulsos_long               = metrosEsticados_f * (distanciaPorPulso_f / CONVERTER_CM_METROS);

    std::cout << pulsos_long << '\n';

}