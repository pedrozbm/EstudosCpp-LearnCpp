#include <iostream>

main(){
double d = 10/4;
int teste {4875};
std::cout << d << std::endl; // imprimirá 2, mas não é isso que queremos... 

int x {10};
int y {4};

double conversao_por_c_style_cast {double (x)/ y};
// static_cast<int>(teste);

int varDeTeste = (teste>>16);

std::cout << varDeTeste << std::endl; // conversão no estilo C 
std::cout << teste << std::endl; // conversão no estilo C 


std::cout << conversao_por_c_style_cast << std::endl; // conversão no estilo C 

int i {128};
char ch { static_cast<char>(i)}; // aqui assumimos a consequencia de possíveis estouros... 
std::cout << ch << std::endl;
// se converter um int de 2 ou 4 bytes para
// um char de 1 byte, possívelmente teremos problemas


}