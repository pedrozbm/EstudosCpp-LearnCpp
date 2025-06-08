#include <iostream>
#include <cstdint>

class Average
{
private:
    std::int32_t m_sum;
    std::int32_t m_repeat;

public:
    Average() : m_sum{0}, m_repeat{0} {

                };

    Average &operator+=(std::int32_t num)
    {
        ++m_repeat;
        m_sum += num;

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, Average &sum)
    {
        if (sum.m_repeat == 0)
        {
            out << 0;
            return out;
        }
        out << (sum.m_sum / sum.m_repeat);
        return out;
    }
};

int main()
{
    Average avg{};
    std::cout << avg << '\n';

    avg += 4;
    std::cout << avg << '\n';

    avg += 8;
    std::cout << avg << '\n';

    avg += 24;
    std::cout << avg << '\n';

    avg += -10;
    std::cout << avg << '\n';

    (avg += 6) += 10;
    std::cout << avg << '\n';

    Average copy{avg};
    std::cout << copy << '\n';

    return 0;
}