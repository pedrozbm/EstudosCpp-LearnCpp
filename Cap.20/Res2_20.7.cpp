#include <iostream>
#include <array>
#include <algorithm>

struct Car
{
    std::string montadora{};
    std::string modelo{};
};

int main()
{
    std::array<Car, 3> cars{
        {
            {"Volksvagen", "Golf"},
            {"Toyota", "Corolla"},
            {"Honda", "Civic"},
        }};
    int comparar{0};
    // Esse exemplo usa uma lambda para contar quantas comparacoes são feitas 
    // no sort para reclassificar a matriz

    std::sort(cars.begin(), cars.end(), 
    [&comparar](const auto& a, const auto& b){ // Vale lembrar que podemos capturar mais de uma var: [comparar, outraVar, maisUmaVar](){}
        ++comparar;

        return a.montadora < b.montadora;
    });


    std::cout << "comparacoes: " << comparar << '\n';

    for(const auto& Car: cars){
        std::cout << Car.montadora << ' ' << Car.modelo << '\n';
    }

    return 0;
}