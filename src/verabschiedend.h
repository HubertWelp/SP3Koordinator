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
    Verabschiedend(PDialog* dlg);
    virtual ~Verabschiedend();
    /** @brief Beendigung des Verabschiedungsbildschirms
    *
    * Mit der Methode wird dem PDialog mitgeteilt, dass der Verabschiedungsbildschirm beendet werden sollte.
    * Die Methode sollte durch einen Timer aufgerufen werden, der beim Eintreffen des Roboters am Ziel
    * gestartet wird (also beim Eintritt in den Zustand Verarbschiedend). Die Methode wechselt den Dialogzustand zu Wartend.
    */
    void onTimer();
protected:

private:
};

#endif // VERABSCHIEDEND_H
