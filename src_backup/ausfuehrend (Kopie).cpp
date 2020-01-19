#include "stdio.h"
#include "ausfuehrend.h"
#include "verabschiedend.h"
#include "fehler.h"
#include "roboter.h"

Ausfuehrend::Ausfuehrend( Koordinator* dlg)
    : Dialogzustand(dlg)
    , m_timerEreignis(false)
    , m_objektUebergebenEreignis(false)
{

    //ctor
    printf("A U S F U E H R E N D\n");
    int x,y,z=0;
    Bildanalysator_Proxy* ba;
    ba=dlg->getBildAnalysator();
    ba->getObjektPosition(&x,&y,&z);
    dlg->getRoboter()->greife(x,y,z,0,0);
    m_timer.anmelden(this);
    m_timer.setStopZeit(10);
    m_timer.start();
}

Ausfuehrend::~Ausfuehrend()
{
    //dtor
}

void Ausfuehrend::objektUebergeben()
{
//    m_objektUebergebenEreignis=true;
    dialog->setZustand(new Verabschiedend(dialog));
    delete this;
}

void Ausfuehrend::onTimer()
{
    printf("Ausfuehrend::onTimer\n");
//    m_timerEreignis=true;
    dialog->setZustand(new Verabschiedend(dialog));
    delete this;
}

void Ausfuehrend::aktualisiere(Subjekt *s)
{
    onTimer();
}

//void Ausfuehrend::warte()
//{
//    Timer* t = dialog->getTimer();
//    t->setStopZeit(10);
//    t->start();
//    while(!m_timerEreignis && !m_objektUebergebenEreignis)
//    {
//        printf("Ausfuehrung: tick %i %i\n",m_timerEreignis,m_objektUebergebenEreignis);
//        sleep(1);
//    }
//    if(m_timerEreignis)
//    {
//        dialog->setZustand(new Verabschiedend(dialog));
//        delete this;
//    }else if(m_objektUebergebenEreignis)
//    {
//        dialog->setZustand(new Verabschiedend(dialog));
//        delete this;
//    }
//}


