/**
 * @file /include/pds/main_window.hpp
 *
 * @brief Qt based gui for pds.
 *
 * @date November 2010
 **/
#ifndef pds_MAIN_WINDOW_H
#define pds_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/
#ifndef Q_MOC_RUN
#include "koordinator.hpp"
#include "dialogzustand.h"

#include "ausfuehrend.h"
#include "verabschiedend.h"
#include "suchend.h"
#include "wartend.h"

#endif
#include <QtGui/QDialog>
//#include "ui_main_window.h"
#include <QtGui/QPushButton>
#include <QtGui/QLabel>

#include <QTimer>




/*****************************************************************************
** Namespace
*****************************************************************************/

namespace pds {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QDialog{
Q_OBJECT

public:
    MainWindow(Koordinator* dlg, QWidget *parent = 0);
	~MainWindow();



public Q_SLOTS:
    //void abbrechen();
    void aktualisiere();
    void onZiel1Button();
    void onZiel2Button();
    void onZiel3Button();
    void onZiel4Button();
    void onTimer();

private:
//	Ui::MainWindowDesign ui;
    //QPushButton* abbrechenButton;
    QPushButton* zielButton[8];/** pushbuttons durch Label ersetzen*/
    QPushButton* sorten[4];
//    QPushButton* ziel1Button;
//    QPushButton* ziel2Button;
//    QPushButton* ziel3Button;
//    QPushButton* ziel4Button;
//    QPushButton* ziel5Button;
//    QPushButton* ziel6Button;
//    QPushButton* ziel7Button;
//    QPushButton* ziel8Button;
    QLabel* logoLabel;
    QLabel* nameLabel;
    QLabel* hinweisLabel;
    QLabel* zustandLabel;
    Koordinator* dialog;
    QString begruessungsText;

    QIcon buttonIcon[4];
    QPixmap buttonImages[8];

    QTimer* timer;


    void handleWartend(Wartend* dz);
    void handleSuchend(Suchend* dz);
    void handleVerabschiedend(Verabschiedend* dz);
    void handleAusfuehrend(Ausfuehrend* dz);

    int aktuelleSuessigkeit;
};

}  // namespace pds

#endif // pds_MAIN_WINDOW_H
