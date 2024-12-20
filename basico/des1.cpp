#include <iostream>

double inserir(double n1, double n2, char operador){
    if(operador == '+')
        return n1 + n2;

    else if(operador == '-')
        return n1 - n2;

    else if(operador == '*')
        return n1 * n2;
       
}
int main(){
    double n1{}; 
    double n2{}; 
    char operador{};

    std:: cout << "Entre com o n1" << std::endl;
    std::cin >> n1; 
    std:: cout << "Entre com o n2" << std::endl;
    std::cin >> n2; 
    std :: cout << "Entre com o operador: "<< std::endl;
    std::cin >> operador; 

    std::cout << inserir(n1, n2, operador);
}