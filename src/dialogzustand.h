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



    virtual void objektAuswaehlen(Bildanalysator_Proxy::ObjektTyp s){}
    virtual void objektErkannt(){}
    virtual void objektNichtErkannt(){}
    virtual void objektUebergeben(){}
    virtual void onTimer() {}

    void setZustand(Dialogzustand* z);

    /** @brief Setzt den Zustand in den Wartemodus
    *
    * Mit der Methode kann der aktuelle Zustand für sek Sekunden in den Ruhezustand versetzt. Nach der Wartezeit wird das
    * Ereignis onTimer ausgeloest. Die Warten kann mit der Methode stopWarten unterbrochen werden. In diesem Fall wird kein
    * onTimer-Ereignis ausgeloest. Die Unterbrechung der Wartezeit koennte z.B. durch ein anderes Ereignis notwendig sein.
    *
    * @param sek [in] Wartezeit in Sekunden
    */
    void warte(int sek);
    /** @brief Wartemodus abbrechen
    *
    * Mit der Methode wird der Wartemodus des Zustands beendet.
    */
    void stopWarten();
protected:
    Koordinator* dialog;
    int m_ereignis;
private:


};

#endif // DIALOGZUSTAND_H
