#include <iostream>

struct employee{
int id{};
int age{};
double wage{};
};
struct Company{
    int numberOdEmployees{};
    employee CEO{};
};
int main(){
    Company myCompany{7, {1, 32, 5500.00}};
    
    std::cout << myCompany.CEO.wage << '\n';

    return 0;
}