#ifndef TIMER_H
#define TIMER_H
#include <thread>
using namespace std;
#include "Subjekt.h"

class Timer : public Subjekt
{
    public:
        Timer(unsigned int stopZeit=1);
        void setStopZeit(unsigned int sz);
        void start();
        void stop();
        int getBusy();

        virtual ~Timer();

    protected:

    private:
        void threadMethode();
        unsigned int m_stopZeit;
        bool m_busy;
        bool m_stop;
        thread m_thread;


};

#endif // TIMER_H
