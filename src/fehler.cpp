#include "fehler.h"
#include "wartend.h"
#include <iostream>
using namespace std;
Fehler::Fehler(PDialog* dlg)
    : Dialogzustand(dlg)
{
    printf("F E H L E R\n");

    Timer* t = dialog->getTimer();
    t->setStopZeit(15);
    t->start();


}


Fehler::~Fehler()
{
    //dtor
    //    Timer* t = dialog->getTimer();
    //    t->stop();
}
void Fehler::onTimer()
{
//    cout << "Fehler::onTimer()" << endl;
    dialog->setZustand(new Wartend(dialog));
    delete this;
}
