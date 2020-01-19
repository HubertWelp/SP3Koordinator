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
#define WARTEZEIT_

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

protected:

};

#endif //ausfuehrend_H
