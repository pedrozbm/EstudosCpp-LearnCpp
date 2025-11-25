/*
Em alguns casos, os valores que gostariamos de movimentar 
usando a semantica do movimento não serão 
r-value. 
// Exemplo:

#include <iostream>
#include <string>
template <typename T>
void mySwapCopy(T& a, T& b){
    // Ao receber os objetos, seus valores são trocados 
    // usando 3 cópias, caso o compilador não otimize, isso pode ser lento!
    // Nesse caso poderiamos usar uma movimentação
    T tmp{a};
    a = b;
    b = tmp;
}
template <typename T>
void mySwapMove(T& a, T& b){
    T tmp = {std::move(a)};
    a = std::move(b);
    b = std::move(tmp);
}

int main(){
    std::string x{"abc"};
    std::string y{"de"};

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    // mySwapCopy(x, y); -> Chama o método de cópia (menos eficiente)
    mySwapMove(x, y); // Chama o método de movimentação (mais eficiente) 

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    return 0;
}
*/
// Agora vamos implementar em elementos de um container, como std::vector:

#include <iostream>
#include <string>
#include <utility> // for std::move
#include <vector>

int main(){
    std::vector <std::string> v;

    std::string str{"Knock"};

    std::cout << "Copying str\n";
    v.push_back(str); // Nesse primeiro caso, passamos por cópia o valor, portanto, ele permanece inalterado no original

    std::cout << "str: " << str << '\n';
    std::cout << "vector: " << v[0] << '\n';

    std::cout << "\nMoving str\n";

    v.push_back(std::move(str)); // Nesse segundo caso, passamos o valor como r-value(através do std::move)
    // Então, é usada a semantica de movimentação, agora o vetor "rouba" o valor da string ao invés de copiar

    std::cout << "str: " << str<<'\n'; // Note que nada é impresso aqui! 
    std::cout << "vector: " << v[0] << ' ' << v[1] <<'\n';

    return 0;
}
/*
Os objetos estarão em estado válido, mas provávelmente em estado indeterminado(a depender da implementação)

-> Em que outras situações std::move é útil?
Muitos algoritimos de ordenação(bubble, selection), funcionam trocando pares de elementos
também pode ser útil para mover o conteúdo gerenciado por um ptr inteligente para outro
*/