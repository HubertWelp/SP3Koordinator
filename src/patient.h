#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include "behandlung.h"

using namespace std;
#include <list>
class Patient
{
public:
    Patient();
    string getNachName();
    void setNachName(string nn);
    string getVorName();
    void setVorName(string vn);
    unsigned long long getRFID();
    void setRFID(unsigned long long ru);
    void setID(unsigned int id);
    unsigned int getID();



    void addBehandlung(Behandlung b);
    list<Behandlung> getBehandlungen();
private:
    string nachName;
    string vorName;
    unsigned long long RFID;
    unsigned int iD;
    list<Behandlung> behandlungen;
};

#endif // PATIENT_H
