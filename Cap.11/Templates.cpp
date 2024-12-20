#include <iostream>

// O sistema de templates foi projetado para simplificar 
// o processo de criação de funções(ou classes)
// capazes de trabalhar com diferentes tipos de dados 
template <typename T>
T max(T x, T y){
    return (x<y)?y:x;
}
main(){
    std::cout << max<int>(1, 2) << '\n';
    std::cout << max<>(1, 2) << '\n'; // Podemos usar também a dedução de argumentos do modelo
    std::cout << max<double>(1,2)<< '\n';
    // Templates não suportam dois tipos diferentes de argumentos, devemos usar 
    // static cast
    std::cout << max(static_cast<double>(2), 3.5) << '\n';
    // Também podemos alterar a declaração de do Template
    // Definimos template <typename T, typename U> e agora temos 
    // dois parametros independentes, que podem ter tipos diferentes
    // Porém nesse caso ainda teremos que adicionar tambem a 
    //palavra auto, já que o operador condicional nesse caso retornará somente um int 
    // que pode nos fazer perder dados 


    return 0; 
}

//https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/