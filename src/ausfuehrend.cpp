#include "stdio.h"
#include "ausfuehrend.h"
#include "verabschiedend.h"

#include "roboter.h"

Ausfuehrend::Ausfuehrend( Koordinator* dlg)
    : Dialogzustand(dlg)
{

    //ctor
    printf("A U S F U E H R E N D\n");
    float x,y,z=0;
    float breite = 0;
    float phi=0;

    Bildanalysator_Proxy* ba;
    ba=dlg->getBildAnalysator();

    phi = ba->getObjektOrientierung();
    breite = ba->getObjektBreite();
    ba->getObjektPosition(&x,&y,&z);
    /*testen der ros rueckmeldung
     * dlg->getRoboter()->changeSubscriberTopic("robot/status");
     * dlg->getRoboter()->publish("hallo");
    */
    dlg->getRoboter()->greife(x,y,z,phi,breite);
    /*Timer* t = dialog->getTimer();
    t->stop();
    t->setStopZeit(10);
    t->start();*/
}

Ausfuehrend::~Ausfuehrend()
{
    //dtor
}

void Ausfuehrend::objektUebergeben()
{
//    stopWarten();
    dialog->setZustand(new Verabschiedend(dialog,2));
    delete this;

}

void Ausfuehrend::onTimer()
{
    dialog->setZustand(new Verabschiedend(dialog,1));
    delete this;

}


