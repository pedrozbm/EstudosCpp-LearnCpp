#include <iostream>

enum class Animal
{
    porco,
    galinha,
    cabra,
    gato,
    cachorro,
    pato,
};

std::string GetAnimalName(Animal animal)
{

    switch (animal)
    {
    case Animal::porco:
        return "porco";

    case Animal::galinha:
        return "galinha";

    case Animal::cabra:
        return "cabra";

    case Animal::gato:
        return "gato";

    case Animal::cachorro:
        return "cachorro";

    case Animal::pato:
        return "pato";

    default:
        return "Animal não existe";
    }
}
int printNumberOfLegs(Animal animal)
{
    switch (animal)
    {
    case Animal::porco:
    case Animal::cabra:
    case Animal::gato:
    case Animal::cachorro:
    case Animal::pato:
        return 4;
    case Animal::galinha:
        return 2;

    default:
        return 0;
    }
}

int main()
{
    std::cout << "Um " << GetAnimalName(Animal::gato) << " tem " << printNumberOfLegs(Animal::gato) << " patas";
}