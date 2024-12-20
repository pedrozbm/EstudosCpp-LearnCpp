#include <iostream> 

int main(){
int x {5};
int y {++x};

std::cout << x <<' '<< y << '\n';
std::cout << x <<' '<< y++ << '\n';
std::cout << x <<' '<< y << '\n';

}
// A saida desse programa é 6 6, esse incremento 
// adiciona na própria var o valor desejado. 
// Geralmente usamos o incremento pós var, assim o compilador 
// cria uma cópia de x e depois o incrementa. 
// O incremento não surtira efeito na segunda impressao, y é chamada
// antes do incremento. 