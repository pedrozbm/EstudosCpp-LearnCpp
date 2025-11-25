/*
c++ 14 inclui uma função adcional chamada std::make_unique().
Essa função constrói um obj do tipo parametrizado
e o inicializa com os argumentos passados para a função
*/

// #include <iostream>
// #include <memory>
// class Fraction
// {
// private:
//     int m_denominator{0};
//     int m_numerator{1};

// public:
//     Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator}
//     {
//     }
//     friend std::ostream &operator<<(std::ostream &out, const Fraction &f1)
//     {
//         out << f1.m_numerator << '/' << f1.m_denominator;
//         return out;
//     }
// };

// int main()
// {
//     // Aqui criamos e alocamos dinamicamente uma fração,
//     // Também podemos usar a dedução de tipo aqui!
//     auto f1{std::make_unique<Fraction>(3, 5)};
//     std::cout << *f1 << '\n';

//     // Aqui também criamos e alocamos e uma fração de comprimento 4
//     auto f2{std::make_unique<Fraction[]>(4)};
//     std::cout << f2[0] << '\n';
// }
/*
O uso de std::make_unique é opcional, mas recomendado em vez de criar um
std::unique_ptr manualmente.
Isso ocorre pois o código que usa make_unique é mais simples e também requer menos
digitação(quando usado com deduçaõ automatica).
Além disso, é resolvido o problema de segurança do c++14 de exceção que pode resultar
do C++ não especificar a ordem de avaliação dos argumentos da função;
Esse problema foi corrigido no c++17

----------------------------Melhores práticas----------------------------------
Use std::make_unique() em vez de criar std::unique_ptr e usar new você mesmo.
-------------------------------------------------------------------------------
*/

/*
Retornando unique_ptr de uma função:
std::unique_ptr<Resource> createResource(){
    return std::make_unique<Resource>();
}
int main(){
    auto ptr{createResource()}

    return 0;
}

Nesse código, createResource retorna unique_ptr por valor, se esse valor não for atribuido
a nada, o valor de retorno temporario sairá do escopo e o recurso será liberado. Em c++14 ou anterior
Se for atribuido, a semantica da movimentação será usada para transferir o recuros do
valor de retorno para o obj atribuido(ptr nesse caso), em c++17 o retorno será omitido
*/

// passando unique_ptr para uma função:

#include <iostream>
#include <memory>
#include <utility>

class Resource
{
public:
    Resource() { std::cout << "Recurso adquirido \n"; }
    ~Resource()
    {
        std::cout << "Recurso destruido\n";
    }
};

std::ostream &operator<<(std::ostream &out, const Resource &)
{
    out << "Eu sou o recurso\n";
    return out;
}

void takeOwnership(std::unique_ptr<Resource> res)
{
    if (res)
        std::cout << *res << '\n';
    else
        std::cout << "Sem recurso\n";
}
void usarRecurso(const Resource *res)
{
    if (res)
        std::cout << *res << '\n';
    else
        std::cout << "Sem recurso\n";
}
int main()
{

    auto ptr{std::make_unique<Resource>()};

    // takeOwnership(std::move(ptr)); // O recurso é destruido ao final desta função
    // Pois foi tranferido para essa função que tem seu fim antes da proxima linha!
    // Isso não é tão interessante...
    usarRecurso(ptr.get()); // Agora conseguimos obter um ponteiro para o recurso

    std::cout << "Fim do programa\n";

    return 0;
}