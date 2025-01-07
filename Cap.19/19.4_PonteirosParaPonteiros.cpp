#include <iostream>



int main(){
    int value{5};

    int *ptr {&value};
    std::cout << *ptr << '\n';

    // Declarado usando dois asteristicos
    int** ptrptr{&ptr}; // nao pode ser declarado diretamente a uma var({&value})
    std::cout << **ptrptr << '\n';

}