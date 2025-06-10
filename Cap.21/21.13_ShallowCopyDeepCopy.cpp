#include <iostream>
#include <cassert>
#include <cstring>
/*
Como c++ não conhece nossa classe, ele usara o costrutor de cópia padrao
que usa um método de cópia membro a membro (cópia superficial)
Quando as classes não tem nenhuma memória alocada dinamicamente
isso funciona bem.
No entanto, ao projetar classes que manipulam memória alocada

dinamicamente, a cópia superficial pode causar problemas. 
Isso ocorre porque cópias superficiais de um ponteiro apenas copiam 
o endereço do ponteiro, não alocam memória nem copiam o conteudo apontado
Vejamos o exemplo:
*/
class MyString{
    private:
    char* m_data{};
    int m_length{};
    public:
    MyString(const char* source = ""){
        assert(source);
        m_length = std::strlen(source) + 1;

        m_data = new char[m_length];

        for(int i{0}; i < m_length; ++i)
            m_data[i] = source[i];
    }
    ~MyString(){
        delete[] m_data;
    }

    char* getString(){return m_data;}
    int getLength(){return m_length;}
};
// Como não definimos um construtor de cópia nessa classe
// C++ usará o construtor padrão....

//Agora considere o seguinte trecho: 
int main(){

        MyString hello{ "Hello, world!" };
    {
        MyString copy{ hello }; // usando o construtor de cópia
    } // Copy é uma var local, então é destruida aqui... O destruidor apaga
    // a string de copy, que deixa hello com ponteiro pendente.
    // A raiz do problema é a cópia superficial feita com construtor de cópias...

    std::cout << hello.getString() << '\n'; // Gera um comportamento indefinido 

    return 0;
}
/*
Uma solução para esse problema é fazer nosso próprio construtor de cópias.
Realizamos a cópia profunda de todos os ponteiros não nulos que estão copiados.
Uma cópia profunda aloca memória para cópia e depois copia o valor real, de modo que 
a cópia permaneça em uma memória distinta da fonte.
Dessa forma, a cópia e a fonte são distintam e nao se afetaram.
Observe a implementação:
*/
void MyString::deepCopy(const MyString& source){
    delete[] m_data;

    m_length - source.m_length;

    if(source.m_data){
        m_data = new char [m_length];

        for(int i{0}; i < m_length; ++i)
            m_data[i] = source.m_data[i];
    }else 
        m_data = nullptr;
}
MyString::MyString(const MyString& source){
    deepCopy(source);
}
/* 
Primeiro verificamos se source possui string.
Caso tenha, alocamos memoria suficeinte para armazenar uma cópia dela 
Por fim, copiamos manualmente a string.
Agora usamos o operador de atribuição sorecarregado:
*/
MyString& MyString::operator=(const MyString& source){
    if(this != &source){
        deepCopy(source);
    }
    return *this;
}
/*
Regra dos três: Se uma classe requer um destrutor, um construtor de cópia
ou um operador de atribuição de cópia definidos pelo usuario, provavelmente
ela precisa dos três.
Uma solução melhor: Classes como std::string e std::vector cuidam de todo
gerenciamento de memoria e possuem construtores de cópia sobrecarregados
e operadores de atribuição que realizam a cópia profunda adequada. 
Portanto, podemos simplesmente atribu-lás como variáveis fundamentais normais.
A classe fica mais simples, facil de usar e menos propensa a erros.
RESUMO:
->  Construtor de cópia padrão e operadores de atribuição fazem cópias superficiais,
o que é bom para classes que não contêm variáveis alocadas dinamicamente
-> Classes com varíaveis alocadas dinamicamente precisam ter um construtor de cópia
e um operador de atribuição que façam uma cópia profunda
-> dê preferência ao uso de classes na biblioteca padrão invês de fazer o 
próprio gerenciamento de memória.
*/
