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
	// We'll use a static std::vector to cache calculated results
	static std::vector<int> results{ 0, 1 };

	// If we've already seen this count, then use the cache'd result
	if (count < results.size())
		return results[count];

	// Otherwise calculate the new result and add it
	results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
	return results[count];
}

// And a main program to display the first 13 Fibonacci numbers
int main()
{
    Timer t;
	for (int count { 0 }; count < 13; ++count)
		std::cout << fibonacci(static_cast<std::size_t>(count)) << ' ';


    std::cout << "Time elapsed: "<<t.elapsed() << "seconds \n";

    return 0;
}