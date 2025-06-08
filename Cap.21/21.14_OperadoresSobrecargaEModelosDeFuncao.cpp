// Obrigado learncpp
// https://www.learncpp.com/cpp-tutorial/overloading-operators-and-function-templates/

#include <iostream>

// Vamos criar uma classe do tipo Cents
class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents) : m_cents{cents} {}

    // Sobrecarregar nosso operador para printar
    friend std::ostream &operator<<(std::ostream &ostr, const Cents &c)
    {
        ostr << c.m_cents;
        return ostr;
    }
};

// E definir um max da função
template <typename T>
const T &max(const T &x, const T &y)
{
    return (x < y) ? y : x;
}

template <typename X>
X average(const X *myArray, int numValues)
{
    X sum{0};
    for (int count{0}; count < numValues; ++count)
    {
        sum += myArray[count];
    }
    sum /= numValues;
    return sum;
}

int main()
{

    Cents nickel{5};
    Cents dime{10};

    // Agora vamos tentar chamar nosso template de função passando Cents como parâmetro...
    Cents bigger{max(nickel, dime)};
    // O compilador tentará criar uma instância para o modelo que se parece com isso:
    /*
        template <>
        const Cents& max(const Cents& x, const Cents& y)
        {
            return (x < y) ? y : x;
        }

    E ai está o problema! C++ não faz ideia de como avaliar x < y quando são do tipo Cents
    Por isso temos um erro de compilação
    Para contornar o problema, podemos sobrecarregar o operador <
    Outro exemplo seria o template para average, precisariamos sobrecarregar o 
    operador += e também o operador /= 
    -> Lembrando que sobrecarga de operadores binarios é com função membro:
        Cents& operator+= (const Cents& cents){
            m_cents += m_cents;
            return *this;
        }
        Cents& operator /=(int x){
            m_cents /= x; -> x seria numero de vezes que somamos, e que dividimos para a média
            return *this;
        }

    */
    std::cout << bigger << "is bigger";

    return 0;
}