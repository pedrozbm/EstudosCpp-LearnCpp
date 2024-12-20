#include <iostream>
#include <bitset>

main(){

    std::bitset<8> me{0b0000'0001};
    me.set(3); // muda posicão 3 para 1
    me.flip(4); // muda posição 4
    me.reset(4); // volta o bit 4 de volta para 0
 
    std::cout << "bits: " << me << "\n";
    std::cout << "bits: " << me.test(3) << "\n";
    std::cout << "bits: " << me.test(4) << "\n";
    std::cout << "bits: " << me.test(1) << "\n";
}
//ref: https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/