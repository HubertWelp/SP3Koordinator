#include "tuimanager.h"
#include <stdlib.h>
#include <iostream>
#include <list>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

TUIManager::TUIManager(PDialog* dlg)
    : dialog(dlg)
{
    //ctor
    dialog->anmelden(this);
//    aktualisiere(NULL);


}

TUIManager::~TUIManager()
{
    //dtor
}

void TUIManager::aktualisiere(Subjekt* s)
{
    Dialogzustand* dz = dialog->getDialogzustand();
    if(dynamic_cast<Wartend*>(dz))
        handleWartend(dynamic_cast<Wartend*>(dz));
    else if(dynamic_cast<Begruessend*>(dz))
        handleBegruessend(dynamic_cast<Begruessend*>(dz));
    else if(dynamic_cast<Fahrend*>(dz))
        handleFahrend(dynamic_cast<Fahrend*>(dz));
    else if(dynamic_cast<Fehler*>(dz))
        handleFehler(dynamic_cast<Fehler*>(dz));
    else if(dynamic_cast<Verabschiedend*>(dz))
        handleVerabschiedend(dynamic_cast<Verabschiedend*>(dz));
    else
        cout << "kein gueltiger Dialogzustand\n";
}

void TUIManager::handleBegruessend(Begruessend* dz)
{
    list<string> rl;
    list<string>::iterator its;
    int i,auswahl;

    rl = dz->getRaeume();
    if(rl.empty())
    {
        dialog->auswahlAbbrechen();
    }else
    {
        system("clear");
        cout << "Begrussungsbildschirm\n\n";
        cout << "Guten Tag Herr/Frau " << dz->getVornamePatient() << " " << dz->getNachnamePatient() << endl;
        cout << endl << "Zu welchem der folgenden Raeume darf ich Sie geleiten?"  << endl;
        i=1;
        for(its=rl.begin();its!=rl.end();its++)
        {
            cout << " (" << i << ") " << *its << endl;
            i++;
        }
        cout << " (" << 0 << ") " << "abbrechen" << endl;
        cout << endl << "Auswahl: ";


        int stopZeit = 10;   // in sec
        int t=0,c;

        while(!kbhit() && t<stopZeit )
        {
            usleep(1000000);
            t++;
        }
        if(kbhit())
        {
            c = getchar();
            //        printf("pressed: %c\n",c);
            c = c-'0';
            if(c>=0 && c<=rl.size())
            {
                //            printf("yes: c=%i 0=%i size=%i\n",c,'0',rl.size());
                auswahl = c;
            }else
            {
                //            printf("no: c=%i 0=%i size=%i\n",c,'0',rl.size());
                auswahl = 0;
            }
        }else
        {
            //        printf("no key pressed\n");
            auswahl = 0;;
        }
        cout << "auswahl : " << auswahl << endl;
        usleep(10000);
        if(auswahl == 0)
        {

            dz->auswahlAbbrechen();
        }else
        {
            cout << "geht weiter " << endl;
            dz->raumWaehlen(auswahl-1);
        }

    }


}
void TUIManager::handleVerabschiedend(Verabschiedend* dz)
{
    system("clear");
    cout << "Verabschiedungsbildschirm\n\n";
    cout << "Wir sind am Ziel!\n";
    cout << "Einen schoenen Tag noch.\n";
}

int TUIManager::kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
      ungetc(ch, stdin);
      return 1;
    }

    return 0;
}
void TUIManager::handleFahrend(Fahrend* dz)
{
    system("clear");
    cout << "Fahrenbildschirm\n\n";
    cout << "                         ^\n";
    cout << "                        / \\\n";
    cout << "                       /   \\\n";
    cout << "                      /     \\\n";
    cout << "                     /       \\\n";
    cout << "                    /         \\\n";
    cout << "                   /           \\\n";
    cout << "                  /             \\\n";
    cout << "                 /               \\\n";
    cout << "                /                 \\\n";
    cout << "               /                   \\\n";
    cout << "              /                     \\\n";
    cout << "             /                       \\\n";
//    cout << "             |                       |\n";
    cout << "             | Bitte folgen Sie mir! |\n";
}

void TUIManager::handleFehler(Fehler *dz)
{
    system("clear");
    cout << "Fehlerbildschirm\n\n";
    cout << "Es tut uns Leid. Es ist ein Fehler aufgetreten! \n";
    cout << "Das Ziel konnte nicht erreicht werden!\n";
    cout << "Bitte wenden Sie sich an das Personal.\n";

}
void TUIManager::handleWartend(Wartend* dz)
{
    system("clear");
    cout << "Wartenbildschirm\n\n";
    cout << "\n\n\n\n\n";
    cout << "          <-----------------------------------------------------------\n";
    cout << "       <--------------------------------------------------------------\n";
    cout << "    <--------------                                   ----------------\n";
    cout << " <-----------------  P a t i e n t e n a r m b a n d  ----------------\n";
    cout << "    <--------------                                   ----------------\n";
    cout << "       <--------------------------------------------------------------\n";
    cout << "          <-----------------------------------------------------------\n";
}
