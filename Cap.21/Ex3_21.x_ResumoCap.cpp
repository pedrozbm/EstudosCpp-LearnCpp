#include <iostream>
#include <cassert>
#include <cstdint>

class FixedPoint2
{
private:
    int8_t m_number{0};
    int16_t m_fractionPart{0};

public:
    FixedPoint2(int8_t number, int16_t fractionPart) : m_number{number}, m_fractionPart{fractionPart} {};


    friend std::ostream &operator<<(std::ostream &out, FixedPoint2 &fixedPoint)
    {
        out << fixedPoint.m_number << ", " << fixedPoint.m_fractionPart << std::endl;
        return out;
    }

    operator FixedPoint2() const
    {
        return FixedPoint2{static_cast<double>(m_number), static_cast<double>(m_fractionPart)};
    }

    operator double() const
    {
        return FixedPoint2{static_cast<double>(m_number), static_cast<double>(m_fractionPart)};
    }
};

int main()
{
    FixedPoint2 a{34, 56};
    std::cout << a << "\n";
    std::cout << static_cast<double>(a) << '\n';
    assert(static_cast<double>(a) == 34.56);

    FixedPoint2 b{-2, 8};
    assert(static_cast < double>(b) == -2.08);

    FixedPoint2 c{2, -8};
    assert(static_cast<double>(c) == -2.08);

    FixedPoint2 d{-2, -8};
    assert(static_cast<double>(d) == -2.08);

    FixedPoint2 e{0, -5};
    assert(static_cast<double>(e) == -0.05);

    FixedPoint2 f{0, 10};
    assert(static_cast<double>(f) == 0.1);

    return 0;
}