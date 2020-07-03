#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

class Timer
{
private:
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    std::chrono::duration<double> sec;

    friend std::ostream& operator <<(std::ostream &out, Timer &t);

public:
    Timer();
    void Start();
    void Stop();

};

Timer::Timer()
{

}

void Timer::Start()
{
    start = std::chrono::system_clock::now();
}

void Timer::Stop()
{
    end = std::chrono::system_clock::now();
    sec = end - start;
}

std::ostream& operator <<(std::ostream &out, Timer &t)
{
    return out << t.sec.count();
}
#endif // TIMER_H

