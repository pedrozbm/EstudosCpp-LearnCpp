/*
Para ser considerada uma agregação:
-> A parte(membro) faz parte do objeto (classe)
-> A parte(membro) pode (se desejado) pertencer a mais de um obejto(classe) simultaneamente
-> A existência da parte(membro) não é gerenciada pelo objeto(classe)
-> A parte (membro) não tem conhecimento da existência do objeto(classe)

Na agregação, as partes não são dependentes do objeto para
serem destruidas ou criadas.
Exemplo: Uma pessoa e seu endereçoo residencial
O endereço já existia antes da pessoa se mudar. 
O endereço continua existindo quando a pessoa se mudar. 
O endereço tambem pode pertencer a mais de uma pessoa 
ao mesmo tempo.
Portanto, a pessoa NÃO gerencia o endereço.
Por outro lado, considere um carro e um motor. 
O motor de um carro faz parte do carro. E embora o motor 
pertença ao carro, ele pode pertencer a outras coisas, como o 
proprietário. embora o carro saiba que tem um motor, 
o motor não sabe que faz parte do carro. 

Podemos dizer que os modelos de agregação estabelecem relações do tipo "possui um"

Geralmente em agregações, usam referências ou ponteiros para apontar 
objetos criados forra do escopo da base.
*/

#include <iostream>
#include <string>

class Teacher{
    private: 
        std::string m_name{};

    public:
        Teacher(std::string name): m_name{name}{}

        const std::string& getName() const {return m_name;}
};

class Department{
    private:
        const Teacher& m_teacher;

    public:
        Department(const Teacher& teacher):m_teacher{teacher}{}
};

int main(){
    Teacher bob{"bob"};

    {
        Department Department{bob};
    } // Como departamento sai do escopo aqui, ele é destruido!

    std::cout << bob.getName() << " still exists\n";

    return 0;
}

