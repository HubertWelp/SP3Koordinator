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
#include "../src/tuimanager.h"
#include "wartend.h"
#include <mysql/mysql.h>
#include <stdio.h>
#include "Bildanalysator_Proxy.h"


using namespace std;

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}
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
    //pds::MainWindow w(&pD);
    pD.setZustand(new Wartend(&pD));
    //w.show();
    pD.objektAuswaehlen(Bildanalysator_Proxy::ObjektTyp::Maoam);

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
