#include <stdio.h>
#include "dialogzustand.h"

Dialogzustand::Dialogzustand(PDialog* dlg)
    : dialog(dlg)
{
    //ctor
}

Dialogzustand::~Dialogzustand()
{
    //dtor
//    printf("Zustand zerstoert\n");
}
