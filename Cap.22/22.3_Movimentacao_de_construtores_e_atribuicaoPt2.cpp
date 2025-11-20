#include <iostream>

// PARTE 2 DO TÓPICO

// Podemos fazer um código mais eficiente com a 
// semantica da movimentação:

// C++11 define duas novas funções para lidar com a semântica
// de movimentação:
// -Um construtor de movimentação
// -Um operador de atruibuição de movimentação
// Enquanto o objetivo do construtor de cópia e da 
// atribuição de cópia é criar uma cópia de um obj para outro,
// o objetivo do construtor de movimentação e da atribuição é 
// transferir a propriedade dos recursos de um obj para outro(o que é 
// muito menos custoso que criar uma cópia)

// Exemplo de implementação:

template<typename T>
class Auto_ptr4{
	T* m_ptr{};
	public:
	Auto_ptr4(T* ptr = nullptr): m_ptr{ptr}{}

	~Auto_ptr4(){
		delete m_ptr;
	}

	// Construtor de cópia (copia profunda)
	Auto_ptr4(const Auto_ptr4& a){
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Construtor de movimento ( transfere o recurso )
	Auto_ptr4(Auto_ptr4&& a) noexcept:
	m_ptr{a.m_ptr}{
		a.m_ptr = nullptr;
	}

	// Atribuição de cópia
	Auto_ptr4& operator=(const Auto_ptr4& a){
		
		if(&a == this)
		return *this;

		delete m_ptr;

		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Atribuição de movimento
	// Transferimos o recurso 
	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
	{
		if(&a == this)
		return *this;

		delete m_ptr;

		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr;}
	T* operator->() const {return m_ptr;}
	bool isNull() const {return m_ptr == nullptr;}
};

class Resource{
	public:
	Resource() {
		std::cout << "Resource acquired\n";
	}
	~Resource(){
		std::cout << "Resource destroyed\n";
	}
};

Auto_ptr4<Resource> generateResource(){
	Auto_ptr4<Resource> res {new Resource};
	return res; // Esse retorno chamará o construtor de movimentação
};

int main(){
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // Essa atribuição chama a atribuição de movimento
	
	return 0;
}

// O fluxo do programa é o mesmo de antes... Porém, agora temos o construtor de 
// operadores de atribuição de movimentação
/*
1. Dentro da função generateResource(), a variavel local res é criada e 
inicializa com um recurso alocado dinamicamente, o que causa a primeira ocorrencia
de "Recurso adquirido"
2. A variavel res é retornada para main() por valor. Em seguida, res é construida
como um obj temporario, transferindo o obj criado dinamicamnete
e armazenado em res para o obj temporario.
3. res sai de escopo. Como res não gerencia mais um ptr(foi movido para o temporario),
nada de interessante acontece aqui.
4. O obj temporário é movido e atribuido a memoria principal(mainres).
Isso transfere o objeto criado dinamicamente e armazenado no objeto 
temporário prara a memoria principal(mainres).
5. A expressão de atribuição termina, e o obj temporario sai do escopo da 
expressao e é destruido. No entanto, como o obj temporário não gerencia mais um ptr 
nada de interessante acontece aqui também.
6. Ao final da main(), mainres sai do escopo e a mensagem final "REcurso destruido" 
é exibida.

Assim, em vez de copiarmos nosso recurso duas vezes( uma vez para o construtor de 
cópia e outra para a atribuição de cópia), nós os transferimos duas vezes.
Isso é mais eficiente, pois o recurso é construído e destruido apenas uma vez
em vez de três;

-> Quando são chamados o construtor de movimentação e o de atribuição?

- São chamados quando são definidos e o argumento para a construção ou atribuição
é rvalue, normalmente, ele será literal ou temporario

O construtor de cópia e de atribuição são usados nos demais casos.
*/