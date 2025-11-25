#include <iostream>
#include <memory>
#include <string>
// Esse é um programa para demonstrar o problema de shared ptr
// imagine um sistema de parceiros, lucy e ricky serão parceiros
class Person
{
private:
    std::string m_name;
    std::shared_ptr<Person> m_partner;

public:
    Person(const std::string &name) : m_name(name)
    {
        std::cout << m_name << " Created\n";
    }
    ~Person()
    {
        std::cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
    {
        if (!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';
        return true;
    }
};
int main(){
    auto lucy{std::make_shared<Person>("Lucy")};
    auto ricky{std::make_shared<Person>("Ricky")};

    partnerUp(lucy, ricky);

    return 0; 
}
/*
Esse programa gera: 
Lucy Created
Ricky Created
Lucy is now partnered with Ricky
Há algo errado aqui... 
Perceba que nenhuma desalocação aconteceu, após a chamada de partnerUp(),
existem dois ponteiros compartilhados apontando para "Ricky"(ricky e o m_partner de Lucy)
e dois ptr compartilhados apontando para "Lucy"(lucy e o m_partner de ricky)

Ao final de main(), o ponteiro compartilhado por "ricky" sai do escopo primeiro.
Quando isso acontece, "ricky" verifica se existem outros ponteiros compartilhados
que também são proprietários da Person "Ricky". Existem(o m_partner de Lucy). Por
causa disso, ele não desaloca Ricky(se o fizesse, o m_partner de Lucy acabaria como um ponteiro pendente)
Neste ponto, temos agora um ptr compartilhado para "Ricky"(o m_partner de Lucy) e
dois ponteiros compartilhados para "Lucy"(O de lucy e o m_parner de Ricky);

Em seguida, o ponteiro compartilhado por Lucy sai do escopo e a mesma coisa acontece.
O ponteiro compartilhado lucy verifica se existem outros ptrs compartilhados
que também são proprietários da Person "Lucy". Existem (o m_partner de Ricky)
então "Lucy" não é desalocado. Neste ponto, existe um ptr compartilhado para "Lucy"
(o m_partner de Ricky) e um ponteiro compartilhado para Ricky(o m_partner de Lucy)

então o programa termina e nem um nem outro é desalocado.
Temos então uma Referência circular, ou ciclica.


*/