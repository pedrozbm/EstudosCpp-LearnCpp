#include <cassert>
#include <iostream>

class Fraction
{
private:
	int m_numerator{0};
	int m_denominator{1};

public:
	Fraction(int numerator = 0, int denominator = 1)
	: m_numerator { numerator}, m_denominator{denominator}{
		// static_assert(denominator != 0 ); -> static_assert dá avisos na compilação
		assert(denominator != 0); // -> dá aviso em tempo de execução
	}

	Fraction(const Fraction& copy):
	m_numerator{copy.m_numerator}, m_denominator{copy.m_denominator}{
		std::cout << "Construtor de cópia chamado\n";
	}

	Fraction& operator= (const Fraction& fraction);
	// Podemos impedir que atribuições sejam feitas tornando nosso operador de atribuição de cópia privado
	// ou usando delete:
	// Fraction& operator= (const Fraction& fraction) = delete;


	friend std::ostream& operator<< (std::ostream& out, const Fraction& f1);
};

std::ostream& operator << (std::ostream& out, const Fraction& f1){
	out << f1.m_numerator << "/" << f1.m_denominator << "\n";
	return out;
}

Fraction& Fraction::operator= (const Fraction& fraction){
	m_numerator = fraction.m_numerator;
	m_denominator = fraction.m_denominator;

	return *this; // -> retorna o objeto mesmo, não um ponteiro
}

int main(){

	// Fraction cincoTercos{5, 0}; -> gera erro pelo assert
	Fraction cincoTercos {5, 3};
	Fraction f;
	f = cincoTercos;
	std::cout << f;
	//como nosso operador sobrecarregado retorna *this, podemos fazer atribuições encadeadas:
	Fraction f1{4, 6};
	Fraction f2{7, 9};
	Fraction f3{1, 2};

	f1 = f2 = f3;
	//O valor que vai ser atribuido é 1/2

	//As coisas ficam interessantes aqui:
	f1 = f1;
	std::cout << f1;
	/*
	Isso chamará f1.operator=(f1) e, nessa implementação simples não há problema...
	A autoatribuição faz com que cada membro seja atribuido a si mesmo...
	Na maioria dos casos a autoatribuição não precisa fazer nada
	Entretanto, em casos que um operador de atribuição precisa atribuir memória dinamicamente
	a autoatribuição pode ser perigosa...
	Exemplo em res1 desse tópico! 
	Ao constrario de outros operadores, o compilador fornecerá um operador de atribuição publica 
	implicito para nosssa classe, para caso de não fornecermos um. 
	Este operador realiza a atribuição membro a membro
	Podemos impedir que atribuições sejam feitas tornando nosso operador de atribuição de cópia privado
	ou usando delete

	
	*/
	

	return 0;
}