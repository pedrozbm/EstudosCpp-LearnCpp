#include <iostream>
#include <string>

class Employee
{
private:
    std::string m_name{};
    int m_id{0};
public:
    Employee(std::string name):
    m_name{name}
    {
        std::cout << "Employee " << m_name << " created\n";
    }
    Employee(std::string name, int id): m_name{name}, m_id{ id }{
        std::cout << "Employee " << m_name << " created\n";
    }
};
int main(){
    Employee e1{"James" };
    Employee e2{"dave", 42};
    

}