#include "wartend.h"
#include <stdio.h>
#include "begruessend.h"

Wartend::Wartend(PDialog* dlg)
    : Dialogzustand(dlg)
{
    //ctor
    printf("W A R T E N D\n");

}

Wartend::~Wartend()
{
    //dtor
}
void Wartend::rfidEmpfangen(unsigned long ru)
{
    dialog->setZustand(new Begruessend(ru,dialog));

    delete this;
}
