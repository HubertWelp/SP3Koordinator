#ifndef AUSFUEHREND_H
#define AUSFUEHREND_H
/** @class ausfuehrend
 * @brief Die Klasse bildet den "ausfuehrend"-Zustand im SP3Koordinator.
 *

 *
 * @author Dr. Hubert Welp
 *
 */

#include "../src/dialogzustand.h"
#include "../src/timer.h"
#include "../src/Beobachter.h"


class Ausfuehrend : public Dialogzustand, public Beobachter
{
public:
    Ausfuehrend( Koordinator* dlg);
    virtual ~Ausfuehrend();
    /** @brief
     *
    */

    void objektUebergeben();
    void onTimer();

//    void warte();
protected:

private:
    bool m_timerEreignis;
    bool m_objektUebergebenEreignis;
    Timer m_timer;

    // Beobachter interface
public:
    void aktualisiere(Subjekt *s);
};

#endif //ausfuehrend_H
