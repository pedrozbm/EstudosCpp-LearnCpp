#include <iostream>
#include <vector>

int main()
{
    std::vector<char> exercise{'h', 'e', 'l', 'l', 'o'};

    // std::cout << std::size(exercise) << '\n'; // só vai funcionar em c++ 17
    std::cout << exercise.size() << '\n'; 
    std::cout << exercise[1] << exercise.at(1) << '\n';


}