#include <iostream>
#include <array>
void foo(const int length){
    std::array<int, length> e{}; //gera erro, pois não é uma constexpr
}
int main(){
 
    int numStudents{};
    std::cin >> numStudents;

    std::array<int, numStudents> {}; // erro: numStudents não é uma expressao constante 
    //const std::array -> pode ser const

    foo(7);
    return 0;
}