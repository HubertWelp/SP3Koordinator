#include "rfidtag.h"
#include <string.h>
RFIDTag::RFIDTag()
{
    unsigned char* ptr=(unsigned char*)this;
    int size=sizeof(*this);
    for(int i=0;i<size;i++)
        ptr[i]=0;
}

unsigned long long RFIDTag::getRFIDNr()
{
    unsigned long long* nr = (unsigned long long*)this->id;
    return *nr;
}
void RFIDTag::setRFIDNr(const unsigned long long nr)
{
    memcpy(id,(unsigned char*)&nr,sizeof(nr));
}

const unsigned char* RFIDTag::getUserdata()
{
    return (unsigned char*)userdata;
}

int RFIDTag::userdataLength()
{
    return sizeof(userdata);
}

void RFIDTag::setUserdata(const unsigned char* buffer, int l)
{
    int n=l;
    if(n>sizeof(userdata))
        n = sizeof(userdata);
    memcpy(userdata,buffer,n);
}

