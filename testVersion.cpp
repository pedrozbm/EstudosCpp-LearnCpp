#include <iostream>
#include <variant>
#include <any>
#include <vector>
#include <chrono>

// Função que usa fold expression para calcular a soma de múltiplos argumentos
template<typename... Args>
auto somar(Args... args) {
    return (args + ...);  // Expansão dos argumentos usando fold expression
}

// Função que aceita um std::any e tenta imprimir seu valor
void imprimirValor(const std::any& valor) {
    if (valor.type() == typeid(int)) {
        std::cout << "Valor inteiro: " << std::any_cast<int>(valor) << '\n';
    } else if (valor.type() == typeid(double)) {
        std::cout << "Valor double: " << std::any_cast<double>(valor) << '\n';
    } else if (valor.type() == typeid(std::string)) {
        std::cout << "Valor string: " << std::any_cast<std::string>(valor) << '\n';
    } else {
        std::cout << "Tipo desconhecido!\n";
    }
}

int main() {
    // Uso de std::variant para armazenar diferentes tipos de dados
    std::variant<int, double, std::string> meuValor;

    // Atribuindo diferentes tipos de valor
    meuValor = 10;
    std::cout << "std::variant armazenando um int: " << std::get<int>(meuValor) << '\n';

    meuValor = 3.14;
    std::cout << "std::variant armazenando um double: " << std::get<double>(meuValor) << '\n';

    meuValor = "Olá, C++17!";
    std::cout << "std::variant armazenando uma string: " << std::get<std::string>(meuValor) << '\n';

    // Uso de std::any para armazenar qualquer tipo de dado
    std::any valorAleatorio = 42;
    imprimirValor(valorAleatorio);

    valorAleatorio = 3.1415;
    imprimirValor(valorAleatorio);

    valorAleatorio = std::string("C++17 é incrível!");
    imprimirValor(valorAleatorio);

    // Uso de fold expression para somar múltiplos valores
    std::cout << "Soma de 1, 2, 3, 4: " << somar(1, 2, 3, 4) << '\n';
    std::cout << "Soma de 1.1, 2.2, 3.3: " << somar(1.1, 2.2, 3.3) << '\n';

    return 0;
}
