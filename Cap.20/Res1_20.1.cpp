#include <utility>
#include <iostream>

//Passando funções como argumentos para outras funções

// Esse é um algoritimo de ordenação de numeros

bool maior(int x, int y){
    return x > y;
}
void SelectionSort(int *array, int size, bool (*comparacaoFcn)(int, int)){ // Note que passamos como arg uma funçao!
// Pode-se tambem definir funcoes como padrao ao chamar: 
// void SelectionSort(int *array, int size, bool (*comparacaoFcn)(int, int) = maior){ // Note que definimos maior como padrao 
// neste caso, maior deve ser definida antes
// Isso não funciona se a funcao for chamada por meio de um ponteiro de funcao
   if(!array || !comparacaoFcn)
        return;

    for( int startIndex {0}; startIndex < (size - 1); ++startIndex){
        int bestIndex {startIndex};

        for(int currentIndex{startIndex + 1 }; currentIndex < size; ++currentIndex){
            if(comparacaoFcn(array[bestIndex], array[currentIndex])){
                bestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex],array[bestIndex]);
    }
}
bool menor(int x, int y){
    return x < y;
}
void printArray(int *array, int size){
    if(!array)  
        return;
    
    for(int index{0}; index < size; ++index){
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';
}
int main(){
    int array[9] {3, 7, 9, 5, 6, 1, 8, 2, 4};

    SelectionSort(array, 9, menor);
    printArray(array, 9);

    SelectionSort(array, 9, maior);
    printArray(array, 9);

    return 0;
}