#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

class Timer
{
private:
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;

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
    std::chrono::duration<double> sec = end - start;
    std::cout << sec.count() << " sec.\n";
}

#endif // TIMER_H

