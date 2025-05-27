// creditos ao learningcpp.com
// https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/

#include <iostream>
#include <string>

// Imagine como exemplo uma classe com varios atributos privados
//  imprimir esses atributos é um pouco trabalhoso
//  Mesmo usando uma função para imprimir, ainda temos trabalho
//  com o cout, pois temos que passar o objeto como argumento
//  e o cout não sabe como imprimir o objeto, então temos que fazer
//  uma sobrecarga do operador << para imprimir o objeto
//  O mesmo vale para o operador >>, que é usado para ler o objeto

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z} {}

    friend std::ostream &operator<<(std::ostream &out, const Point &point);

    friend std::istream &operator>>(std::istream &in, Point &point);
};

std::ostream &operator<<(std::ostream &out, const Point &point)
{
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Point &point)
{
    // in >> point.m_x >> point.m_y >> point.m_z;
    // Há um problema aqui, pois o operador não sabe lidar com
    // entradas invalidas
    // Ao extrair um valor, queremos apenas dois valores possíveis
    // A falha ou sucesso da operação
    // Portanto usamos Operações transacionais: Em que uma operação deve ser completamente bem sucedida ou completamente falha
    // Assim como as transações em banco de dados ou transferencia de dinheiro.
    // Implementação:
    double x{};
    double y{};
    double z{};
    // Verificando se a leitura foi bem sucedida
    if(in >> x >> y >> z)
    {
       point = Point{x, y, z};
    }
    // Podemos também uma construção padrao caso tenha erro
    // in >> x >> y >> z;
    // point = in ? Point{x, y, z} : Point{};

    // Podemos também tratar as entradas invalidas, como exemplo numeros negativos:
    // in >> x >> y >> z;
    // if (x < 0.0 || y < 0.0 || z < 0.0)
    //    in.setstate(std::ios::failbit);
    // point = in ? Point{x, y, z} : Point{};
    // Assim, se a leitura falhar, o estado do fluxo de entrada é alterado para falha

    return in;
}

int main()
{
    const Point p1{1.0, 2.0, 3.0};
    Point p2{0, 0, 0};

    std::cin >> p2; // Lê os valores de x, y e z do ponto p1

    std::cout << p2 << std::endl; // Imprime os valores44 de x, y e z do ponto p1

    // std::cout << p1 << std::endl; // Point(1, 2, 3)
}