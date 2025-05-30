#include <iostream>
/*
Na lição 10.6 estudamos conversao de tipos com static_cast
c++ já sabe como converter entre os tipo encorporados pelo programa
No entanto, não sabe converter nenhuma das classes definidas no
programa.
Na lição 14.6 vimos como usar construtor de conversão para criar objeto
do tipo da classe a partir de outro objeto, mas isso só funciona se
o tipo de destino for tipo de classe que pode ser modificado para
adicionar tal constutor, mas e se nao for o caso?
*/
// Vamos analisar a classe:

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents = 0) : m_cents{cents} {};

    //Sobrecarga do operador de tipo (int)
    operator int() const {return m_cents;}
    /*Algumas obs importante:
    Typecasts sobrecarregados devem ser membros não estaticos e dever ser const usados em objetos const
    Typecasts sobrecarregados não possuem parâmetros explícitos, pois não há omo passar argumentos implícitos
    para eles
    Eles ainda possuem um *this parâmetro oculto, apontando para o objeto implícito (que é o objeto a ser convertido)
    Typecast sobrecarregados não declaram um tipo de retorno, o nome da conversão (por exemplo, int) é usado como
    tipo de retorno permitido. Isso evita redundância na declaração.
    Agora em nosso main poderiamos chamar printInt(cents)
    */

    int getCents() const {return m_cents;}
    void setCents(int cents) {m_cents = cents;}
};

void printInt(int valor){
    std::cout << valor; // uma implementaçao de função simples para exemplo
}

int main()
{
    Cents cents {7};

    printInt(cents.getCents());

    std::cout << "\n";

    return 0;

    // Embora esse programa funcione, não é necessáriamente uma conversão
    // O compilador entenderá que deve usar conversões implicitas ou
    // conversões de conversão.
    // Para contornar isso temos a nosso favor a sobrecarga dos operadores typecast
}