#include <iostream>
#include <limits>
//https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/

bool hasUnestractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';

// Primeiro, chamamos std::cin.eof()para ver se a extração x chegou ao fim do fluxo de entrada. 
//Se sim, então sabemos que todos os caracteres foram extraídos, o que é um caso de sucesso.
// Caso contrário, deve haver caracteres adicionais ainda dentro std::cinesperando para serem extraídos.
// Nesse caso, chamamos std::cin.peek()para espiar o próximo caractere esperando para ser extraído sem realmente extraí-lo.
//Se esse próximo caractere for um '\n', isso significa que já extraímos todos os caracteres nessa linha de entrada para x. 
//Este também é um caso de sucesso.
// No entanto, se o próximo caractere for algo diferente de '\n', então o usuário deve ter inserido uma entrada estranha que não foi extraída para x. 
//Esse é o nosso caso de falha. Limpamos toda essa entrada estranha e continuevoltamos ao topo do loop para tentar novamente.
}
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Elimina as variaveis que ficam armazenadas no buffer
}


double getDouble()
{
    while (true)
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            continue;
        }

        ignoreLine();
        return x;
    }
}


char getOperator()
{
    while (true)
    {
        std::cout << "Enter one of the following: +, -, *, / \n";
        char op{};
        std::cin >> op;

        switch (op)
        {
        case '+':
        case '-':
        case '*':
        case '/':

            return op;
        default:
            std::cout << "Ops, that input is invalid. Please try again. \n";
        }
    }
}

void printResult(double x, char operation, double y)
{

    std::cout << x << ' ' << operation << ' ' << y << " is ";

    switch (operation)
    {
    case '+':
        std::cout << x + y << '\n';
        return;

    case '-':
        std::cout << x - y << '\n';
        return;

    case '*':
        std::cout << x * y << '\n';
        return;

    case '/':
        std::cout << x / y << '\n';
        return;
    }
}

int main()
{

    double x{getDouble()};
    char operation{getOperator()};
    double y{getDouble()};

    printResult(x, operation, y);
    return 0;
}