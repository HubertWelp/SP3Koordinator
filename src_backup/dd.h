#ifndef DD_H
#define DD_H

#include "../src/Beobachter.h"
#include "../src/scrs.h"
#include "../src/roboter.h"
class DD : public Beobachter
{
public:
    DD(int argc=1, char **argv=(char *[]){"pds"});
    void aktualisiere(Subjekt* s);
    ~DD();
private:
    SCRS* m_scrs;
    Roboter* m_roboter;
    void handleSCRSNachrichten();
    void handleRoboterNachrichten();
};

#endif // DD_H
