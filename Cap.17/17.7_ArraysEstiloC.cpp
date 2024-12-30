#include <iostream>

int main(){

const int arr2[5] {9, 8, 7, 6, 5}; // Declararmos explicitamente o tamanho do array, mas é desnecessario
const int arr[]{9, 8, 7, 6, 5}; // Se comporta da mesma forma

int s {2};
std::cout << arr[s] << '\n';

const int* ptr{arr};
std::cout << ptr[2];

unsigned int u { 2 };
std::cout << arr[u] << '\n';

    return 0;
}