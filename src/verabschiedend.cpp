#include <stdio.h>
#include "verabschiedend.h"
#include "wartend.h"


Verabschiedend::Verabschiedend(Koordinator* dlg, int event)
    : Dialogzustand(dlg)
{
    //ctor
    printf("V E R A B S C H I E D E N D\n");
    ereignis_status = event;
    std::cout<<"\nAusloesendes Ereignis: "<<ereignis_status<<"\n";
//    Timer* t = dialog->getTimer();
//    t->stop();
//    t->setStopZeit(5);
//    t->start();
}

Verabschiedend::~Verabschiedend()
{
    //dtor
}
void Verabschiedend::onTimer()
{
//    cout << "Verabschiedend::onTimer()" << endl;
    dialog->setZustand(new Wartend(dialog));
    delete this;
}



