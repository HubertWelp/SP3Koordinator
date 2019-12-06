#ifndef PDIALOG_H
#define PDIALOG_H
#ifndef Q_MOC_RUN
#include "Subjekt.h"
#include "scrs.h"
#include "roboter.h"
#include "Beobachter.h"
#include "timer.h"
#endif
#include <QtCore/QObject>
class Dialogzustand;

class PDialog : public QObject, public Subjekt, public Beobachter
{
Q_OBJECT
public:
    PDialog(int argc=1, char **argv=(char *[]){"pds"});
    virtual ~PDialog();
    void rfidEmpfangen(unsigned long ru);
    void auswahlAbbrechen();
    void raumWaehlen(unsigned short rNr);
    void angekommen();
    void onTimer();
    void fahrenAbgebrochen(string grund="");
    void setZustand(Dialogzustand* z);
    Dialogzustand* getDialogzustand();
    Roboter* getRoboter();
    Timer* getTimer();


    void aktualisiere(Subjekt* s);
Q_SIGNALS:
    void changed();
protected:
    Dialogzustand* zustand;

private:
    SCRS* m_scrs;
    Roboter* m_roboter;
    Timer* m_timer;
    void handleSCRSNachrichten();
    void handleRoboterNachrichten();
    void handleTimerNachrichten();

};

#endif // PDIALOG_H
