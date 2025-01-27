#include "Timer.hpp"
#include <iostream>

Timer::Timer(){
};

bool Timer::cronometroTempo(int tempo_long){
    if(contador_long >= tempo_long){
            contador_long = 0;
            return true;
        }else{
            contador_long += 1;
            std::cout << contador_long << '\n';
            return false;
        }
}
Timer t; 