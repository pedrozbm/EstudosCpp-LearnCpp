#include <iostream>
#include <utility>

// template <typename T>
// struct Pair{
//     T first{};
//     T second{};
// };

template <typename U, typename Y>
void print(std::pair <U, Y> p){
    std::cout << '[' << p.first << ", " << p.second << ']';
}

int main(){
// Pair<int> p1{5, 6};
// Pair<double> p2{4.478, 8.7};
// Pair<std::string>s1{"arroz", "macarrao"};
std::pair<int, int> p3{7, 9};

// std::cout << p1.first << '\n'; 
// std::cout << p2.first << '\n'; 
// std::cout << s1.second << '\n'; 

print(p3);

}