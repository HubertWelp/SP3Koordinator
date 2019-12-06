#ifndef BEHANDLUNGSRAUM_H
#define BEHANDLUNGSRAUM_H
#include <string>
#include "behandlung.h"
#include <list>
using namespace std;
struct Koordinaten
{
    double x;   // x-Position in m
    double y;   // y-Position in m
};

class Raum
{
public:
    Raum();
    /** @brief liefert die x,y-Koordinaten eines Raumes
     *
     * @return Koordinaten des Raumes
     *
     * */
    Koordinaten getKoordinaten();
    void setKoordinaten(Koordinaten k);
    unsigned int getGebaeudeNummer();
    void setGebaeudeNummer(unsigned int gnr);
    unsigned int getRaumNummer();
    void setRaumNummer(unsigned int rnr);
    void setVerwendung(string v);
    string getVerwendung();

private:
    unsigned int gebNr;
    unsigned int raumNr;
    Koordinaten koordinaten;
    string verwendung;
};

#endif // BEHANDLUNGSRAUM_H
