#ifndef SUCHEND_H
#define SUCHEND_H
/** @class suchend
 * @brief Die Klasse bildet den "SUCHEND"-Zustand im SP3Koordinator.
 *

 *
 * @author Dr. Hubert Welp
 *
 */

#include "../src/dialogzustand.h"


class Suchend : public Dialogzustand
{
public:
    Suchend(Bildanalysator_Proxy::ObjektTyp o ,Koordinator* dlg);
    virtual ~Suchend();
    /** @brief
     *
    */
    void objektErkannt();
    void objektNichtErkannt();
    int getSuessigkeit();
protected:

private:
    Bildanalysator_Proxy::ObjektTyp m_suessigkeit;
};

#endif //SUCHEND_H
