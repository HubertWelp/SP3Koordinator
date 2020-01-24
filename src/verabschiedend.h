#ifndef VERABSCHIEDEND_H
#define VERABSCHIEDEND_H
/** @class Verabschiedend
 * @brief Die Klasse bildet den "Verabschiedend"-Zustand im Patientendialogsystem ab.
 *
 * Die Dialogfuehrung im Patientendialogsystem wird ueber ein Zustandsmuster realisiert.
 * Die Klasse Verabschiedend stellt die Funktionalitaet und die Daten fuer den Zustand Verabschiedend zur Verfuegung.
 * Dies umfasst die Implementierung des Ereignisses "onTimer".
 * Dieser Zustand wird erreicht, wenn der Roboter einen Patienten erfolgreich zu einem ausgewaehlten Ziel gefuehrt hat.
 *
 * @author Dr. Hubert Welp
 *
 */
#include "../src/dialogzustand.h"


class Verabschiedend : public Dialogzustand
{
public:
    Verabschiedend(Koordinator* dlg, int event);
    virtual ~Verabschiedend();
    /** @brief Beendigung des Verabschiedungsbildschirms
    *
    * Mit der Methode wird dem Koordinator mitgeteilt, dass der Verabschiedungsbildschirm beendet werden sollte.
    * Die Methode kann durch einen Timer aufgerufen werden, der bei Eintritt in den Zustand Verabschiedend gestartet wird.
    * Die Methode wechselt den Dialogzustand zu Wartend.
    */
    void onTimer();
    int getAusloeser();

protected:

private:
    /**
     * der parameter [anzeige_status] gibt an welches Ereigniss zu diesem Zustand geführt hat
     * Diese Information wird von der GUI genutzt
     * [ereignis_status] = 0 | Ereignis: ObjektNichtErkannt
     * [ereignis_status] = 1 | Ereignis: onTimer  <30s>
     * [ereignis_status] = 2 | Ereignis: objektUebergeben
     */
    int ereignis_status;
};

#endif // VERABSCHIEDEND_H
