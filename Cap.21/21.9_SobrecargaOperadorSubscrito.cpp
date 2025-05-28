#include <iostream>

// Ao trabalhar com matrizes normalmente usamos o operador subscrito []
// para indexar elementos específicos de uma matriz

class IntList{
    private:
        int m_list[10]{}; //como nosso atributo é privado
        // e criar um metodo set para alterar valores pode ser um pouco confuso 
        // a melhor opção é a sobrecarga:

    public:
        int& operator [] (int index){ // o operador subscrito deve ser carregado como função membro
            return m_list[index]; //esperamos q o usuario passse um indice inteiro e retornamos um valor inteiro de volta
        }
};


int main(){

    IntList list{};
    list[2] = 3; // Note que aqui atribuimos diretamente o valor, vamos entender:
    // Como o operador de subscrito vem antes do que o operador de atribuição (=)
    // ele é avaliado primeiro
    // Como o operador [] retorna uma referência, ele retorna o list.m_list[2] elemento real do array
    // Nossa expressão se torna list.m_list[2] = 3, que é uma atribuição de int simples! 

    // Na lição 12.2 aprendemos que qualquer valor ao lado esquerdo de atribuição deve ser 
    // lvalue ( que é uma variável que possui um endereço de memória real)
    // Como o resultado de operator [] pode ser usado no lado esquerdo de uma atribuição (=)
    // O valor de retorno de operator[] deve ser um lvalue. 
    // Como se vê, referências são sempre l-value.
    std::cout << list[2] << '\n';

    return 0;
}