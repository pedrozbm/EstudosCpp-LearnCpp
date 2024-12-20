//https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/

#include <iostream>

class Storage
{
private:
    int m_nvalue{};
    double m_dvalue{};

public:
    Storage(int nValue, double dValue) : m_nvalue{nValue}, m_dvalue{dValue} {}

    friend class Display; // display eh amiga de storage, entao consegue acessar os membros privados
};

class Display
{
private:
    bool m_displayIntFirst{};

public:
    Display(bool displayIntFirst) : m_displayIntFirst{displayIntFirst} {}

    void displayStorage(const Storage &storage)
    {
        if (m_displayIntFirst)
        {
            std::cout << storage.m_nvalue << ' ' << storage.m_dvalue << '\n';
        }else {
            std::cout << storage.m_dvalue << ' ' << storage.m_nvalue << '\n';
        }
    }
    void setDisplayIntFirst(bool b)
    {
        m_displayIntFirst = b;
    }
};

int main()
{
    Storage storage{5, 6.7};
    Display display{false};

    display.displayStorage(storage);

    display.setDisplayIntFirst(true);
    display.displayStorage(storage);

    return 0;
}