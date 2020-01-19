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


class Ausfuehrend : public Dialogzustand
{
public:
    Ausfuehrend( Koordinator* dlg);
    virtual ~Ausfuehrend();
    /** @brief
     *
    */

    void objektUebergeben();
    void onTimer();
    void warte();
protected:

private:
    bool m_objektUebergebenEreignis;
};

#endif //ausfuehrend_H
