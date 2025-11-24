#include <cstddef>
#include <algorithm>
#include <chrono>
#include <iostream>

/*
A classe Timer irá contar o tempo de dois programas distintos
iremos ver a eficiencia de cada método de movimentação!
*/
class Timer
{
private:
    // Type aliases to make accessing nested type easier
    using Clock = std::chrono::high_resolution_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<Clock> m_beg{Clock::now()};

public:
    void reset()
    {
        m_beg = Clock::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

// Essa classe contém um construtor de CÓPIA profunda
// E um operador de atribuição de CÓPIA:
template <typename T>
class DynamicArray
{
private:
    T *m_array{};
    int m_length{};

    void alloc(int length)
    {
        m_array = new T[static_cast<std::size_t>(length)];
        m_length = length;
    }

public:
    DynamicArray(int length)
    {
        alloc(length);
    }

    ~DynamicArray()
    {
        delete[] m_array;
    }

    DynamicArray(const DynamicArray &arr)
    {
        alloc(arr.m_length);
        std::copy_n(arr.m_array, m_length, m_array);
    }

    DynamicArray &operator=(const DynamicArray &arr)
    {
        if (&arr == this)
            return *this;

        delete[] m_array;

        alloc(arr.m_length);

        std::copy_n(arr.m_array, m_length, m_array);

        return *this;
    }

    int getLength() const { return m_length; }
    T &operator[](int index) { return m_array[index]; }
    const T &operator[](int index) const { return m_array[index]; }
};

DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int> &arr)
{
    DynamicArray<int> dbl(arr.getLength());
    for (int i = 0; i < arr.getLength(); ++i)
        dbl[i] = arr[i] * 2;

    return dbl;
}

// Vamos alocar 1 milhão de inteiros na heap
// Esses foram os tempos de execução:
// 0.008384
// 0.009113
// 0.010099

int main()
{
    Timer t;

    DynamicArray<int> arr(1000000);

    for (int i = 0; i < arr.getLength(); i++)
    {
        arr[i] = i;
    }
    arr = cloneArrayAndDouble(arr);

    std::cout << t.elapsed();
}
// A classe foi otimizada e está no arquivo "ExemploComArraysOtimizado"