#include <iostream>
#include <conio.h>

int main() {
    std::cout << "Pressione as setas do teclado (ESC para sair)\n";

    while (true) {
        int ch = _getch();

        // Teclas especiais (setas, F1, etc.) começam com 0 ou 224
        if (ch == 0 || ch == 224) {
            int arrow = _getch();

            switch (arrow) {
                case 72:
                    std::cout << "Seta para CIMA\n";
                    break;
                case 80:
                    std::cout << "Seta para BAIXO\n";
                    break;
                case 75:
                    std::cout << "Seta para ESQUERDA\n";
                    break;
                case 77:
                    std::cout << "Seta para DIREITA\n";
                    break;
            }
        }
        else if (ch == 27) { // ESC
            std::cout << "Saindo...\n";
            break;
        }
    }

    return 0;
}