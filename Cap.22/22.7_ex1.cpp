/*
Exercicio:
Corrija o programa apresentado na seção “Um caso redutivo” para que o recurso
seja desalocado corretamente. Não altere o código em main().
*/

#include <iostream>
#include <memory>

class Resource
{
public:
    std::weak_ptr<Resource> m_ptr{}; // Antes estava shared_ptr, o que causava a ref ciclica

    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }    
};

int main()
{
    auto ptr1{std::make_shared<Resource>()};
    ptr1->m_ptr = ptr1;

    return 0;
}