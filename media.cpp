#include <iostream>

int main()
{
    int soma = 6;
    int variavel = 3;
    int qtd = 50;

    float media;

    for (size_t contador = 0; contador < qtd; contador++)
    {
        soma += variavel;
    }
    media = (static_cast<float>(soma)/ qtd);
    
    std::cout << media;
}