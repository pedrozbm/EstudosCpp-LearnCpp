// Programa: MeusArgumentos
#include <iostream>
#include <string>

//alguns tipos de programas precisam de entradas para trabalhar...


int main(int argc, char* argv[]){
    std::cout << "Aqui temos " << argc << " argumentos:\n";

    for (int count{0}; count < argc; ++count){
        std::cout << count << ' ' << argv[count] << '\n';
    }
    return 0;
}