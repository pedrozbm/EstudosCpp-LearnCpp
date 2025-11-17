// Antes do c++11 existiam apenas um tipo de referência
// No c++11 ela é chamada de referência de valor-l, que só
// podem ser inicializadas com valores-l modificáveis 

// As referências de valor-l para objetos constantes são úteis pois 
// permitem passar qualquer tipo de argumento sem criar uma cópia do argumento

// R-VALUE
//C++ introduziu a referênia r-value, enquanto l-value é criada
// usando apenas um único &, r-value é criada usando dois &&
// int x{5};
// int& lref{x}; referência para l-value
// int&& rref{5}; Referência para r-value

// As referências de valores R não podem ser inicializadas com r-values

// Referências R-values extendem o tempo de vida do objeto com o qual foram inicializadas
// Para o tempo de vida da própria ref de r-value.
// Referência de r-values não constantes permitem alterar o r-value

// #include <iostream>
// class Fraction{
//     private:
//     int m_numerator{0};
//     int m_denominator{1};

//     public:
//     Fraction(int numerator = 0, int denominator = 1):
//     m_numerator{numerator}, m_denominator{denominator}{}

//     friend std::ostream& operator<<(std::ostream& out, const Fraction& f1){
//         out << f1.m_numerator << '/' << f1.m_denominator; 
//         return out;
//     }
// };


// int main(){
// auto&& rref {Fraction{3, 5}}; // referencia de r-value para a fração temporaria 

// std::cout << rref << '\n'; // Nenhuma cópia é criada, f1 se vincula
// // a variavel temporaria

// return 0; // rref e a fração temporaria saem do escopo aqui. 
// }
// Como um objeto anônimo, Fraction(3, 5) normalmente sairia do escopo
// ao final da expressão em que é definido. 
// No entanto, como estamos inicializando uma ref r-value com ele, sua 
// duração é estendida até o final do bloco, então usamos a ref para imprimir 
// O valor de Fraction

// As ref de r-value são frequentemente usadas como parametros de função
// Isso é especialmente útil para sobrecargas de função, quando se deseja 
// diferentes comportamentos para argumentos de valor l e r

#include <iostream>

void fun(const int& lref){
    std::cout << "ref l-value para const: " << lref << '\n';
}
void fun(int&& rref){
    std::cout << "ref a r-value: " << rref << '\n';
}

int main(){
    int x{5};
    fun(x);
    fun(5); 

    return 0;
}

// Surpreendentemente: 
// int&& ref {5};
// fun(ref); 
// Chama fun(const int&)... 
// Embora a varíavel reef tenha o tipo std::vector int&&
// Quando usada em uma expressão, ela é um lvalue. 
// Sabemos que 5 é um literal l-value e que x é um lvalue int
// Da mesma forma int&& ref é um lvalue do tipo int&&
// Portanto, não apenas fun(ref) é verdadeira fun(const int&), como também 
// não corresponde a nenhuma fun(int&&, já que referências a r-values não
//podem ser vinculadas a valores-l)

