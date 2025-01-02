#include <array>
#include <iostream>
#include <cassert> // Para usar static_assert
namespace Color {
enum Type
{
    black,
    red,
    blue,
    max_colors
};
// Usando const char* em vez de std::string_viewconstexpr 
    constexpr char* colorName[] = { "black", "red", "blue" };

// Certificando-se de que o tamanho do array colorName seja igual a max_colors
static_assert(sizeof(colorName) / sizeof(colorName[0]) == max_colors, "Tamanho do array colorName não corresponde ao número de cores!");
}
    constexpr const char *getColorName(Color::Type color)
{
    return Color::colorName[color];
}
// Sobrecarga do operador<< para imprimir uma cor
std::ostream& operator<<(std::ostream& out, Color::Type color) {
    return out << getColorName(color);
}
int main()
{
    // Usando um laço para iterar por todas as cores
    for (int i = 0; i < Color::max_colors; ++i) {
    std::cout << static_cast<Color::Type>(i) << '\n';
}
    return 0;
}