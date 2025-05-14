#include <iostream>

int main(){

int arr2[5] {}; // Declararmos explicitamente o tamanho do array, mas é desnecessario
const int arr[]{9, 8, 7, 6, 5}; // Se comporta da mesma forma
int teste {0x060700};

int s {2};

std::cout << ((teste >> 24)& 0xFF);
std::cout << ((teste >> 16)& 0xFF);
std::cout << ((teste >> 8)& 0xFF);
std::cout << ((teste)& 0xFF);


}
// canMsgEnviada_ts.data[2] = (tamFlashCode >> 24) & 0xFF;
// canMsgEnviada_ts.data[3] = (tamFlashCode >> 16) & 0xFF;
// canMsgEnviada_ts.data[4] = (tamFlashCode >> 8) & 0xFF;
// canMsgEnviada_ts.data[5] = (tamFlashCode & 0xFF);

std::cout << arr[s] << '\n';

std::cout << arr[s] << '\n';



const int* ptr{arr};
std::cout << ptr[2];

unsigned int u { 2 };
std::cout << arr[u] << '\n';

    return 0;
}