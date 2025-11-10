#include <iostream>
#include <memory>
// Considere uma função na qual usamos alocação dinamica

// void someFunction(){
//     Resource* ptr = new Resource();

//     int x;
//     std::cout << "Entre com um int: ";
//     std::cin >> x;

//     if(x == 0)
//         return; // Aqui a função retorna antecipadamente
        // e o ponteiro não será excluído
        // isso também pode ocorrer com throw

    // A memoria alocada para o ponteiro será vazada
    // E será vazada toda vez que essa função for chamada

//     delete ptr;
// }

// Classes contém destruidores que são executados automaticamente quando 
// um obj sai do escopo
// Portanto podemos criar uma classe para ajudar a gerenciar e limpar os 
// ponteiros! 


template <typename T>
class Auto_ptr2
{
    T *m_ptr{};

public:
    // Construtuor moldado para possuir o ponteiro passado
    Auto_ptr2(T *ptr = nullptr) : m_ptr(ptr)
    {
    }
    // O destruidor da classe garantirá que ele seja desalocado
    ~Auto_ptr2()
    {
        delete m_ptr;
    }

    Auto_ptr2(Auto_ptr2& a)
    {
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
    }

    Auto_ptr2 &operator=(Auto_ptr2& a)
    {
        if (&a == this)
            return *this;

        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }

    // Sobrecarga para poder usar Auto_ptr1 como m_ptr
    T &operator*() const { return *m_ptr; }
    T *operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};
// Essa classe é chamada de ponteiro inteligente.
// Uma classe de composição é projetada para gerenciar a memoria 
// e garantir que a memoria seja excluida ao objetos sairem do escopo

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    Auto_ptr2<Resource> res1(new Resource());
//    Observe a alocação de memória aqui
// ... mas nenhuma exclusão explícita é necessária
// Observe também que usamos <Resource>, não <Resource*>
// Isso ocorre porque definimos m_ptr com o tipo T* (e não T)
    Auto_ptr2<Resource> res2;

    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    res2 = res1; // res2 assumes ownership, res1 is set to null

    std::cout << "Ownership transferred\n";

    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    return 0;
}