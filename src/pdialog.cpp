#include "pdialog.hpp"
#include "wartend.h"
#include <iostream>
PDialog::PDialog(int argc, char **argv)
{
    //ctor
    m_scrs = new SCRS();
    m_scrs->anmelden(this);
    m_roboter = new Roboter(argc,argv);
    m_roboter->anmelden(this);
    m_timer = new Timer();
    m_timer->anmelden(this);
    zustand = nullptr;
}

PDialog::~PDialog()
{
    //dtor
    delete m_scrs;
    delete m_roboter;
    delete m_timer;
}

void PDialog::aktualisiere(Subjekt *s)
{
    if(dynamic_cast<SCRS*>(s))
        handleSCRSNachrichten();
    if(dynamic_cast<Roboter*>(s))
        handleRoboterNachrichten();
    if(dynamic_cast<Timer*>(s))
        handleTimerNachrichten();}


void PDialog::handleSCRSNachrichten()
{
    cout << "RFIDUID empfangen: " << m_scrs->getRFIDUID() << endl;
    rfidEmpfangen( m_scrs->getRFIDUID());
}

void PDialog::handleRoboterNachrichten()
{
    string nachricht =  m_roboter->getStatus();
//    cout << "Roboterstatus empfangen: " <<  nachricht  << endl;
    if(nachricht=="3")
    {
        angekommen();
    }else
    {
        fahrenAbgebrochen();
    }

//    {
////        onTimer();
//    }
}

void PDialog::handleTimerNachrichten()
{
    onTimer();
}

void PDialog::setZustand(Dialogzustand* z)
{
    zustand = z;
    this->benachrichtige();
    Q_EMIT changed();
}

void PDialog::rfidEmpfangen(unsigned long ru)
{
    zustand->rfidEmpfangen(ru);
}
void PDialog::auswahlAbbrechen()
{
    zustand->auswahlAbbrechen();
}
void PDialog::raumWaehlen(unsigned short rNr)
{
    zustand->raumWaehlen(rNr);
}
void PDialog::angekommen()
{
    zustand->angekommen();
}
void PDialog::onTimer()
{
    zustand->onTimer();

}
void PDialog::fahrenAbgebrochen(string grund)
{
    zustand->fahrenAbgebrochen(grund);
}


Dialogzustand* PDialog::getDialogzustand()
{
    return zustand;
}


Roboter* PDialog::getRoboter()
{
    return m_roboter;
}


Timer* PDialog::getTimer()
{
    return m_timer;
}

