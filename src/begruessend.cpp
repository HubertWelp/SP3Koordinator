#include <stdio.h>
#include "begruessend.h"
#include "wartend.h"
#include "kis.h"
#include "gis.h"
#include <list>
#include <iterator>

Begruessend::Begruessend(unsigned long long ru, Koordinator* dlg)
    : Dialogzustand(dlg)
{
    //ctor
    printf("B E G R skjdU E S S U N G\n");
    KIS k;
    m_patient = k.getPatientByRFID(ru);
    Timer* t = dialog->getTimer();
    t->setStopZeit(25);
    t->start();
}

Begruessend::~Begruessend()
{
    //dtor
    Timer* t = dialog->getTimer();
    if(t->getBusy())
    {
        cout << "Timer busy - stop timer" << endl;
        t->stop();
    }
}

void Begruessend::auswahlAbbrechen()
{
    dialog->setZustand(new Wartend(dialog));
    delete this;
}

void Begruessend::raumWaehlen(unsigned short rNr)
{
    Roboter* roboter = dialog->getRoboter();
    if(rNr>=0 && rNr<m_raumListe.size())
    {
        Koordinaten rk = m_raumListe[rNr].getKoordinaten();
        roboter->publish(rk.x,rk.y);
    }
    delete this;
}

string Begruessend::getVornamePatient()
{
    return m_patient.getVorName();
}
string Begruessend::getNachnamePatient()
{
    return m_patient.getNachName();
}

list<string> Begruessend::getRaeume()
{
    list<string> raeume;
    stringstream ss;
    string rs;

    Raum r;
    vector<Raum>::iterator itr;
    list<Behandlung> bl;
    list<Behandlung>::iterator itb;
    GIS gis;

    bl = m_patient.getBehandlungen();
    for(itb=bl.begin();itb!=bl.end();itb++)
    {
        r = gis.getRaumByBehandlung(*itb);
        ss.str("");
        if(r.getRaumNummer()>9999)
        {
            ss << r.getGebaeudeNummer() << "/" <<  "---" << " (" << itb->getBezeichnung() <<")";
        }else
        {
            ss << r.getGebaeudeNummer() << "/" <<  r.getRaumNummer() << " (" << itb->getBezeichnung() <<")";
        }
        rs = ss.str();
        raeume.push_back(rs);
        m_raumListe.push_back(r);
    }

    for(itr=m_raumListe.begin();itr!=m_raumListe.end();itr++)
    {

    }

    return raeume;
}

void Begruessend::onTimer()
{
    cout << "fertig" << endl;
    auswahlAbbrechen();
}

