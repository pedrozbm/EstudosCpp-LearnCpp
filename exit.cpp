#include <cstdlib>
#include <iostream>

void cleanup(){
    std:: cout << "Cleanup! \n";
}
int main(){

    std::atexit(cleanup);//atexit chama a função ao termino do programa. 

    std::cout << 1 << '\n';

    std::exit(0); // chmamada para encerrar o programa, pode ser chamado de qualquer lugar, inclusive funções

    std::cout << 2 << '\n';

    return 0;
}