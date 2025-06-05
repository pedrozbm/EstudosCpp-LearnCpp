#include <algorithm> // Para std::max e std::copy_n
#include <iostream>

class MyString
{
private:
    char *m_data{};
    int m_length{};

public:
    MyString(const char *data = nullptr, int length = 0) : m_length{std::max(length, 0)}
    {
        if (length)
        {
            m_data = new char[static_cast<std::size_t>(length)];
            std::copy_n(data, length, m_data);
        }
    }
    ~MyString()
    {
        delete[] m_data;
    }

    MyString &operator=(const MyString &str);

    friend std::ostream &operator<<(std::ostream &out, const MyString &s);
};

std::ostream &operator<<(std::ostream &out, const MyString &s)
{
    out << s.m_data;
    return out;
}

MyString &MyString::operator=(const MyString &str)
{
    // Aqui garantimos que não teremos o problema da autoatribuição...
    if (this == &str)
        return *this;

    if (m_data)
        delete[] m_data;

    m_length = str.m_length;
    m_data = nullptr;

    if (m_length)
        m_data = new char[static_cast<std::size_t>(str.m_length)];
    std::copy_n(str.m_data, m_length, m_data);

    return *this;
}

int main()
{

    MyString alex("Alex", 5); // Meet Alex

    /*
    MyString employee;
    employee = alex;
    std::cout << employee;
    */
    // Isso funciona perfetiamente, mas isso:
    alex = alex;
    std::cout << alex;
    // Gera uma saída ruim.. Mas pq?
    /*
    Note que a sobrecarga vai primeiro verificar se a string passada tem uma string,
    caso tenha, ela vai ser apagada para evitar vazamento de memória... neste caso
    m_data é alocado, então a função exclui m_data, mas como str é a mesma coisa que *this
    a string que iriamos copiar foi excluida e m_data e str.m_data estão pendentes...
    Posteriormente, alocamos nova memória para m_data e str.data. Portanto, quando copiamos os
    dados de str.m_data para m_data, estamos copiadno lixom por que setr.m_data nunca foi inicializado
    Existe uma maneira simples de evitar isso! linha 38 desse código!
    Verificamos se o endereço do objeto implicito é o mesmo do que está sendo
    passado como parâmetro.

    Bons artigos para entender tudo e idioma de copiar e trocar :
    https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
    https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three
    https://en.wikipedia.org/wiki/Argument-dependent_name_lookup -> Isso é sobre ADL
    */

    return 0;
}