#ifndef DIALOGZUSTAND_H
#define DIALOGZUSTAND_H
/** @class Dialogzustand
* @brief Die Klasse stellt die von den konkreten Zustandsklassen zu implementierende Schnittstelle dar.
*
* Die Klasse Dialogzustand ist die abstrakte Basisklasse fuer die konkreten Zustandsklassen. Sie stellt somit die von diesen zu
* implementierende Schnittstelle dar. Ferner stellt die Klasse eine Assoziation zum zugeordneteten Dialog-Objekt zur Verfuegung,
* welche von den konkreten Zustand-Objekten genutzt werden kann, um Zustandsaenderungen im Dialog zu initiieren.
*
* @author Dr. Hubert Welp
*/

#ifndef Q_MOC_RUN
#include "koordinator.hpp"
#endif

class Dialogzustand
{
public:
    Dialogzustand(Koordinator* dlg);
    virtual ~Dialogzustand();

    virtual void rfidEmpfangen(unsigned long ru) {};
    virtual void auswahlAbbrechen() {};
    virtual void raumWaehlen(unsigned short rNr) {};
    virtual void angekommen() {};
    virtual void onTimer() {};
    virtual void fahrenAbgebrochen(string grund=""){};

    virtual void objektAuswaehlen(Bildanalysator_Proxy::ObjektTyp s){};
    virtual void objektGefunden(){};
    virtual void objektNichtGefunden(){};
    virtual void objektUebergeben(){};

    void setZustand(Dialogzustand* z);
protected:
    Koordinator* dialog;
private:


};

#endif // DIALOGZUSTAND_H
