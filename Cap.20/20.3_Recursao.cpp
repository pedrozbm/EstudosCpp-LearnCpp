#include <iostream>
#include <chrono>
#include <vector>

//Funcoes recursivas chamam a si mesma 
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
int fibonacci(std::size_t count)
{
    // Usaremos um std::vector estático para armazenar em cache os resultados calculados
	static std::vector<int> results{ 0, 1 };

    // Se já vimos esse valor, então use o resultado armazenado em cache
	if (count < results.size())
		return results[count];

    // Caso contrário, calcule o novo resultado e adicione-o
	results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
	return results[count];
}

// E um programa principal para exibir os primeiros 13 números de Fibonacci
int main()
{
    Timer t;
	for (int count { 0 }; count < 13; ++count)
		std::cout << fibonacci(static_cast<std::size_t>(count)) << ' ';


    std::cout << "Time elapsed: "<<t.elapsed() << "seconds \n";

    return 0;
}