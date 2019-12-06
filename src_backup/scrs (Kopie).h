#ifndef SCRS_H
#define SCRS_H
#include "../src/Subjekt.h"
#include "../src/mqttnode.h"


class SCRS : public Subjekt
{
public:
    void setRFIDUID(unsigned long long ru);
    unsigned long long getRFIDUID();
    static SCRS* getInstanz();
private:
    static SCRS* m_instanz;
    MQTTNode m_mqttNode;
    unsigned long long m_RFIDUID;
    static void onMessageReceived(char* topic, char* msgContent, int msgLen );
    SCRS ();/* verhindert, dass ein Objekt von außerhalb von N erzeugt wird. */
                  // protected, wenn man von der Klasse noch erben möchte
    SCRS( const SCRS& ); /* verhindert, dass eine weitere Instanz via
     Kopie-Konstruktor erstellt werden kann */
};

#endif // SCRS
