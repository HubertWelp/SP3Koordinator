#include "scrs.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

SCRS::SCRS()
{
    m_mqttNode = new MQTTNode();
    m_mqttNode->anmelden(this);
    m_mqttNode->subscribe("test");
    m_RFIDUID=0;
}

void SCRS::setRFIDUID(unsigned long long ru)
{
    m_RFIDUID = ru;
    cout << "RFIDUID: " << ru << endl;
    benachrichtige();
}

unsigned long long SCRS::getRFIDUID()
{
    return m_RFIDUID;
}

void SCRS::aktualisiere(Subjekt *s)
{
    char msg[10000];
    if(dynamic_cast<MQTTNode*>(s))
    {
        if(m_mqttNode)
        {
            m_mqttNode->getLastMessageReceived(msg);
            unsigned long long ru=atoi(msg);
            setRFIDUID(ru);
        }

    }
}




