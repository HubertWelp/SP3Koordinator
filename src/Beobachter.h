#pragma once
/** @class Beobachter
 * @brief Interfaceklasse fuer Observer-Pattern
 *
 * Diese Klasse stellt die Schnittstelle dar, die Beobachter eines Subjekt's implementieren muessen.
 *
 * @author Dr. Hubert Welp
 *
 */
class Subjekt;
class Beobachter
{
public:

    /** @brief Standardkonstruktor
    *
    * keine Implementierung
    *
    *
    */
    Beobachter(void);

    /** @brief Call-Back-Methode fuer Subjekt
    *
    * Diese Methode wird von einem Subjekt-Objekt aufgerufen, bei der sich der Beobachter registriert hat,
    * falls sich der Zustand des Subjekts veraendert hat.
    * Als rein virtuelle Funktion muss sie von der beobachtenden Klasse implementiert werden.
    * Hier kann sich der Beobachter vom Subjekt die aktuellen Daten holen und sich so mit diesem synchornisieren.
    *
    * @param [in] s Subjekt, von dem die Benachrichtigung kommmt
    *
    */
    virtual void aktualisiere(Subjekt* s)=0;

    /** @brief Destruktor
    *
    * keine Implementierung
    *
    */
    virtual ~Beobachter(void)=0;
};

