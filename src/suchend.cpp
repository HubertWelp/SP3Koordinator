#include "stdio.h"
#include "suchend.h"
#include "ausfuehrend.h"
#include "roboter.h"
#include "verabschiedend.h"

Suchend::Suchend(Bildanalysator_Proxy::ObjektTyp o,Koordinator* dlg)
    : Dialogzustand(dlg)
{
    //ctor
    printf("S U C H E N D\n");
    m_suessigkeit = o;
    dlg->getBildAnalysator()->bildanalyseStarten(m_suessigkeit);
}

Suchend::~Suchend()
{
    //dtor

}

void Suchend::objektErkannt()
{
    dialog->setZustand(new Ausfuehrend(dialog));
    delete this;
    //dialog->getDialogzustand()->warte(30);
//    dialog->getDialogzustand()->warte(10);
}

void Suchend::objektNichtErkannt()
{
    dialog->setZustand(new Verabschiedend(dialog,0));
    delete this;

}

int Suchend::getSuessigkeit()
{
    return m_suessigkeit;
}


