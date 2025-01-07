#include <iostream>

int main(){
int value {5};

void* ptr{ &value }; // Este é um ponteiro vazio
// Um ponteiro vazio pode apontar para qualquer tipos de dados

std::cout << *ptr << '\n'; // O ponteiro não sabe para que tipo de dado está apontando
// antes disso, ele deve ser convertido para algum tipo

int* intPtr{static_cast<int*>(ptr)};

std::cout << *intPtr << '\n'; // Agora conseguimos desferenciar o ponteiro 

// Ponteiros nulos são tipados, podem ter aritimetica de ponteiros
// Ponteiros vazios não são tipados, não podem ser desreferenciados e não permitem aritimetica
}