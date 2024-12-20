#include <iostream>
//definindo a estrutura:

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main(){
    Employee joe{};
    [[maybe_unused]] Employee frank{};

    joe.age = 32;

    std::cout << joe.age << "\n";

    return 0;
}