#include "stdio.h"
#include "ausfuehrend.h"
#include "verabschiedend.h"
#include "fehler.h"
#include "roboter.h"

Ausfuehrend::Ausfuehrend( Koordinator* dlg)
    : Dialogzustand(dlg)
{

    //ctor
    printf("A U S F U E H R E N D\n");
    int x,y,z=0;
    Bildanalysator_Proxy* ba;
    ba=dlg->getBildAnalysator();
    ba->getObjektPosition(&x,&y,&z);
    dlg->getRoboter()->greife(x,y,z,0,0);
    /*Timer* t = dialog->getTimer();
    t->setStopZeit(10);
    t->start();*/


}

Ausfuehrend::~Ausfuehrend()
{
    //dtor
}

void Ausfuehrend::objektUebergeben()
{

    dialog->setZustand(new Verabschiedend(dialog));
    delete this;
}

void Ausfuehrend::onTimer()
{
    dialog->setZustand(new Verabschiedend(dialog));
    delete this;
}


