
// A memoria do computador é dividida em segmentos 
// segmento do codigo: somente leitura, onde o programa compilado fica
// segmento bss: var globais e estaticas iniciadas com zero
// segmento de dados: var globais e estaticas
// heap: variaveis alocadas dinamicamente
// pilha de camadas: param  de funcao, var locais e outras info. de funcao
#include <iostream>
//heap 
int* ptr {new int};
int* array {new int[10]};
// relativamente lenta
// mem. premanece alocada ate ser desalocada
// mem. alocada deve ser acessada por ptr. desferenciar ptr é mais lento que acessar var diretamente
// 
int g_counter{ 0 };

void eatStack()
{
    std::cout << ++g_counter << ' ';

    // We use a conditional here to avoid compiler warnings about infinite recursion
    if (g_counter > 0)
        eatStack(); // note that eatStack() calls itself

    // Needed to prevent compiler from doing tail-call optimization
    std::cout << "hi";
}

int main()
{
    eatStack();

    return 0;
}