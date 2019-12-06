#pragma once
/** @class Subjekt
 * @brief Klasse zur Verwaltung von Beobachtern im Observer-Pattern
 *
 * Klassen sollten von Subjekt abgeleitet werden, falls sie in Verbindung mit Beobachter-Klassen das
 * Observer-Pattern implementieren wollen. Subjekt stellt die Funktionalitaet zur Verwaltung
 * der Beobachter zur Verfuegung.
 *
 * @author Dr. Hubert Welp
 *
 */

#include <list>
using namespace std;
#include "../src/Beobachter.h"
class Subjekt
{
private:
		list<Beobachter *> beobachter;
public:

    /** @brief Standardkonstruktor
    *
    * keine Implementierung
    *
    *
    */
	Subjekt(void);

    /** @brief registriert einen Beobachter
    *
    * Beobachter koennen sich bei einem Subjekt registrieren. Sie werden in die Beobachterliste aufgenommen
    * und bei folgenden Benachrichtigungen ueber Zustandsaenderungen beruecksichtigt.
    *
    * @param [in] beobachter Zu registrierendes Objekt vom Typ Beobachter
    *
    */
	void anmelden(Beobachter * beobachter);

    /** @brief entfernt einen registrierten Beobachter
    *
    *  Entfernt uebergebenen Beobachter aus der Liste, falls dieser eingetragen ist.
    *
    * @param [in] beobachter Zu entfernendes Objekt vom Typ Beobachter.
    *
    */
	void abmelden(Beobachter * beobachter);

    /** @brief benachrichtigt alle Beobachter ueber Aenderungen
    *
    * Die Methode benachrichtigt alle mit anmelden() registrierten Beobachter, in dem sie die dort
    * implementierte Methode aktualisiere() aufruft. benachrichtige() sollte bei jeder Aenderung des
    * Ojektzustandes aufgerufen werden.
    *
    */
    void benachrichtige(void);

    /** @brief Destruktor
    *
    * keine Implementierung
    *
    */
    virtual ~Subjekt(void);
};

