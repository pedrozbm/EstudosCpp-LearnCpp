#include <iostream>
#include <vector>

template <typename T>// podemos usar template para passar outros tipos além de int 
void passByReference(std::vector<T>& arr){
    std::cout << arr[1] << '\n';
}

int main(){
    std::vector<int> arr{1, 2 , 3 , 4};
    passByReference(arr);

    std::vector<float> arr2{1.1, 2.2, 3.3};
    passByReference(arr2);

}