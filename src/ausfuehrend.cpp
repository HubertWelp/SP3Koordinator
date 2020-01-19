#include "stdio.h"
#include "ausfuehrend.h"
#include "verabschiedend.h"
#include "fehler.h"
#include "roboter.h"

Ausfuehrend::Ausfuehrend( Koordinator* dlg)
    : Dialogzustand(dlg)
    , m_objektUebergebenEreignis(false)
{

    //ctor
    printf("A U S F U E H R E N D\n");
    int x,y,z=0;
    int breite = 0;
    float phi;

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
    t->setStopZeit(10);
    t->start();*/


}

Ausfuehrend::~Ausfuehrend()
{
    //dtor
}

void Ausfuehrend::objektUebergeben()
{
    m_objektUebergebenEreignis=true;
    dialog->setZustand(new Verabschiedend(dialog,2));
    delete this;
}

void Ausfuehrend::onTimer()
{
    dialog->setZustand(new Verabschiedend(dialog,1));
    delete this;
}

void Ausfuehrend::warte()
{
    int t=0; // verstrichene Zeit in Sekunden
    while(t<30 && !m_objektUebergebenEreignis)
    {
        printf("Ausfuehrung: tick %i %i\n",t,m_objektUebergebenEreignis);
        sleep(1);
        t++;
    }
    if(!m_objektUebergebenEreignis)
        onTimer();
}


