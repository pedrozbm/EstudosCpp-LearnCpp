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

// Essa classe contém um construtor de MOVIMENTAÇÃO
// E um operador de atribuição de MOVIMENTAÇÃO:
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

    DynamicArray(const DynamicArray &arr) = delete;
    DynamicArray &operator=(const DynamicArray &arr) = delete;

    DynamicArray(DynamicArray &&arr) noexcept : m_array{arr.m_array}, m_length{arr.m_length}
    {
        arr.m_length = 0;
        arr.m_array = nullptr;
    }
    DynamicArray &operator=(DynamicArray &&arr) noexcept
    {
        if (&arr == this)
            return *this;

        delete[] m_array;

        m_length = arr.m_length;
        m_array = arr.m_array;
        arr.m_length = 0;
        arr.m_array = nullptr;

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

// Tempos do novo programa:
// 0.008549
// 0.009518
// 0.008963

// Os tempos foram parecidos kkkkkkkkkkkkkkkkk
// Mas isso ocorre por otimização do compilador, esse jeito aqui é mais eficiente
// Segundo o GPTeco:
// Mesmo usando a classe com construtor de cópia, o compilador elimina completamente a cópia graças à otimização conhecida como:
// ✔ RVO — Return Value Optimization
// ✔ NRVO — Named Return Value Optimization

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