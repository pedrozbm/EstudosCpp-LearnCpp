#include <iostream>
#include <functional>
#include <chrono>
#include <iomanip>
class Timer{
    private: 
        using Clock = std::chrono::steady_clock;
        using Second = std::chrono::duration<double, std::ratio<1>>;

        std::chrono::time_point<Clock> m_beg{Clock::now()};

    public:
        void reset(){
            m_beg = Clock::now();
        }

        double elapsed() const
        {
            return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
        }
};
long add(long n1, long n2)
{
    return n1 + n2;
}
long subtract(long n1, long n2)
{
    return n1 - n2;
}
long multiply(long n1, long n2)
{
    return n1 * n2;
}
long divide(long n1, long n2)
{
    return n1 / n2;
}
using funcaoAritimetica = std::function<long(long, long)>;
std::function<long(long n1, long n2)> ptrOp{};

funcaoAritimetica getFuncaoAritimetica(char op){
    switch (op)
    {
    case '+':return &add;
    case '-':return &subtract;
    case '*':return &multiply;
    case '/':return &divide;
    
    default:
        break;
    }
}
char getOperator()
{
    char op{};
    do
    {
        std::cout << "Entre com um operador: +, -, *, / \n";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int main()
{
    long n1{0}, n2{0};

    std::cout << "Entre com dois numeros: ";
    std::cin >> n1 >> n2;
    char operador{getOperator()};

    funcaoAritimetica fcn {getFuncaoAritimetica(operador)};
    Timer t;
    std::cout << n1 << ' ' << operador << ' ' << n2 << " = " << fcn(n1, n2) << '\n';
    std::cout << "Time elapsed: "<<t.elapsed() << "seconds \n";
}