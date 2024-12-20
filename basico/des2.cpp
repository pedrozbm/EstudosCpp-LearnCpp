#include <iostream>

double getTorre(){    
    double torre{};
    std:: cout << "Informe a altura da torre em metros: ";
    std:: cin >> torre;
    return torre;
}
double calculaTorre(double torre){
    double g {9.8};

    for (int i = 0; i < 5; i++)
    {
        std::cout << "At " << i << "seconds, the ball is at height: " << (torre - ((g*(i*i))/2)) << std::endl;

    }
    

}


main(){
    double t{getTorre()};

    calculaTorre(t);
}