#include "koordinator.hpp"
#include "wartend.h"
#include <iostream>
Koordinator::Koordinator(int argc, char **argv)
{
    //ctor
    m_bildanalysatorProxy = new Bildanalysator_Proxy();
    m_bildanalysatorProxy->anmelden(this);
    m_roboter = new Roboter(argc,argv);
    m_roboter->anmelden(this);
    m_timer = new Timer();
    m_timer->anmelden(this);
    zustand = nullptr;
}

Koordinator::~Koordinator()
{
    //dtor
    delete m_bildanalysatorProxy;
    delete m_roboter;
    delete m_timer;
}

void Koordinator::aktualisiere(Subjekt *s)
{


    if(dynamic_cast<Bildanalysator_Proxy*>(s))
    {handleBildanalysatorNachrichten();
        printf("\n bildanalysator erkannt---\n");
    }
    if(dynamic_cast<Roboter*>(s))
    {handleRoboterNachrichten();
        printf("\n Rueckmeldung vom Roboter\n");
    }
    if(dynamic_cast<Timer*>(s))
        handleTimerNachrichten();
}


void Koordinator::handleBildanalysatorNachrichten()
{
//    cout << "RFIDUID empfangen: " << m_bildanalysatorProxy->getRFIDUID() << endl;
//    rfidEmpfangen( m_bildanalysatorProxy->getRFIDUID());
    printf("\nhandleBilananalysatorn");

    //ueberpruefen welche Nachricht
    if(m_bildanalysatorProxy->getNichtErkannt())
    {
        objektNichtErkannt();
    }
    else
    {
        objektErkannt();
    }

}

void Koordinator::handleRoboterNachrichten()
{
    string nachricht =  m_roboter->getStatus();
    cout << "Roboterstatus empfangen: " <<  nachricht  << endl;
    objektUebergeben();

//    {
////        onTimer();
//    }
}

void Koordinator::handleTimerNachrichten()
{
    onTimer();
}

void Koordinator::setZustand(Dialogzustand* z)
{
    zustand = z;
    this->benachrichtige();
    Q_EMIT changed();
}

void Koordinator::rfidEmpfangen(unsigned long ru)
{
    zustand->rfidEmpfangen(ru);
}
void Koordinator::auswahlAbbrechen()
{
    zustand->auswahlAbbrechen();
}
void Koordinator::raumWaehlen(unsigned short rNr)
{
    zustand->raumWaehlen(rNr);
}
void Koordinator::angekommen()
{
    zustand->angekommen();
}
void Koordinator::onTimer()
{
    zustand->onTimer();

}
void Koordinator::fahrenAbgebrochen(string grund)
{
    zustand->fahrenAbgebrochen(grund);
}


Dialogzustand* Koordinator::getDialogzustand()
{
    return zustand;
}


Roboter* Koordinator::getRoboter()
{
    return m_roboter;
}


Timer* Koordinator::getTimer()
{
    return m_timer;
}

Bildanalysator_Proxy* Koordinator::getBildAnalysator()
{
    return m_bildanalysatorProxy;
}


void Koordinator::objektAuswaehlen(Bildanalysator_Proxy::ObjektTyp s)
{
    zustand->objektAuswaehlen(s);
}

void Koordinator::objektErkannt()
{
    zustand->objektErkannt();
}

void Koordinator::objektUebergeben()
{
    zustand->objektUebergeben();
}

void Koordinator::objektNichtErkannt()
{
    zustand->objektNichtErkannt();
}



