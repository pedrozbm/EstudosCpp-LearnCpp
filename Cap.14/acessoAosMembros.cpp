#include <iostream>

class Date
{
public:
    void print() const
    {
        std::cout << m_year << '/' << m_month << '/' << '/' << m_day;
    }

private:
    int m_year{};
    int m_month{};
    int m_day{};
};

int main()
{
    Date d{};

    d.print();

    return 0;
}