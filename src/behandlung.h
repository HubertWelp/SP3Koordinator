#ifndef BEHANDLUNG_H
#define BEHANDLUNG_H
#include <string>
using namespace std;
class Behandlung
{
public:
    Behandlung(unsigned int i=1, string b="EKG")
    {
        iD = i;
        bezeichnung =b;
    }
    string getBezeichnung(){return bezeichnung;};
    void setBezeichnung(string bez);
    void setID(unsigned int id);
    unsigned int getID();
private:
    unsigned int iD;
    string bezeichnung;
};
#endif // BEHANDLUNG_H

