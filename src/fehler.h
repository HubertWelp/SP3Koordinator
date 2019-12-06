#ifndef FEHLER_H
#define FEHLER_H
/** @class Fehler
 * @brief Die Klasse bildet den "Fehler"-Zustand im Patientendialogsystem ab.
 *
 * Die Dialogfuehrung im Patientendialogsystem wird ueber ein Zustandsmuster realisiert.
 * Die Klasse Fehler stellt die Funktionalitaet und die Daten fuer den Zustand Fehler zur Verfuegung.
 * Dies umfasst die Implementierung des Ereignisses "onTimer".
 * Dieser Zustand wird angenommen, wenn der Roboter einen Geleitvorgang nicht ortungsgemaess beenden konnte.
 *
 * @author Dr. Hubert Welp
 *
 */

#include "../src/dialogzustand.h"
#include "timer.h"

class Fehler : public Dialogzustand
{
public:
    Fehler(PDialog* dlg);
    virtual ~Fehler();
    /** @brief Beendigung des Verabschiedungsbildschirms
    *
    * Mit der Methode wird dem PDialog mitgeteilt, dass der Fehlerbildschirm beendet werden sollte.
    * Die Methode sollte durch einen Timer aufgerufen werden, der beim Abbruch eines Geleitvorganges
    * gestartet wird (also beim Eintritt in den Fehler-Zustand). Die Methode wechselt den Dialogzustand zu Wartend.
    */
    void onTimer();
private:
//    Timer m_timer;
};

#endif // FEHLER_H
