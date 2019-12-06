#include "patient.h"

Patient::Patient()
{
//    behandlungen.push_back(Behandlung());
//    behandlungen.push_back(Behandlung(2,"MRT"));
//    behandlungen.push_back(Behandlung(5,"Roentgen"));
//    vorName = "Hubert";
//    nachName = "Mustermann";
}

string Patient::getNachName()
{
    return nachName;
}

void Patient::setNachName(string nn)
{
    nachName = nn;
}

string Patient::getVorName()
{
    return vorName;
}

void Patient::setVorName(string vn)
{
    vorName = vn;
}

void Patient::setRFID(unsigned long long ru)
{
    RFID = ru;
}

void Patient::setID(unsigned int id)
{
    iD = id;
}

unsigned int Patient::getID()
{
    return iD;
}

void Patient::addBehandlung(Behandlung b)
{
    behandlungen.push_back(b);
}

list<Behandlung> Patient::getBehandlungen()
{
    return behandlungen;
}
