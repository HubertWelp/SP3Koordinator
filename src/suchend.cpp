#include "stdio.h"
#include "suchend.h"
#include "ausfuehrend.h"
#include "fehler.h"
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
    dynamic_cast<Ausfuehrend*>(dialog->getDialogzustand())->warte();
}

void Suchend::objektNichtErkannt()
{
    dialog->setZustand(new Verabschiedend(dialog,0));
    delete this;
}


