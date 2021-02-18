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
    bildInfoAuswerten(msg);
//     std::cout << "--Bildanalysator_Proxy::messageReceived: " << msg << std::endl;
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

void Bildanalysator_Proxy::bildInfoAuswerten(string ms)
{
    if(ms=="Fehler")
    {
        error=true;
    }
    else
    {
        std::sscanf(ms.c_str(),"%f %f %f %f %f",&x,&y,&z,&phi,&breite);
//        printf("Bildanalysator_Proxy::Koordinaten: %f %f %f %f %f\n",x,y,z,phi,breite);
        error=false;
    }

}

int Bildanalysator_Proxy::bildanalyseStarten(Bildanalysator_Proxy::ObjektTyp suessigkeit)
{
//    Bildanalysator_Proxy::sendmessage(std::to_string(suessigkeit+1),"192.168.1.203",5842);
    Bildanalysator_Proxy::sendmessage(std::to_string(suessigkeit+1),"192.168.188.30",5842);
}

void Bildanalysator_Proxy::getObjektPosition(float* px, float* py, float* pz)
{
    (*px)=x;
    (*py)=y;
    (*pz)=z;
}

float Bildanalysator_Proxy::getObjektOrientierung()
{
    return phi;
}

float Bildanalysator_Proxy::getObjektBreite()
{
    return breite;
}

bool Bildanalysator_Proxy::getNichtErkannt()
{
    return error;
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



