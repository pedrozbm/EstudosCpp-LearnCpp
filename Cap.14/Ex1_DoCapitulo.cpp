#include <iostream>
#include <cmath>
//https://www.learncpp.com/cpp-tutorial/chapter-14-summary-and-quiz/
class Point2d{
    private:
        double m_x{0.0};
        double m_y{0.0};

    public:

        Point2d() = default;
        Point2d(double x, double y): m_x{x}, m_y{y} { }

        void print(){
            std::cout << "Ponto2d(" << m_x << ", " << m_y << ")\n";
        }

    // double getX(){return m_x;};
    // double getY(){return m_y;};

        double DistanceTo(const Point2d& point){
            return sqrt((m_x - point.m_x)*(m_x - point.m_x) + (m_y - point.m_y)*(m_y - point.m_y));
        }
};

int main(){

    Point2d first{};
    Point2d second{3.0, 4.0};

    first.print();
    second.print();

    std::cout << "Distancia entre os dois pontos: " << first.DistanceTo(second) << '\n';

}