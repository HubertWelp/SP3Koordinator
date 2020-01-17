#include "Bildanalysator_Proxy.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

Bildanalysator_Proxy::Bildanalysator_Proxy()
{


}



void Bildanalysator_Proxy::messageReceived(string msg)
{

    // Nachricht analysieren
    std::sscanf(msg.c_str(),"%i %i %i %f %i",&x,&y,&z,&phi,&breite);
     std::cout << "--Bildanalysator_Proxy::messageReceived: " << msg << std::endl;
    benachrichtige();

}

void Bildanalysator_Proxy::byteStreamToHexString(char* hex, const unsigned char* byte, int len)
{
    int i;
    for (i=0; i<len; i++)
    {
        sprintf(hex+i*2, "%02X", byte[i]);
    }
    hex[i*2] = 0;
}

int Bildanalysator_Proxy::bildanalyseStarten(Bildanalysator_Proxy::ObjektTyp suessigkeit)
{
    Bildanalysator_Proxy::sendmessage(std::to_string(suessigkeit));
}

void Bildanalysator_Proxy::getObjektPosition(int* px, int* py, int* pz)
{
    (*px)=x;
    (*py)=y;
    (*pz)=z;
}

float Bildanalysator_Proxy::getObjektOrientierung()
{
    return phi;
}

int Bildanalysator_Proxy::getObjektBreite()
{
    return breite;
}

int Bildanalysator_Proxy::hexStringToByteStream(unsigned char* byte, const char* hex, int len)
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



