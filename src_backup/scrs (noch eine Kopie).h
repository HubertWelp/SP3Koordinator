#ifndef SCRS_H
#define SCRS_H
#include "../src/Subjekt.h"
#include "../src/mqttnode.h"


class SCRS : public Subjekt, public Beobachter
{
public:
    SCRS ();/* verhindert, dass ein Objekt von außerhalb von N erzeugt wird. */
                  // protected, wenn man von der Klasse noch erben möchte
    void setRFIDUID(unsigned long long ru);
    unsigned long long getRFIDUID();
private:
    void aktualisiere(Subjekt* s);
    MQTTNode* m_mqttNode;
    unsigned long long m_RFIDUID;


};

#endif // SCRS
