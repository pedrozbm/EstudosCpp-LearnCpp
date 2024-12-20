#include <iostream>

template <typename T, typename U, typename V>
class Triad
{
    private:    
        T m_first;
        U m_second;
        V m_third;

    public:
    T first(){
        return m_first;
    }

    Triad(const T& first, const U& second, const V& third):
        m_first{first},
        m_second{second},
        m_third{third}
        {
        }
     T& first() const{return m_first;}
     V& second() const{return m_second;}
     U& third() const{return m_third;}

    void print() const;
};

template <typename T, typename U, typename V>
void Triad<T,U,V>::print() const{
    std::cout << "[" << m_first << ", " << m_second << ", " << m_third << "]"; 
}

int main(){
    Triad<int , int,  int>t1{1, 2, 3};
    t1.print();
    std::cout << "\n";
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
     Triad<int, double, std::string> t2{1, 2.3, "Hello"s};
    t2.print();
    std::cout << '\n';

    return 0;
}