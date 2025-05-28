#include <iostream>
#include <cassert>
#include <string>
#include <string_view>

class Mystring
{
private:
    std::string_view m_stringColetada;

public:
    Mystring(std::string_view stringColetada = {}) : m_stringColetada{stringColetada} {}

    friend std::ostream &operator<<(std::ostream &saida, const Mystring &mystring);

    std::string_view operator()(int indiceInicio, int caracteresRetornados)
    {
        assert(indiceInicio >= 0);
        assert(indiceInicio + caracteresRetornados <= static_cast<int>(m_stringColetada.length()) && "a substring está fora do escopo");

        return std::string_view{m_stringColetada.substr(static_cast<std::string_view::size_type>(indiceInicio), static_cast<std::string_view::size_type>(caracteresRetornados))};
    };
};

std::ostream &operator<<(std::ostream &saida, const Mystring &mystring)
{
    saida << mystring.m_stringColetada;
    return saida;
}

int main()
{
    Mystring s{"Hello, world!"};
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}

/* Algumas questões:
OBS: Agora o código acima está alterado, mas antes era usado std::string no lugar de std::string_view
Consultar o maravilhoso site: https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator/
Por que o procedimento acima é ineficiente se não precisamos modificar a substring retornada?
Dentro de operator(), std::substring retorna uma string, que significa que quando chamamos,
estamos fazendo uma cópia de parte da string de origem. 
Nosso método sobrecarrregado () usa isso para construir um novo Mystring(nossa classe), que contém
um std::string membro, que faz outra cópia. 
Em seguida retornamos Mystring ao chamador, que faz uma terceira cópia. O compilador provavelmente
otimizara algumas, mas pelo menos uma std::string deve ser mantida
Só precisamos de uma cópia de substring nos casos em que pretendemos modifica-lá ou quando
a substring durar mais que a string original. Normalmente, esse não é o caso.
Então estamos fazendo cópias caras que não precisamos.
*/