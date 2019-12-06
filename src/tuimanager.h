#ifndef TUIMANAGER_H
#define TUIMANAGER_H

#include "Beobachter.h"
#include "dialogzustand.h"
#include "begruessend.h"
#include "wartend.h"
#include "fahrend.h"
#include "fehler.h"
#include "verabschiedend.h"

class TUIManager : public Beobachter
{
    public:
        TUIManager(PDialog* dlg);
        ~TUIManager();
        void aktualisiere(Subjekt* s);
    protected:

    private:
        void handleWartend(Wartend* dz);
        void handleBegruessend(Begruessend* dz);
        void handleFahrend(Fahrend* dz);
        void handleFehler(Fehler* dz);
        void handleVerabschiedend(Verabschiedend* dz);
        int kbhit();

        PDialog* dialog;
//        UI* ui;
};

#endif // TUIMANAGER_H
