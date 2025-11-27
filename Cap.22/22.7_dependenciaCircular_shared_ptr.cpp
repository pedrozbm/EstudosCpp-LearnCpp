#include <iostream>
#include <memory>
#include <string>
// Esse é um programa para demonstrar o problema de shared ptr
// imagine um sistema de parceiros, lucy e ricky serão parceiros
// class Person
// {
// private:
//     std::string m_name;
//     std::shared_ptr<Person> m_partner;

// public:
//     Person(const std::string &name) : m_name(name)
//     {
//         std::cout << m_name << " Created\n";
//     }
//     ~Person()
//     {
//         std::cout << m_name << " destroyed\n";
//     }

//     friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
//     {
//         if (!p1 || !p2)
//             return false;

//         p1->m_partner = p2;
//         p2->m_partner = p1;

//         std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';
//         return true;
//     }
// };
// int main(){
//     auto lucy{std::make_shared<Person>("Lucy")};
//     auto ricky{std::make_shared<Person>("Ricky")};

//     partnerUp(lucy, ricky);

//     return 0;
// }
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

O problema da ref ciclica pode acontecer até mesmo com um único shared_ptr
*/
// class Resource{
// public:
//     std::shared_ptr<Resource> m_ptr{};

//     Resource(){std::cout<<"Resource aquired\n";}
//     ~Resource(){std::cout << "Resource destroyed\n";} // Não vemos isso em nossa
//     //saida!
// };
// int main(){
// auto ptr1{std::make_shared<Resource>()};

// ptr1->m_ptr = ptr1;

// return 0;
// }
/*
Nesse exemplo, quando ptr1 sai do escopo, o recurso não é desalocado
porque o ptr m_ptr do recurso está compartilhando o recurso.
Nesse ponto, a única maneira de liberar o recurso seria definir m_ptr para outro valor
(de forma que nada mais compartilhe o recurso). MAs não podemos acessar
m_ptr por que ptr1 está fora do escopo, então não temos mais como fazer isso.
O recurso se tornou um vazamento de memoria!

std::weak foi projetado para resolver o problema de "propriedade ciclica"
um weak_ptr é um observador, ele pode observar e acessar o mesmo objeto que
um std::shared_ptr(ou outros std::weak_ptrs), mas não é considerado proprietário.
Quando um shared_ptr sai do escopo, ele só considera se outros shared_ptr são coproprietarios
do obj, o weak_ptr não conta.
*/
// class Person
// {
//     std::string m_name;
//     std::weak_ptr<Person> m_partner;

// public:
//     Person(const std::string &name) : m_name(name)
//     {
//         std::cout << m_name << " Created\n";
//     }
//     ~Person()
//     {
//         std::cout << m_name << " Destroyed\n";
//     }
//     friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
//     {
//         if (!p1 || !p2)
//             return false;

//         p1->m_partner = p2;
//         p2->m_partner = p1;

//         std::cout << p1->m_name << " is now partnered with " << p2->m_name << "\n";

//         return true;
//     }
// };

// int main()
// {
//     auto lucy{std::make_shared<Person>("Lucy")};
//     auto ricky{std::make_shared<Person>("Ricky")};

//     partnerUp(lucy, ricky);

//     return 0;
// }
/*Funcionalmente, funciona quase da mesma forma que o exemplo problemático
No entanto, agora, quando ricky sai do escopo, o compilador percebe que não
há outros std::shared_ptr apontando para Ricky ( o std::weak_ptr de Lucy não conta);
Portanto ele desaloca Ricky. E o mesmo ocorre para Lucy!

Considere o caso em que um ponteiro "burro" normal armazena o endereço de algum
obj, e em seguida, esse obj é destruido. Tal ponteiro é considerado pendente,
tentar desferenciar vai causar um comportamento indefinido. Infelizmente não há
como determinar se um ptr que armazena um endereço n nulo é pendente ou não.
weak_ptr tem um truque, ele tem acesso a contagem de referências de um objeto,
ele pode determinar se está apontando para um obj válido ou não.
A maneira mais fácil de testar se weak_ptr é válido ou não, é usar
a expired(), que retorna true se estiver apontando para um obj invalido e
false caso contrario.

Exemplo:
*/
class Resource
{
public:
    Resource() { std::cerr << "Resource acquired\n"; }
    ~Resource() { std::cerr << "Resource destroyed\n"; }
};

std::weak_ptr<Resource> getWeakPtr()
{
    auto ptr{std::make_shared<Resource>()};
    return std::weak_ptr<Resource>{ptr};
}

Resource *getDumbPtr()
{
    auto ptr{std::make_unique<Resource>()};
    return ptr.get();
}

int main()
{
    auto dumb{getDumbPtr()};
    std::cout << "Our dumb ptr is: " << ((dumb == nullptr) ? "nullptr\n" : "non-null\n");

    auto weak{getWeakPtr()};
    std::cout << "Our weak ptr is: " << ((weak.expired()) ? "nullptr\n" : "non-null\n");
}
 
/*
Tanto getDumbPtr quanto getWeakPtr utilizam um ponteiro inteligente
para alocar um recurso, esse ponteiro inteligente garante que 
o recurso alocado será destruido ao final da função.
Quando getDumbPtr retorna um Resource*, retorna um ptr inválido,
(pois unique_ptr destruiu o recurso ao final da função). Quando getWeakPtr 
retorna um weak_ptr, esse weak_ptr aponta de forma semelhante para um objeto invalido 
(pois shared_ptr destruiu o recurso ao final da função).

Dentro de main(), primeiro testamos se o ptr não referenciado retornado é nulo
Como o ptr não referenciado ainda contém o endereço do recurso desalocado, 
esse teste falha. Não há como main() determinar se esse ponteiro é pendente ou não.
Nesse caso, como se trata de um ptr pendente, se tentassemos desferencia-lo, o resultado
seria um comportamento indefinido.

Em seguida, testamos se weak.expired() é true. Como a contagem de referências para o obj apontado
por weak é false(pois o obj apontado já foi destruido), isso resulta em true. O código em main
pode portanto, dizer que weak está apontando para um objeto inválido, e podemos conficionar nosso cód
conforme apropriado. 

Observe que, se um weak_ptr estiver expirado, não devemos chamar lock(), pois o obj
apontado já foi destruido, portanto não há objeto para compartilhar. 
Se você chamar lock() de um weak_ptr expirado, ele retornará um shared_ptr para nullptr
*/