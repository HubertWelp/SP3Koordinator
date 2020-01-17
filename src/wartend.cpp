#include "wartend.h"
#include <stdio.h>
#include "suchend.h"

Wartend::Wartend(Koordinator* dlg)
    : Dialogzustand(dlg)
{
    //ctor
    printf("W A R T E N D\n");

}

Wartend::~Wartend()
{
    //dtor
}
/*void Wartend::rfidEmpfangen(unsigned long ru)
{
    dialog->setZustand(new Begruessend(ru,dialog));

    delete this;
}*/

void Wartend::objektAuswaehlen(Bildanalysator_Proxy::ObjektTyp s)
{
    //...
    dialog->setZustand(new Suchend(s,dialog));//s fehlt
    delete this;

}
