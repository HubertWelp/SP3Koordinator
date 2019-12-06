#include "dd.h"
#include <iostream>
using namespace std;

DD::DD(int argc, char **argv)
{
       m_scrs = new SCRS();
       m_scrs->anmelden(this);
       m_roboter = new Roboter(argc,argv);
       m_roboter->anmelden(this);
}

void DD::aktualisiere(Subjekt *s)
{
    if(dynamic_cast<SCRS*>(s))
        handleSCRSNachrichten();
    if(dynamic_cast<Roboter*>(s))
        handleRoboterNachrichten();
}

DD::~DD()
{
    if(m_roboter)
        delete m_roboter;
}

void DD::handleSCRSNachrichten()
{
    cout << "RFIDUID empfangen: " << m_scrs->getRFIDUID() << endl;
}

void DD::handleRoboterNachrichten()
{
    cout << "Roboterstatus empfangen: " << m_roboter->getStatus()    << endl;
}
