#include <iostream>
// PARTE 1 DO TÓPICO

// Recapitulando sobre construtores de cópia:
// - Usados para criar uma copia baseada num obj da mesma classe
// - A atriubuição de cópias é usada para copiar
// o obj de outra classe para o obj existente da mesma classe;
// -> Por padrão, c++ fornece um construtor de cópia e um operador
// de atribuição de cópia caso nenhum deles tenha sido explicitamente
// criado.
// -> Essas funções do compilador realizam cópias superficiais e podem
// causar problemas a classes que alocam memoria dinamica;

// Exemplo:

template <typename T>
class Auto_ptr3
{
	T *m_ptr{};

public:
	Auto_ptr3(T *ptr = nullptr) : m_ptr{ptr} {}

	~Auto_ptr3()
	{
		delete m_ptr;
	}
	// Construtor de cópia que faz uma cópia profunda:
	Auto_ptr3(const Auto_ptr3 &a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}
	// Atribuição de cópia:
	Auto_ptr3 &operator=(const Auto_ptr3 &a)
	{
		// Verifica autoatribuição:
		if (&a == this)
		{
			return *this;
		}
		// Libera os recursos:
		delete m_ptr;

		// copia o recurso:
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	T &operator*() const { return *m_ptr; }
	T *operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class resource
{
private:
	/* data */
public:
	resource()
	{
		std::cout << "Recurso Adquirido" << '\n';
	}
	~resource()
	{
		std::cout << "Recurso Destruido" << '\n';
	};
};
Auto_ptr3<resource> generateResource()
{
	Auto_ptr3<resource> res{new resource};
	return res; // Retorna o valor chamado pelo construtor de cópia
}

int main()
{
	Auto_ptr3<resource> mainres;
	mainres = generateResource();

	// Na nossa saída, teremos
	// Recurso Adquirido
	// Recurso Adquirido
	// Recurso Destruido
	// Recurso Destruido
	return 0;
}
// Analisando as etapas:
// 1. em generateResource(), res é local e é inicializada com um recurso
// alocado dinamicamente, o que causa o primeiro "Recurso adquirido"
// 2. res é retornada para main() por valor, pois é local e portanto não
// pode ser retornada como referencia(já que será destruida ao fim de generateResource)
// Res é construida como uma cópia de um obj temporario. Como o construtor de cópias 
// realiza uma cópia profunda, um novo recurso é alocado, causando novamente 
// "Recurso Adquirido"
// 3. O recurso sai do escopo, destruindo o recurso originalmente criado, o que causa 
// a primeira ocorrencia de "Recurso destruido"
// 4. O obj temporario é atribuido ao recurso principal pela atribuicao de cópia.
// Como nossa atribuição de cópia também realiza uma cópia profunda, um
// novo recurso também é alocado, assim temos outro "Recurso adquirido"
// 5. A expressão de atribuição termina, o obj temporario sai do escopo
// da expressao e é destruido, causando "Recurso destruido"
// 6. Ao final da main(), mainres sai do escopo e a mensagem final 
// "Recurso destruido" é chamada

// Isso é bem ineficiente... Mas não causa problemas