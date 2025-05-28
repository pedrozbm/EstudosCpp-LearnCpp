#include <iostream>

// No exemplo de sobrecarga do operador[] que não é const conseguimos alterar objetos nao const
// Caso nosso objeto intList fosse constante podemos definir uma versão não const e uma
// versao const do operador[] separadamente.
// A versao nao const será usada com objetos nao const
// a versao const com objetos const

class IntList
{
private:
    int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 

public:
    // Para objetos não constantes: pode ser usado para atribuição
    int& operator[] (int index)
    {
        return m_list[index];
    }

// Para objetos const: só ​​pode ser usado para acesso
// Esta função também pode retornar por valor se o tipo for barato de copiar
    const int& operator[] (int index) const
    {
        return m_list[index];
    }

    // Observe que ambas implementações são identicas
    // O que muda é seu retorno
};

int main()
{
    IntList list{};
    list[2] = 3; // okay: chama a versao nao const do operador
    std::cout << list[2] << '\n';

    const IntList clist{};
    // clist[2] = 3; // erro de compilação: clist[2] retorna referência constante, que não podemos atribuir
    std::cout << clist[2] << '\n';

    return 0;
}