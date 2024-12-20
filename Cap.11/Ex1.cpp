#include <iostream>

template <typename T>
void fatorial(){
    std::cout << 
}

main(){

    static_assert(fatorial<0>() == 1);
    static_assert(fatorial<3>() == 6);
    static_assert(fatorial<0>() == 120);

    fatorial<-3>();

    return 0;
}