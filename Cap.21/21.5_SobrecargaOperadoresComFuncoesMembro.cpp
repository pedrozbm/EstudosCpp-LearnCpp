#include <iostream>

// Ao sobrecarregar um operador com uma função membro
// O operador sobrecarregado deve ser adicionado como uma função membro do operando esquerdo
// O operando esquerdo se torna o objeto *this implicito
// Todos os outros operandos se tornam parâmetros de função

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents) : m_cents(cents) {} // Construtor

    // Sobrecarga do operador + como uma função membro
    Cents operator+(int value) const;

    int getCents() const { return m_cents; } // Método para obter o valor em centavos
};

Cents Cents::operator+(int value) const{
    return Cents(m_cents + value); 
}

    int main()
{
    const Cents cents1{6};

     
    const Cents cents2 = { cents1 + 2};
    // O compilador traduz a expressão acima como:
    // cents2 = cents1.operator+(2);
    // O compilador converte implicitamente um prefixo de objeto em um parâmetro mais a esquerda
    // Chamando *this (estudado no tópico 15.1)
    // Portanto isso se torna operator+(&cents1, 2), que é quase idêntico a maneira friend.

    // Mas quando vou saber o que usar? 
    // Os operadores de atribuição(=), subscrição([]), chamada de função(()), e seleção de membro(->) 
    // devem ser sobrecarrecados como funções membros, pois a linguagem exige isso.

    // Também não podemos sobrecarregar o operador << como uma função membro,
    // pois o operador << (que será sobrecarregado) deve ser adicionado como membro do operando esquerdo.
    // E nesse caso, o operando esquerdo é um objeto ostream, que não pode ser modificado.
    // Portanto, o operador << deve ser sobrecarregado como uma função normal(preferível) ou amiga.

    // Como escolher a semântica correta para o operador?
    // Na maioria dos casos, a linguagem deixa a nosso críterio
    // No entanto, apenas uma é a melhor escolha 
    // Ao lidar com operadores binarios que não modificam o operando esquerdo (como +, -, *, /, %)
    // A melhor escolha é sobrecarregar o operador como uma função normal ou como uma função friend
    // pois funciona para todos os tipos de parâmetros, mesmo quando o operando esquerdo não é um objeto da classe.

    //Ao lidar com operadores binários que modificam o operando a esquerda (como =, +=, -=, *=, /=, %=)
    // é preferível sobrecarregar o operador como uma função membro, pois o operando a esquerda.
    // sempre será um tipo de classe, e ter um obj a a ser modificado como aquele apontado po *this é natural.
    // não há confusão, e o código é mais fácil de ler.
    // pois a linguagem exige que o operando esquerdo seja um objeto da classe.

    std::cout << "I have " << cents2.getCents() << " cents.\n";

    return 0;
}

// Regras a serem adotada: 
// As seguintes regras práticas podem ajudar você a determinar qual formato é melhor para uma determinada situação:

// Se você estiver sobrecarregando atribuição (=), subscrito ([]), chamada de função (()) ou seleção de membro (->),
// faça isso como uma função de membro.

// Se você estiver sobrecarregando um operador unário, 
//faça isso como uma função membro.

// Se você estiver sobrecarregando um operador binário que não modifica seu operando esquerdo 
//(por exemplo, operador+), faça isso como uma função normal (preferencial) ou função amiga.

// Se você estiver sobrecarregando um operador binário que modifica seu operando esquerdo, 
// mas não puder adicionar membros à definição de classe do operando esquerdo
// (por exemplo, operator<<, que tem um operando esquerdo do tipo ostream), 
// faça isso como uma função normal (preferencial) ou função amiga.

// Se você estiver sobrecarregando um operador binário que modifica seu operando esquerdo 
// (por exemplo, operador+=) e puder modificar a definição do operando esquerdo, 
// faça isso como uma função membro.