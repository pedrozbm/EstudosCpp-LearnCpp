#include <iostream>

void print(char ptr[]){
    std::cout << ptr << '\n';
}

int main(){
    char str[]{"string"};
    std::cout << str << '\n';

    print(str);

    return 0;
}