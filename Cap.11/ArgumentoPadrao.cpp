#include <iostream>

void print(int x, int y = 4){
    std::cout << x << '\n';
    std::cout << y << '\n';
}

main(){
    print(1,2);
    print(3);
    //Esse código imprimira 1, 2, 3, 4
    return 0; 
} 