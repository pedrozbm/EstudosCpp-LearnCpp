#include <iostream>
// Tais typecast também podem ser invocados explicitamente por meio de static_cast:

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents = 0) : m_cents{cents} {};

    // Sobrecarga do operador de tipo (int)
    // operator int() const { return m_cents; }

    // usando typecast explicito
    explicit operator int() const {return m_cents;}

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

// Podemos fornecer typecast carregados para qualquer tipo de dados
//  No exemplo vamos implementar numa classe dollars:

/* Typecast explicito:
Assim como podemos criar construtores explicit
também podemos criar sobrecargas explicitas. Conversoes de tipo
explicitas só podem ser invocadas por conversão (ex:static_cast)
Ou por inicialização direta
*/
class Dollars
{
private:
    int m_dollars{};

public:
    Dollars(int dollars = 0) : m_dollars{dollars} {}

    operator Cents() const { return Cents{m_dollars * 100}; }
    // Isso nos permite converter dollars obj diretamente em um Cents objeto

};

void printCents(Cents cents)
{
    // std::cout << cents; -> Isso não funciona quando usamos explicit e tentamos conversoes implicitas...
    std::cout << static_cast <int>(cents);
}

int main()
{

    Dollars dollars{9};
    printCents(dollars);
    std::cout << "\n";

}
/*
Quando usar typecast sobrecarregados ou construtores de conversão?

Em geral, um construtor de conversão é preferível. Exceto em alguns casos:
-> Ao fornecer um tipo fundamental (não é possivel usar construtores para esses tipos)
-> Quando a conversão retorna uma ref ou uma ref constante
-> Ao forncecer uma conversão para um tipo que nao se pode add membros(ex: conversão para std::vector)
-> Quando vc não quer que o tipo que está sendo construido reconheça o tipo que está sendo convertido 
isso pode ser util para evitar depêndencias circulares
 Para um exemplo do último item, std::stringtemos um construtor 
 para criar um std::stringa partir de um std::string_view. 
 Isso significa que <string>deve incluir <string_view>. 
 Se std::string_viewtivéssemos um construtor para criar um std::string_view 
 a partir de um std::string, <string_view>precisaríamos incluir <string>, 
 e isso resultaria em uma dependência circular entre cabeçalhos.

*/