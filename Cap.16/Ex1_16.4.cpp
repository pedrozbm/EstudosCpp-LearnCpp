#include <iostream>
#include <vector>

template <typename T>
void printElement (const std::vector<T>& arr, int indice){
    if(static_cast<int> (indice >= arr.size())){
    std::cout << "Indice invalido" << '\n';
    }else{
        std::cout << arr[indice] << std::endl;
    }

}

int main(){
    std::vector<int> v1{0, 1, 2, 3, 4};
    printElement(v1, 2);
    printElement(v1, 5);
    
    std::vector<float> v2{1.1, 2.2, 3.3};
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;    
}