#include "raum.h"
#include <iostream>
Raum::Raum()
{

    koordinaten.x = 10;
    koordinaten.y = 15;
    gebNr = 8;
    raumNr = 305;
}

Koordinaten Raum::getKoordinaten()
{
    return koordinaten;
}

void Raum::setKoordinaten(Koordinaten k)
{
    koordinaten = k;
    std::cout << "x=" << koordinaten.x << "  y=" << koordinaten.y << std::endl;
}

void Raum::setGebaeudeNummer(unsigned int gnr)
{
    gebNr = gnr;
}

unsigned int Raum::getGebaeudeNummer()
{
    return gebNr;
}

unsigned int Raum::getRaumNummer()
{
    return raumNr;
}

void Raum::setRaumNummer(unsigned int rnr)
{
    raumNr = rnr;
}

void Raum::setVerwendung(string v)
{
    verwendung = v;
}

string Raum::getVerwendung()
{
    return verwendung;
}
