#include <iostream>

//Ao trabalhar com matrizes, normalmente usamos o operador subscrito
// para indexar elementos especificos de uma matriz
// entretanto, quando temos uma classe com um membro privado,
// não podemos acessar diretamente o membro privado

// O metodo tipico seria criar um metodo de acesso
// embora funcione, não é muito elegante, veja o exemplo das linhas 16 e 17;

class IntList{
private:
    int m_list[10]{};   

public:
    void setItem(int index, int value){m_list[index] = value; }
    int getItem(int index) const { return m_list[index]; }

    // O melhor a se fazer é sobrecarregar o operador subscrito
    int &operator[](int index) { return m_list[index]; }
};

int main(){

    IntList list;
    list.setItem(2, 10); // Estamos definindo o elemento 2 com valor 3, ou o elemento 3 com valor 2?
    // Sem ver a definição, isso não fica claro.
    list[2] = 3; // Com a sobrecarga, tudo fica claro!
    // Isso é fácil tanto sintaticamente, quanto do ponto de vista de compreensão.
    // O compilador avalia list[2] e verifica se há uma sobrecarga do operador subscrito
    // se sim, ele passa o valor entre as chaves como argumento para a função
}

// Mas por que o operador subscrito retorna uma referência?

// Como o operador subscrito tem uma precedencia maior que o operador de atribuição,
// list[2] avalia primeiro. 
// list[2] chama o operador[], que definimos para retornar uma referência a list.m_list[2].
// Como o operator[] retorna uma referência, ele retorna o list.m_list[2] elemento real.
// Nossa expressão se torna equivalente a list.m_list[2] = 3, que é uma atribuição de inteiro simples

// Na lição 12.2 aprendemos que qualquer valor do lado esquerdo da atribuição deve
// ser um lvalue, que é uma variavel que possue um endereço de memória real.
// Como o resultado de operator[] pode ser usado do lado esquerdo
// o valor de retorno de operator [] deve ser um lvalue..
// Referências são sempre lvalues, pois só se pode tomar como referências variaveis que possuem um endereço de memória real.

// Considere o que acontecceria se o operador subscrito retornasse um valor inteiro:
// Se m_list[2] tivesse valor 6
// list[2] chamaria o valor 6;
// e nossa atribuição se tornaria 6 = 3;
// Isso não é válido, pois 6 não é uma variavel, é um valor literal.
// O compilador reclamará!
// erro C2106: '=' : operando esquerdo deve ser l-valor
