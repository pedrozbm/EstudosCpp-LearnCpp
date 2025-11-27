/*
std::shared_ptr foi projetado para o caso em que
vários ponteiros inteligentes sejam proprietarios
do mesmo recurso
Isso significa que não há problemas ter múltiplos std::shared_ptr apontando
para o mesmo recurso. Internamentem std::shared_ptr controla os ponteiros que
estiverem compartilhando o mesmo recurso.
Enquanto pelo menos um shared_ptr estiver apontando para o recurso
ele não será desalocado, mesmo que shared_ptr individuais sejam destruidos
*/
#include <iostream>
#include <memory>
class Resource
{
private:
    /* data */
public:
    Resource() { std::cout << "Recurso adquirido\n"; };
    ~Resource() { std::cout << "Recurso adquirido\n"; };
};

int main()
{
    Resource *res{new Resource};
    std::shared_ptr<Resource> ptr1{res};
    {
        // std::shared_ptr<Resource> ptr2{ptr1}; // Aqui, criamos um ponteiro compartilhado a partir do
        // primeiro ponteiro, o que não tras problemas.
        std::shared_ptr<Resource> ptr2{res}; // Mas note que aqui, passamos o mesmo recurso,
        // Mas ambos ponteiros não sabem da existencia do outro.
        // Como consequencia, quando o ptr2 sai do escopo, ele exclui o recurso
        // Quando ptr1 sai do escopo e tenta excluir o recurso novamente, o que causa problemas.
        /*
        ----------------------------Melhores práticas---------------------------------------------
        Sempre faça uma cópia de um std::shared_ptr existente se 
        precisar de mais de um std::shared_ptr apontando para o mesmo recurso.
        ------------------------------------------------------------------------------------------
        */
        std::cout << "Destruindo o primeiro ponteiro compartilhado\n";
    }
    std::cout << "Destruindo o outro ponteiro compartilhado\n";

    return 0;
}
/*
Assim como make_unique, std::make_shared também pode e deve ser usado
para criar um std::shared_ptr. Ele está disponível no c++11

Ao contrario de unique_ptr usa um único ptr internamente
shared_ptr usa dois ponteiros internamente. Um ptr aponta para 
o recurso que está sendo gerenciado e o outro para o "bloco de controle",
que é um obj alocado dinamicamente que controla várias informações,
incluindo quantos shared_ptr estão apontando para o recurso.
Quando um shared_ptr é criado por meio de um construtor,
a mémoria para o obj gerenciado e para o bloco de controle
são alocadas separadamente. No entando, quando usamos 
make_shared, isso pode ser otimizado, para uma única alocação de 
memória, o que leva melhor desempenho.
Isso também explica pq a criação independente de dois shared_ptr causa problemas
Cada shared_ptr terá um ptr apontando para o recurso, no entando, cada um desses
ponteiros terá seu bloco de controle independente, em que será indicado
que ele é o único ponteiro que possui esse recurso.
No entanto, quando um shared_ptr é clonado usando atribuição de cópia,
os dados no bloco podem ser atualizados adequadamente para indicar
que agora existem shared_ptr adicionais gerenciando o recurso em conjunto

unique_ptr pode ser convertido para shared_ptr por meio de um construtor de shared_ptr
especial que aceita um valor de r de unique_ptr.
No entanto, shared_ptr n pode ser convertido para unique_ptr
*/