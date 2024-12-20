#include <iostream>
#include <ios>

template <typename T>
class Pair
{
private:
    T m_first{};
    T m_second{};

public:
    Pair(const T &first, const T &second) :
     m_first{first}, m_second {second}
     {}

     bool isEqual(const Pair<T>& pair);
};

template <typename T>
bool Pair<T>::isEqual(const Pair<T>& pair){
    return m_first == pair.m_first && m_second == pair.m_second;
}

int main()
{

    Pair<int> p1{5, 6};
    std::cout << std::boolalpha << "isEqual(5, 6): "<< p1.isEqual(Pair<int>{5, 6}) << '\n';

  
    return 0;
}