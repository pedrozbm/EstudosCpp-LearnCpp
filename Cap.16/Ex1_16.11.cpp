#include <iostream>
#include <vector>

void printPilha(const std::vector<int>& pilha){
  

    
    // std::cout << "(Pilha:  " << pilha.back() << " ) \n";
    std::cout << "(Pilha: ";
    for(const auto& correPilha: pilha)
        std::cout << " "<< correPilha << " ";
    if(pilha.empty())
        std::cout << " Vazia";
    std::cout << ") \n";

     
}

void popPilha(std::vector<int>& pilha){

    pilha.pop_back();
    printPilha(pilha);

}

void pushPilha(std::vector<int>& pilha, int valor){

    pilha.push_back(valor);
    printPilha(pilha);

}

int main(){
    std::vector<int> pilha{};
    
    pushPilha(pilha, 1);
    pushPilha(pilha, 2);
    pushPilha(pilha, 3);
    
    popPilha(pilha);
    pushPilha(pilha, 4);

    popPilha(pilha);
    popPilha(pilha);
    popPilha(pilha);

}