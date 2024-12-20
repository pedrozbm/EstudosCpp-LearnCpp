// https://www.learncpp.com/cpp-tutorial/classes-and-header-files/

#include <iostream>
#include "Date.h"

Date::Date(int year, int month, int day):
m_year{year}
, m_month{month}
, m_day{day}
{
}
void Date::print() const
{
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
};

int main()
{
    Date d{2015, 10, 14};
    d.print();

    return 0;
}