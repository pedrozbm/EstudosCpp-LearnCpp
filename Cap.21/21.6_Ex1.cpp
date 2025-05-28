#include <iostream>

// Essa implementação mostra o operador !, que é um operador lógico unário
// Ele é usado para verificar se um objeto é definido na origem ou nao    
class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x{x}, m_y{y}, m_z{z} {}

    Point operator-() const;

    Point operator+() const;

    bool operator!() const;

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

Point Point::operator-() const
{
    return Point{-m_x, -m_y, -m_z};
}

Point Point::operator+() const
{
    return Point{m_x, m_y, m_z};
    // mas isso também funciona:
    return *this;
}

bool Point::operator!() const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

int main()
{
    Point point{};

    if (!point)
    {
        std::cout << "Point is set at origin\n";
    }
    else
    {
        std::cout << "Point is not set at origin \n";
    }

    return 0;
}