#include "scrs.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

SCRS::SCRS()
{
    subscribe("RFID1/Tagdaten");

}

unsigned long long SCRS::getRFIDUID()
{
    return receivedTag.getRFIDNr();;
}

void SCRS::onMessageReceived(char *t, char *m)
{
    hexStringToByteStream((unsigned char*)&receivedTag,(m+2),240);
    benachrichtige();
}

void SCRS::byteStreamToHexString(char* hex, const unsigned char* byte, int len)
{
    int i;
    for (i=0; i<len; i++)
    {
        sprintf(hex+i*2, "%02X", byte[i]);
    }
    hex[i*2] = 0;
}

void SCRS::setTagContent(const unsigned char *content, int len)
{
    if(len>sizeof (RFIDTag))
        memcpy(&receivedTag,content,sizeof (RFIDTag));
    else
        memcpy(&receivedTag,content,len);
    benachrichtige();;
}

int SCRS::hexStringToByteStream(unsigned char* byte, const char* hex, int len)
{
    int n=0,ret=1;
    const char* pos = hex;
    n=0;
    do
    {
        ret = sscanf(pos,"%2hhX",&byte[n]);
        if(ret==1)
        {
            n++;
            pos += 2;
        }
    }while(n<len/2 && ret==1);
    return n;
}



