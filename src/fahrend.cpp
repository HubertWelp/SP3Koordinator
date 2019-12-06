#include "stdio.h"
#include "fahrend.h"
#include "verabschiedend.h"
#include "fehler.h"
#include "roboter.h"

Fahrend::Fahrend(PDialog* dlg)
    : Dialogzustand(dlg)
{
    //ctor
    printf("F A H R E N D\n");

}

Fahrend::~Fahrend()
{
    //dtor
}

void Fahrend::angekommen()
{
    dialog->setZustand(new Verabschiedend(dialog));
    delete this;
//    sleep(5);
//    dialog->onTimer();
}

void Fahrend::fahrenAbgebrochen(string grund)
{
    dialog->setZustand(new Fehler(dialog));
    delete this;
//    sleep(10);
//    dialog->onTimer();
}
