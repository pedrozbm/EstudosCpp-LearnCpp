#include <iostream>
#include <array>

int main(){
    std::array<char, 5> prime{'h', 'e', 'l', 'l', 'o'};

    std::cout << "O comprimento eh " << prime.size() << '\n';

    std::cout << prime[1];
    std::cout << prime.at(1);
    std::cout << std::get<1>(prime);

}