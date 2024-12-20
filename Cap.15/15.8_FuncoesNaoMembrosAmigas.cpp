#include <iostream>

class Humidity; // Necessario declarar antes para usar em funcao amiga com mais classes

class Temperature{
    private:    
        int m_temp{0};
    public:
        explicit Temperature(int temp):m_temp{temp} {}

        friend void printWheather(const Temperature& temperature, const Humidity& humidity);
};

class Humidity{
    private:
        int m_humidity{0};
    public:
        explicit Humidity(int humidity) : m_humidity{humidity} {}

        friend void printWheather(const Temperature& temperature, const Humidity& humidity);
};

    void printWheather(const Temperature& temperature, const Humidity& humidity){
        std::cout << "The temperature is " << temperature.m_temp << "and the humidity is " << humidity.m_humidity << '\n';
    }

int main(){
    Humidity hum {10};
    Temperature temp{12};

    printWheather(temp, hum);

}

// ---------Exemplo de função não membro ----------------
// class Accumulator
// {
// private:
//     int m_value{0};

// public:
//     void add(int value) { m_value += value; }

//     friend void print(const Accumulator& accumulator);
// };

// void print(const Accumulator &accumulator) // mesmo se essa função estivesse na classe, ela seria considerada não membro
// {
//     std::cout << accumulator.m_value;
// }

// int main()
// {
//     Accumulator acc{};
//     acc.add(5);

//     print(acc);

//     return 0;
// }