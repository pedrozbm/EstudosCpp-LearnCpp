/*#include <iostream>

void someFunction()
{
    auto *ptr{new Resource()};

    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
        throw 0;

    delete ptr;
}
*/
// Note que nesse código teriamos um ponteiro pendente, pois antes de deletar
// o ptr, paramos essa execução;
/*
Ponteiros inteligentes gerenciam o recurso alocado
dinamicamente, fornecido pelo usuario do ptr inteligente.
Garantindo que o obj alocado dinamicamente será liberado no
momento correto.
*/
// Por isso, ptr inteligentes não devem ser alocados dinamicamente
// Caso isso aconteça, há o risco de não ser desalocado corretamente
// causando um vazamento de memória;

// std::unique_ptr;

/*
std::unique_ptr é o substituto em c++11 para o std::auto_ptr
Ele deve ser usado para gerenciar qualquer obj alocado dinamicamente
que não seja compartilhado entre multiplos objs
Portanto, deve ser proprietário completo do obj que gerencia,
e n compartilhar essa propriedade com outras classes
*/

#include <iostream>
#include <memory>
#include <utility>
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};
int main()
{
    // Aqui atribuimos a res a propriedade de Resouce
    //  std::unique_ptr<Resource> res {new Resource()};
    std::unique_ptr<Resource> res1{new Resource()};
    std::unique_ptr<Resource> res2{};

    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

    res2 = std::move(res1);
    std::cout << "Propriedade transferida\n";

    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");
    return 0;
} // quando res2 sai do escopo, Resource é destruido
/*
Como std::unique_ptr foi projetado com semantica de movimentação em mente
a inicialiação por cópia e a atribuição por cópia são desabilitadas
Portanto para transferir o conteúdo gerenciado por um unique_ptr é 
necessário usar a semantica de movimentação(usamos std::move nesse caso)

-> ACESSANDO O OBJ GERENCIADO   
unique ptr possui operadores *(para ref ao recurso gerenciado) e ->(retorna um ponteiro)
Lembre-se de verificar se unique_ptr está gerenciando algum objeto antes de usar algum
desses operadores.
std::unique_ptr possui uma conversão para bool, que retorna true se estiver gerenciando algo:
std::unique_ptr<Resource> res{new Resource{}};
if(res)
    std::cout << "Temos um ponteiro com recurso";

Melhores práticas

Dê preferência a std::array, std::vector ou std::string
em vez de um ponteiro inteligente que gerencie um array fixo, 
um array dinâmico ou uma string no estilo C.
*/

