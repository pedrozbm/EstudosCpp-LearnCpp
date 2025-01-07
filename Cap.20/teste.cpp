#include <iostream>
#include <chrono>
using namespace std;

class Timer{
    private: 
        using Clock = std::chrono::steady_clock;
        using Second = std::chrono::duration<double, std::ratio<1>>;

        std::chrono::time_point<Clock> m_beg{Clock::now()};

    public:
        void reset(){
            m_beg = Clock::now();
        }

        double elapsed() const
        {
            return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
        }
};
int main() {
    double num1, num2;
    char operacao;

    // Solicita ao usuário os dois números e a operação
    cout << "Digite o primeiro número: ";
    cin >> num1;
    
    cout << "Digite o operador (+, -, *, /): ";
    cin >> operacao;
    
    cout << "Digite o segundo número: ";
    cin >> num2;
    Timer t;
    // Realiza a operação dependendo do operador escolhido
    switch(operacao) {
        case '+':
            cout << "Resultado: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Resultado: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Resultado: " << num1 * num2 << endl;
            break;
        case '/':
            // Verifica se o segundo número é zero para evitar divisão por zero
            if(num2 != 0) {
                cout << "Resultado: " << num1 / num2 << endl;
            } else {
                cout << "Erro: Divisão por zero não é permitida." << endl;
            }
            break;
        default:
            cout << "Operação inválida!" << endl;
    }
    std::cout << "Time elapsed: "<<t.elapsed() << "seconds \n";

    return 0;
}
