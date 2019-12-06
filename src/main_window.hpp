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
#include "pdialog.hpp"
#include "dialogzustand.h"
#include "fehler.h"
#include "fahrend.h"
#include "wartend.h"
#include "begruessend.h"
#include "verabschiedend.h"
#endif
#include <QtGui/QDialog>
//#include "ui_main_window.h"
#include <QtGui/QPushButton>
#include <QtGui/QLabel>




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
    MainWindow(PDialog* dlg, QWidget *parent = 0);
	~MainWindow();



public Q_SLOTS:
    void abbrechen();
    void aktualisiere();
    void onZiel1Button();
    void onZiel2Button();
    void onZiel3Button();
    void onZiel4Button();
    void onZiel5Button();
    void onZiel6Button();
    void onZiel7Button();
    void onZiel8Button();
private:
//	Ui::MainWindowDesign ui;
    QPushButton* abbrechenButton;
    QPushButton* zielButton[8];
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
    PDialog* dialog;
    QPixmap* wartendSymbol;
    QPixmap* fehlerSymbol;
    QPixmap* verabschiedendSymbol;
    QPixmap* fahrendSymbol;
    QString begruessungsText;

    void handleWartend(Wartend* dz);
    void handleBegruessend(Begruessend* dz);
    void handleFahrend(Fahrend* dz);
    void handleFehler(Fehler* dz);
    void handleVerabschiedend(Verabschiedend* dz);
};

}  // namespace pds

#endif // pds_MAIN_WINDOW_H
