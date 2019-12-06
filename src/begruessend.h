#ifndef BEGRUESSEND_H
#define BEGRUESSEND_H
/** @class Begruessend
 * @brief Die Klasse bildet den "Begruessend"-Zustand im Patientendialogsystem ab.
 *
 * Die Dialogfuehrung im Patientendialogsystem wird ueber ein Zustandsmuster realisiert.
 * Die Klasse Begruessend stellt die Funktionalitaet und die Daten fuer den Zustand Begruessend zur Verfuegung.
 * Dies umfasst die Informationen zur Darstellung des Begruessungsmenue's und die Implementierung der Ereignisse "auswahlAbbrechen" und raumAuswaehlen.
 * In diesem Zustand wird der Patient anhand seines Patientenarmbandes identifziert, mit seinem Namen begruesst und ihm
 * eine Auswahl von moeglichen Zielen angeboten.
 *
 * @author Dr. Hubert Welp
 *
 */

#include "dialogzustand.h"
#include "patient.h"
#include "raum.h"
#include <vector>
using namespace std;

class Begruessend : public Dialogzustand
{
public:
    Begruessend(unsigned long long ru, PDialog* dlg);
    virtual ~Begruessend();
    /** @brief Patient moechte nirgendwohin geleitet werden
    *
    * Mit der Methode wird dem PDialog mitgeteilt, dass der Patient die Raumauswahl abgebrochen hat.
    * Die Methode wechselt den Dialogzustand zu Wartend.
    */
    void auswahlAbbrechen();

    /** @brief waehle anzufahrenden Raum
    *
    * Mit der Methode kann ein Raum bestimmt werden, zu dem der Patient vom Roboter geleitet werden moechte. Die Methode
    * wechselt den Dialogzustand zu Fahrend.
    * @param [in] rNr die laufende Nummer der mit getRaeume() zur Verfuegung gestellten Raumliste, beginnend
    *                   bei 0.
    */
    void raumWaehlen(unsigned short rNr);

    string getVornamePatient();
    string getNachnamePatient();

    /** @brief auswaehlbare Raeume
    *
    *   Liefert eine Liste von Raeumen, die als auswaehlbare Ziele fuer einen vorher identifizierten
    *   Patienten verfuegbar sind.
    *
    * @param [in] keiner
    * @param [out] keiner
    * @return  Liste mit den als Ziele zur Verfuegung stehenden Raeumen.
    */
    list<string> getRaeume();

    void onTimer();

protected:

private:
    Patient m_patient;
    vector<Raum> m_raumListe;

};

#endif // BEGRUESSEND_H
