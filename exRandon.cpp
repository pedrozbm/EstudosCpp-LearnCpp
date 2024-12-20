#include <iostream>
#include "C:\Repositorios\Estudos\c++\Cap.8\Random.h"
#include <limits>

int getGuess(int count)
{
    
    while (true)
    {
        std::cout << "Guess # " << count << " : ";
        int guess{};
        std::cin >> guess;
        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (guess < 1 || guess > 100)
        {            
            continue;
        }
    return guess;
   }
}

bool playHiLo(int guesses, int min, int max)
{

    std::cout << "Lets's plsy a game. I'm thinking of a number between " << min << " and " << max << " You have " << guesses << " tries to guess what it is. \n";
    int number{Random::get(min, max)};

    for (int count{1}; count <= guesses; ++count)
    {
        
        int guess{getGuess(count)};

        if (guess > number)
        {
            std::cout << "Your guess is too high \n";
        }
        else if (guess < number)
        {
            std::cout << "Yor guess is too low \n";
        }
        else
        {
            std::cout << "Correct! You win! \n";
            return true;
        }
    }
    std::cout << "Sorry, you lose. The correct number was " << number << '\n';
    return false;
}

bool playAgain()
{

    while (true)
    {
        char ch{};
        std::cout << "would you like to play again (y/n)? ";
        std::cin >> ch;

        switch (ch)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        }
    }
}
int main()
{

    constexpr int guesses{7};
    constexpr int min{1};
    constexpr int max{100};

    do
    {
        playHiLo(guesses, min, max);
    } while (playAgain());

    std::cout << "Thank you for playing";
}
