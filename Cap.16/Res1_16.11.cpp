#include <iostream>
#include <string>
#include <vector>

class foo{
    private: 
    std::string m_a{};
    int m_b{};

    public:
    foo(std::string a, int b):
    m_a{a}, m_b{b}{};

    explicit foo(int b):
    m_a{}, m_b{b} {};

};

int main(){
    std::vector<foo> stack{};
    
    //Quando ja temos um objeto, push_back e emplace
    //são parecidos em eficiencia

    foo f{"a", 2};
    stack.push_back(f);
    stack.emplace_back(f);

    stack.push_back({"a", 2}); // Cria um obj temporario e move ao vetor
    // stack.emplace_back({"a", 2}); Encaminha diretamente os argumentos para o vetor, não há cópia


    // stack.push_back({2});
    stack.emplace_back(2);

    return 0; 
}