#include <stdio.h>
#include "dialogzustand.h"

Dialogzustand::Dialogzustand(Koordinator* dlg)
    : dialog(dlg)
    , m_ereignis(false)
{
    //ctor
}

Dialogzustand::~Dialogzustand()
{
    //dtor
//    printf("Zustand zerstoert\n");
}

void Dialogzustand::warte(int sek)
{
    int t=0; // verstrichene Zeit in Sekunden
    while(t<sek && !m_ereignis)
    {
        printf("Ausfuehrung: tick %i %i\n",t,m_ereignis);
        sleep(1);
        t++;
    }
    if(!m_ereignis)
        onTimer();
}

void Dialogzustand::stopWarten()
{
    m_ereignis = true;
}

