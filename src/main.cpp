/**
 * @file /src/main.cpp
 *
 * @brief Qt based gui.
 *
 * @date November 2010
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QApplication>
#include "../src/main_window.hpp"
#include <iostream>
#include <string.h>
#include "../src/rosnode.h"
#ifndef Q_MOC_RUN
#include "koordinator.hpp"
#endif
#include "wartend.h"

#include "verabschiedend.h"

#include <stdio.h>
#include "Bildanalysator_Proxy.h"


using namespace std;

/*****************************************************************************
** Main
*****************************************************************************/

int main(int argc, char **argv) {

    /*********************
    ** Qt
    **********************/
    QApplication app(argc, argv);
    int a=1;


    Koordinator pD;
    pds::MainWindow w(&pD);
    pD.setZustand(new Wartend(&pD));
    w.show();
    printf("%s\n",setlocale(LC_NUMERIC,"de_DE.UTF-8"));
    //printf("%s\n",setlocale(LC_NUMERIC,"en_GB.UTF-8"));
    //pD.objektAuswaehlen(Bildanalysator_Proxy::)
    //std::cout <<"\nwert test: "<<Bildanalysator_Proxy::ObjektTyp::Maoam<<"\n";
    //pD.objektAuswaehlen(Bildanalysator_Proxy::ObjektTyp::Maoam);
    //pD.objektErkannt();
    //pD.objektUebergeben();*/
//    std::cin >> a;
//    pD.onTimer();
    //app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();

    return result;

//    Koordinator pD;
//    TUIManager tm(&pD);
//    pD.setZustand(new Wartend(&pD));
//    std::cout << "Schleife";
//    while(1)
//        sleep(1);
////    getchar();


//    return 0;
}
