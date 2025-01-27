#include "Timer.cpp"
#include "Timer.hpp"

int main(){
    Timer t;

    bool stop = false;
    while(stop == false){
        stop = t.cronometroTempo(5000);
        std::cout << stop << '\n';
    }
}