#include "scrs.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
SCRS* SCRS::m_instanz=NULL;
SCRS::SCRS()
{
    m_mqttNode.setMsgRcvdCallback(SCRS::onMessageReceived);
    m_mqttNode.subscribe("test");
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

SCRS* SCRS::getInstanz()
{
    if(m_instanz)
        return m_instanz;
    else
        return (m_instanz = new SCRS());
}

void SCRS::onMessageReceived(char *topic, char *msgContent, int msgLen)
{
    unsigned long long ru=atoi(msgContent);
    if(m_instanz)
        m_instanz->setRFIDUID(ru);
}

