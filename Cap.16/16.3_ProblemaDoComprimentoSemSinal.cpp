#include <iostream>
#include <vector>

int main(){
    
    std::vector<int> prime{2, 3, 5, 7, 11};

    std::cout << prime[3];
    std::cout << prime[9]<< '\n'; // gera comportamento indefinido (index invalido)

    std::cout << prime.at(3) << '\n'; // at verifica o limite do array

    std::cout << prime.at(9) << '\n'; // Por ser invalido, gera uma excessao

    return 0;   
}