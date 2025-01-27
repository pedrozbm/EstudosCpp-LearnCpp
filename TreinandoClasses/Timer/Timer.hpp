#ifndef TIMER_H
#define TIMER_H

class Timer {
  private:
    int contador_long;

  public:
    Timer();

    bool cronometroTempo(int tempo_long);
};

#endif
