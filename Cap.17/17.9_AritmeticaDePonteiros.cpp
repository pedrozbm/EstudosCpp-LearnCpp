#include <iostream>

int main(){
    int arr[] {3, 2, 1};
    const int arr1[] {9, 7, 5, 3, 1};
    const int* begin{arr1};
    const int* end{ arr1 + (sizeof(arr1) / sizeof(arr1[0]))};

    for(; begin != end; ++begin){
        std::cout << *begin << ' ';
    }
    return 0; 

    std::cout << *(arr+1); 

}