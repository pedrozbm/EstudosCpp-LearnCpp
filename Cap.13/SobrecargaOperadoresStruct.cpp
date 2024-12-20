#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage {};
};

std::ostream& operator<<(std::ostream& out, const Employee e){
    out << "id: "<< e.id << " Age: " << e.age << " Wage: "<< e.wage;
    return out;
}

int main(){

    Employee joe{2, 28};
    std::cout << joe << '\n';

    return 0;
}