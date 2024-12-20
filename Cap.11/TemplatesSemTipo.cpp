#include <iostream>

template <int N>
void print(){
    std::cout << N << std::endl;
}
main(){

print<6>();

}