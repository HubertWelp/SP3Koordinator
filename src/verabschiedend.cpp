#include <stdio.h>
#include "verabschiedend.h"
#include "wartend.h"


Verabschiedend::Verabschiedend(PDialog* dlg)
    : Dialogzustand(dlg)
{
    //ctor
    printf("V E R A B S C H I E D U N G\n");
    Timer* t = dialog->getTimer();
    t->setStopZeit(10);
    t->start();

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
