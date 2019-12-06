#include "timer.h"
#include <iostream>
#include <unistd.h>


Timer::Timer(unsigned int stopZeit)
: m_stopZeit(stopZeit)
{
    //ctor
    m_busy = false;
    m_stop = false;

}

Timer::~Timer()
{
    //dtor
    if(m_thread.joinable())
        m_thread.join();
//    std::cout << "joined" << std::endl;
}

void Timer::setStopZeit(unsigned int sz)
{
    m_stopZeit = sz;
}

void Timer::stop()
{
    m_stop = true;
    m_busy = false;
}
void Timer::start()
{
    if(!m_busy)
    {
        if(m_thread.joinable())
            m_thread.join();
        m_stop = false;
        m_busy = true;
        m_thread = thread(&Timer::threadMethode,this);
    }
}

int Timer::getBusy()
{
    return m_busy;
}

void Timer::threadMethode()
{
    m_busy = 1;
    unsigned int i=0;
//    cout << "start\n";
    while(!m_stop && i<m_stopZeit)
    {
        sleep(1);
//        cout << "tick" <<endl;
        i++;
    }
    m_busy = 0;
    if(!m_stop)
        benachrichtige();
//    cout << "stop\n";
}
