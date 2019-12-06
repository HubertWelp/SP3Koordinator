#ifndef FAHREND_H
#define FAHREND_H
/** @class Fahrend
 * @brief Die Klasse bildet den "Fahrend"-Zustand im Patientendialogsystem ab.
 *
 * Die Dialogfuehrung im Patientendialogsystem wird ueber ein Zustandsmuster realisiert.
 * Die Klasse Fahrend stellt die Funktionalitaet und die Daten fuer den Zustand Fahrend zur Verfuegung.
 * Dies umfasst die Implementierung der Ereignisse "angekommen" und "fahrenAbgebrochen".
 * Dieser Zustand wird angenommen, waehrend der Roboter einen Patienten zu einem ausgewaehlten Ziel geleitet.
 *
 * @author Dr. Hubert Welp
 *
 */

#include "../src/dialogzustand.h"


class Fahrend : public Dialogzustand
{
public:
    Fahrend(PDialog* dlg);
    virtual ~Fahrend();
    /** @brief Roboter ist am Ziel angekommen
    *
    * Mit der Methode wird dem PDialog mitgeteilt, dass der Roboter das ausgewaehlte Ziel erreicht hat.
    * Die Methode wechselt den Dialogzustand zu Verabschiedend.
    */
    void angekommen();

    /** @brief Roboter hat Fahrt abgebrochen
    *
    * Mit der Methode wird dem PDialog mitgeteilt, dass der Roboter das ausgewaehlte Ziel nicht erreichen konnte
    * und die Fahrt abgebrochen hat. .
    * Die Methode wechselt den Dialogzustand zu Fehler.
    *
    * @param grund Der Grund fuer den Abbruch der Fahrt
    */
    void fahrenAbgebrochen(string grund="");

protected:

private:
};

#endif // FAHREND_H
