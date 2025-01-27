#include <iostream>
#include <cstdarg> // Para usar ellipsis

// Ellipsis = retincencias
//C++ permite que sejam passados
// um numero variavel de parametros para uma funcao

double findAverage(int count, ...){
    // Devem ser sempre o ultimo parametro da funcao
    // 
    int sum{0};

    // Acessamos a reticencia com va_list
    std::va_list list;

    va_start(list, count);

    for(int arg{0}; arg < count; ++arg){
        sum+= va_arg(list, int);
    }
    
    va_end(list);

    return static_cast<double>(sum)/count;
}
int main(){

    std::cout << findAverage(5, 1, 2,3 ,4 , 5) << '\n';
    std::cout << findAverage(6, 1, 2, 3, 4, 5, 6) << '\n';
    // Reticencias não tem definição ou conversão de tipo    
    // Ao chamar uma função que use reticencias, cabe completamente 
    // ao programador garantir que os tipos passados correspondem aos 
    // tipos da função
    int value{7};
    std::cout << findAverage(6, 1.0, 2, "Hello, world!", 'G', &value, &findAverage) << '\n'; // sim, isto é aceito sem problemas
    // Aqui obteremos um resultado lixo
    // GIGO -> garbage in, garbage out 

    return 0;
}