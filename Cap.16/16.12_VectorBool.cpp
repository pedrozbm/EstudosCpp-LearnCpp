#include <iostream>
#include <vector>


int main(){
    std::vector<bool> v {true, false, false, true, true }; //funciona como um normal std::vector

    for(int i:v)
        std::cout << i << ' ';
    std::cout << '\n';

    v[4] = false;

    for(int i:v)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}