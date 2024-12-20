#include <iostream>
int convert(int a){
    std::cout << a << std::endl;
}
int main()
{

    std::cout << "Enter a Single character: " << std::endl ; 
    char a;
    std::cin >> a;
    convert(a);
    std::cout << "You entered '" << a << "' , wich has ASCII code " << (a) << std::endl; 

    
    return 0;
}