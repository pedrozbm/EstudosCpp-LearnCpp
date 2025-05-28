// Baseado em: https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap/

// A memoria do computador é dividida em segmentos
// segmento do codigo: somente leitura, onde o programa compilado fica
// segmento bss: var globais e estaticas iniciadas com zero
// segmento de dados: var globais e estaticas
// heap: variaveis alocadas dinamicamente
// pilha de camadas: param  de funcao, var locais e outras info. de funcao
#include <iostream>
// heap
int *ptr{new int};
int *array{new int[10]};
// relativamente lenta
// mem. premanece alocada ate ser desalocada
// mem. alocada deve ser acessada por ptr. desferenciar ptr é mais lento que acessar var diretamente
//
int g_counter{0};

void eatStack()
{
    std::cout << ++g_counter << ' ';

    // Usamos uma condicional aqui para evitar avisos do compilador sobre recursão infinita
    if (g_counter > 0)
        eatStack(); // observe que eatStack() chama a si mesma

    // Necessário para evitar que o compilador faça otimização de chamada em cauda
    std::cout << "hi";
}

// O segmento de pilhas de chamada contém a memoria usada para a pilha de chamadas
// Quando o app é iniciado, a função ,main() é chamada e inserida na pilha pelo SO
// Em seguida o programa começa a ser executado

int main()
{
    eatStack();

    return 0;
}