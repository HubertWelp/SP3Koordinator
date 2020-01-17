#ifndef WARTEND_H
#define WARTEND_H
/** @class Wartend
 * @brief Die Klasse bildet den "Wartend"-Zustand im Patientendialogsystem ab.
 *
 * Die Dialogfuehrung im Patientendialogsystem wird ueber ein Zustandsmuster realisiert.
 * Die Klasse Wartend stellt die Funktionalitaet und die Daten fuer den Zustand Wartend zur Verfuegung.
 * Dies umfasst die Implementierung des Ereignisses "rfidEmpfangen".
 * In diesem Zustand wird darauf gewartet, dass ein Patient sein Patientenarmband in den Empfangsbereich
 * des RFID-Readers bewegt.
 *
 * @author Dr. Hubert Welp
 *
 */

#include "../src/dialogzustand.h"



class Wartend : public Dialogzustand
{
public:
    Wartend(Koordinator* dlg);

    virtual ~Wartend();

    /**  @brief Informiert Koordinator ueber Empfang einer RFID-UID
    *
    * Eine empfangene RFID-UID wird mit der Methode an den Koordinator uebergeben und hier
    * zur Ermittlung des dazugehoerigen Patienten verwendet. Mit diesem wird dann im weiteren
    * Verlauf der Koordinator gefuehrt. Die Methode aendert den Dialogzustand zu Begruessend.
    *
    * @param [in] ru empfangene RFID-UID eines Patientenarmbandes
    */
    //void rfidEmpfangen(unsigned long ru);
    void objektAuswaehlen(Bildanalysator_Proxy::ObjektTyp s);
protected:

private:
};

#endif // WARTEND_H
