#include <iostream>
#include <cassert>
#include <cstdint>
#include <cmath>

class FixedPoint2
{
private:
    int8_t m_number{0};
    int16_t m_fractionPart{0};

public:
    FixedPoint2(int8_t number, int16_t fractionPart) : m_number{number}, m_fractionPart{fractionPart}
    {
        if (m_number < 0 || m_fractionPart < 0)
        {
            if (m_number > 0)
                m_number = -m_number;
            if (m_fractionPart > 0)
                m_fractionPart = -m_fractionPart;
        }
        m_number += m_fractionPart / 100; // integer division
        m_fractionPart = m_fractionPart % 100;
    }
    FixedPoint2(double number) : FixedPoint2(
                                     static_cast<std::int16_t>(std::trunc(number)),
                                     static_cast<std::int8_t>(std::round(number * 100) - std::trunc(number) * 100)) {}

    friend std::ostream &operator<<(std::ostream &out, const FixedPoint2 &fixedPoint)
    {
        out << static_cast<double>(fixedPoint);
        return out;
    }

    bool operator==(const FixedPoint2 &d) const
    {
        return (d.m_number == m_number) && (d.m_fractionPart == m_fractionPart);
    }

    friend bool testDecimal(const FixedPoint2 &fp);

    explicit operator double() const
    {
        if (m_number < 0 || m_fractionPart < 0)
        {
            return -(std::abs(m_number) + std::abs((static_cast<double>(m_fractionPart) / 100)));
        }
        else
            return (m_number + (static_cast<double>(m_fractionPart) / 100));
    }
    FixedPoint2 operator-() const
    {
        return FixedPoint2{-static_cast<double>(*this)};
    }
};

FixedPoint2 operator+(const FixedPoint2 &d, const FixedPoint2 &d2)
{
    return FixedPoint2{static_cast<double>(d) + static_cast<double>(d2)};
}

std::istream& operator>> (std::istream& in, FixedPoint2& fp){
    double d{};
    in >> d;
    fp = FixedPoint2{d};

    return in;
}

bool testDecimal(const FixedPoint2 &fp)
{
    if (fp.m_fractionPart >= 0)
        return fp.m_number >= 0 && fp.m_number < 100;
    else
        return fp.m_number <= 0 && fp.m_number > -100;
}
int main()
{
    assert(FixedPoint2{0.75} == FixedPoint2{0.75});    // Test equality true
    assert(!(FixedPoint2{0.75} == FixedPoint2{0.76})); // Test equality false

    // // Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
    assert(FixedPoint2{0.75} + FixedPoint2{1.23} == FixedPoint2{1.98});    // both positive, no decimal overflow
    assert(FixedPoint2{0.75} + FixedPoint2{1.50} == FixedPoint2{2.25});    // both positive, with decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{-1.23} == FixedPoint2{-1.98}); // both negative, no decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{-1.50} == FixedPoint2{-2.25}); // both negative, with decimal overflow
    assert(FixedPoint2{0.75} + FixedPoint2{-1.23} == FixedPoint2{-0.48});  // second negative, no decimal overflow
    assert(FixedPoint2{0.75} + FixedPoint2{-1.50} == FixedPoint2{-0.75});  // second negative, possible decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{1.23} == FixedPoint2{0.48});   // first negative, no decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{1.50} == FixedPoint2{0.75});   // first negative, possible decimal overflow

    FixedPoint2 a{-0.48};
    assert(static_cast<double>(a) == -0.48);
    assert(static_cast<double>(-a) == 0.48);

    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> a;
    std::cout << "You entered: " << a << '\n';
    assert(static_cast<double>(a) == 5.68);

    return 0;
}