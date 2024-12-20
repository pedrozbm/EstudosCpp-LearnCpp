#include <iostream>
#include <limits>
#include <vector>

int main(){
    std::vector<int> scoreList{};

    while(true){
        std::cout << "Enter a score (or -1 to finish) ";
        int x{};
        std::cin >> x;

        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if(x == -1)
            break;
        
        scoreList.push_back(x);
    }

    std::cout << "Your list of scores: \n";

    for(const auto& score: scoreList)
        std::cout << score << ' ';

        return 0;
}