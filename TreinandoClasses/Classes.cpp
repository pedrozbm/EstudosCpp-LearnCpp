#define CYCLE_TIME 1;
#include <iostream>

class Timer{

private:
    long tempo_l = 0;
public:
    bool CronometroTempo(long tempo){
        // bool ok = false;
        if(tempo_l > tempo){
            tempo_l = 0;
            return true;
        }else{
        tempo_l += CYCLE_TIME;
            std::cout << tempo_l << '\n';
            return false;
        }
}
};


int main(){
    Timer timerParaTeste;
    bool acionamento = false;


    while(!acionamento){
        acionamento = timerParaTeste.CronometroTempo(8000);
        std::cout << acionamento;
    }
}
