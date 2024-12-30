#include <iostream>
#include <array>

int main()
{

    int ttt[3][3]{
        {1, 2, 3},
        {6, 4, 5},
        {6, 7, 8}};
    int tttt[3][3][3];

    // for (std::size_t linha{0}; linha < std::size(ttt); ++linha) // Isso funciona a partir do cpp17
    // std::cout << ttt[linha] << ' ';

    for (std::size_t linha{0}; linha < sizeof(ttt) / sizeof(ttt[0]); ++linha)
    { // isso funciona no cpp11
        std::cout << '\n';
        for (std::size_t coluna{0}; coluna < sizeof(ttt) / sizeof(ttt[0]); ++coluna)
        {
            std::cout << ttt[linha][coluna] << ' ';
        }
    }
    std::cout << "\n";

    // Com foreach:
    for (const auto &e : ttt)
    {
        std::cout << '\n';
        for (const auto &y : e)
        {
            std::cout << y << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}