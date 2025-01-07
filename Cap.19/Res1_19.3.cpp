#include <iostream>

class Simple{
    private:
        int m_nId{};
    
    public:
        Simple(int nId):
        m_nId{nId}{
            std::cout << "Construindo construtor simples " << nId << '\n';
        }
        ~Simple(){
            std::cout << "Destruindo simples" << m_nId << '\n';
        }
        int getId(){return m_nId;}
};
int main(){
    Simple simples{1};
    std::cout << simples.getId() << '\n';

    Simple* pSimples{ new Simple{2}};

    std::cout << pSimples -> getId() << '\n';

    delete pSimples;

    return 0;
}