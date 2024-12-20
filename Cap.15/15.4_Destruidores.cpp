//https://www.learncpp.com/cpp-tutorial/introduction-to-destructors/

#include <iostream>
class Simple
{
    private: 
        int m_id{};
    
    public: 
        Simple(int id)
            : m_id { id }
            {
                std::cout << "Constructing Simple " << m_id << '\n';
            }
        ~Simple(){
            std::cout<< "Destructing Simple " << m_id << '\n';
        }
        int getID() const {return m_id;}
};

int main(){
    Simple simple1{1};
    {
        Simple simple2{2};
    }
    return 0;
}