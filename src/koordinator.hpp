#ifndef KOORDINATOR_H
#define KOORDINATOR_H
#ifndef Q_MOC_RUN
#include "Subjekt.h"
#include "Bildanalysator_Proxy.h"
#include "roboter.h"
#include "Beobachter.h"
#include "timer.h"
#endif
#include <QtCore/QObject>
class Dialogzustand;

////Diese Klasse managed den ablauf des Programms

class Koordinator : public QObject, public Subjekt, public Beobachter
{
Q_OBJECT
public:
    Koordinator(int argc=1, char **argv=(char *[]){"sp3"});
    virtual ~Koordinator();


    void setZustand(Dialogzustand* z);

    void objektAuswaehlen(Bildanalysator_Proxy::ObjektTyp s);
    void objektErkannt();
    void objektNichtErkannt();
    void objektUebergeben();
    void onTimer();

    Dialogzustand* getDialogzustand();
    Roboter* getRoboter();
    Bildanalysator_Proxy* getBildAnalysator();
    Timer* getTimer();


    void aktualisiere(Subjekt* s);
Q_SIGNALS:
    void changed();
protected:
    Dialogzustand* zustand;

private:
    Bildanalysator_Proxy* m_bildanalysatorProxy;
    Roboter* m_roboter;
    Timer* m_timer;
    void handleBildanalysatorNachrichten();
    void handleRoboterNachrichten();
    void handleTimerNachrichten();

};

#endif // KOORDINATOR_H
