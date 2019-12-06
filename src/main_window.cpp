/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../src/main_window.hpp"



/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace pds {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(PDialog* dlg, QWidget *parent)
    : QDialog(parent)
    , dialog(dlg)
{
//	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    setMinimumWidth(800);
    setMinimumHeight(600);
    move(10,10);
//    setStyleSheet("background-color:white;");

    int minButtonHeight = 60;
    QPixmap pxm;
    QPalette sample_palette;
    QFont font;
    QColor thgaBlue(0,61,125);
    QColor thgaRed(228,0,30);

//    wartendSymbol = new QPixmap("/home/Student/wartendSymbol.png");
//    fahrendSymbol = new QPixmap("/home/Student/fahrendSymbol.png");
//    fehlerSymbol = new QPixmap("/home/Student/fehlerSymbol.png");
//    verabschiedendSymbol = new QPixmap("/home/Student/verabschiedendSymbol.png");
    wartendSymbol = new QPixmap("/home/Student/catkin_ws/src/pds/resources/images/wartendSymbol.png");
    fahrendSymbol = new QPixmap("/home/Student/catkin_ws/src/pds/resources/images/fahrendSymbol.png");
    fehlerSymbol = new QPixmap("/home/Student/catkin_ws/src/pds/resources/images/fehlerSymbol.png");
    verabschiedendSymbol = new QPixmap("/home/Student/catkin_ws/src/pds/resources/images/verabschiedendSymbol.png");

    logoLabel = new QLabel(this);
    logoLabel->move(125,50);
    logoLabel->setFixedSize(250,100);
    logoLabel->setAlignment(Qt::AlignCenter);
    logoLabel->setScaledContents(true);
    std::cout << "logoLabel: " << logoLabel->width() << " " << logoLabel->height() << std::endl;
//    if(!pxm.load("/home/Student/thga.jpg"))
    if(!pxm.load("/home/Student/catkin_ws/src/pds/resources/images/thga.jpg"))
        std::cout << "Bild konnte nicht geladen werden\n";
    else
    {
        logoLabel->setPixmap(pxm);
    }

    nameLabel = new QLabel(this);
    font = nameLabel->font();
    font.setPointSize(32);
    font.setBold(false);
    nameLabel->setFont(font);
    sample_palette.setColor(QPalette::Window, Qt::white);
    sample_palette.setColor(QPalette::WindowText, thgaBlue);
    nameLabel->setAutoFillBackground(true);
    nameLabel->setFixedHeight(100);
    nameLabel->setPalette(sample_palette);
    nameLabel->setAlignment(Qt::AlignCenter);
    nameLabel->setText("Guten Tag\nHerr Mustermann");

    hinweisLabel = new QLabel(this);
    font = hinweisLabel->font();
    font.setPointSize(18);
    font.setBold(false);
    hinweisLabel->setFont(font);
    sample_palette.setColor(QPalette::Window, Qt::white);
    sample_palette.setColor(QPalette::WindowText, thgaRed);
    hinweisLabel->setAutoFillBackground(false);
    hinweisLabel->setPalette(sample_palette);
    hinweisLabel->setAlignment(Qt::AlignCenter);
    hinweisLabel->setText("Wohin darf ich Sie begleiten?");

    for(int i=0;i<8;i++)
    {
        zielButton[i] = new QPushButton(this);
        zielButton[i]->setMinimumHeight(minButtonHeight);
        font = zielButton[i]->font();
        font.setPointSize(18);
        font.setBold(false);
        zielButton[i]->setFont(font);
    }


    abbrechenButton = new QPushButton(this);
    abbrechenButton->setMinimumHeight(minButtonHeight);
    font = abbrechenButton->font();
    font.setPointSize(18);
    font.setBold(false);
    abbrechenButton->setFont(font);
    abbrechenButton->setText("abbrechen");


    QHBoxLayout* greetingLayout = new QHBoxLayout;
    greetingLayout->setSpacing(0);
    greetingLayout->addWidget(nameLabel);
    greetingLayout->addWidget(logoLabel);

    QGridLayout* buttonLayout = new QGridLayout;
    buttonLayout->addWidget(zielButton[0],0,0);
    buttonLayout->addWidget(zielButton[4],0,1);
    buttonLayout->addWidget(zielButton[1],1,0);
    buttonLayout->addWidget(zielButton[5],1,1);
    buttonLayout->addWidget(zielButton[2],2,0);
    buttonLayout->addWidget(zielButton[6],2,1);
    buttonLayout->addWidget(zielButton[3],3,0);
    buttonLayout->addWidget(zielButton[7],3,1);
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(greetingLayout);
//    mainLayout->setMargin(30);
//    std::cout << "margin: " << mainLayout->margin() << std::endl;

    //    mainLayout->addStretch();
    mainLayout->addWidget(hinweisLabel);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(abbrechenButton);
    setLayout(mainLayout);

    zustandLabel = new QLabel(this);
    zustandLabel->move(10,height()-400);
    zustandLabel->setFixedSize(width()-20,390);
    zustandLabel->setAlignment(Qt::AlignCenter);
    zustandLabel->setScaledContents(true);
    if(!wartendSymbol)
        std::cout << "Bild konnte nicht geladen werden\n";
    else
    {
        zustandLabel->setPixmap(*wartendSymbol);
    }

    connect(dialog,SIGNAL(changed()),this,SLOT(aktualisiere()));
    connect(abbrechenButton, SIGNAL(clicked()),this,SLOT(abbrechen()));
    connect(zielButton[0],SIGNAL(clicked()),this,SLOT(onZiel1Button()));
    connect(zielButton[1],SIGNAL(clicked()),this,SLOT(onZiel2Button()));
    connect(zielButton[2],SIGNAL(clicked()),this,SLOT(onZiel3Button()));
    connect(zielButton[3],SIGNAL(clicked()),this,SLOT(onZiel4Button()));
    connect(zielButton[4],SIGNAL(clicked()),this,SLOT(onZiel5Button()));
    connect(zielButton[5],SIGNAL(clicked()),this,SLOT(onZiel6Button()));
    connect(zielButton[6],SIGNAL(clicked()),this,SLOT(onZiel7Button()));
    connect(zielButton[7],SIGNAL(clicked()),this,SLOT(onZiel8Button()));
}

MainWindow::~MainWindow() {
    for(int i=0;i<8;i++)
    {
        delete zielButton[i];
    }
    delete nameLabel;
    delete abbrechenButton;
    delete zustandLabel;
    delete hinweisLabel;
    delete logoLabel;
    delete wartendSymbol;
    delete fahrendSymbol;
    delete fehlerSymbol;
    delete verabschiedendSymbol;

}

void MainWindow::aktualisiere()
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


void MainWindow::onZiel1Button()
{
    dialog->raumWaehlen(0);
}

void MainWindow::onZiel2Button()
{
    dialog->raumWaehlen(1);
}

void MainWindow::onZiel3Button()
{
    dialog->raumWaehlen(2);
}

void MainWindow::onZiel4Button()
{
    dialog->raumWaehlen(3);
}

void MainWindow::onZiel5Button()
{
    dialog->raumWaehlen(4);
}

void MainWindow::onZiel6Button()
{
    dialog->raumWaehlen(5);
}

void MainWindow::onZiel7Button()
{
    dialog->raumWaehlen(6);
}

void MainWindow::abbrechen()
{
    dialog->auswahlAbbrechen();
}

void MainWindow::onZiel8Button()
{
    dialog->raumWaehlen(7);
}

void MainWindow::handleWartend(Wartend *dz)
{
    begruessungsText = "Guten Tag";
    nameLabel->setText(begruessungsText);
    hinweisLabel->setText("\nBitten halten Sie das Patientenarmband in den Lesebereich.");
    for(int i=0;i<8;i++)
    {
        zielButton[i]->hide();
    }

    abbrechenButton->hide();
    zustandLabel->show();
    if(!wartendSymbol)
         std::cout << "Bild konnte nicht geladen werden\n";
     else
     {
         zustandLabel->setPixmap(*wartendSymbol);
     }

}

void MainWindow::handleBegruessend(Begruessend *dz)
{

    list<string> rl;
    list<string>::iterator its;
    QString strOutput;
    int i,auswahl;



    rl = dz->getRaeume();
    if(rl.empty())
    {
        dialog->auswahlAbbrechen();
    }else
    {
        i=0;
        for(its=rl.begin();its!=rl.end();its++)
        {
            zielButton[i]->setText((*its).c_str());
            zielButton[i]->setEnabled(true);
            i++;
        }
        for(i;i<8;i++)
        {
            zielButton[i]->setText("");
            zielButton[i]->setEnabled(false);
        }

        begruessungsText ="Guten Tag\n";
        begruessungsText = begruessungsText + QString(dz->getVornamePatient().c_str()) + " " + QString(dz->getNachnamePatient().c_str());
        nameLabel->setText(begruessungsText);

        hinweisLabel->setText("\nWohin darf ich Sie begleiten?");
        for(int i=0;i<8;i++)
        {
            zielButton[i]->show();
        }

        abbrechenButton->show();
        zustandLabel->hide();

    }


}

void MainWindow::handleFahrend(Fahrend *dz)
{
    nameLabel->setText(begruessungsText);
    hinweisLabel->setText("\nFolgen Sie dem Roboter.");
    for(int i=0;i<8;i++)
    {
        zielButton[i]->hide();
    }

    abbrechenButton->hide();
    zustandLabel->show();
    if(!wartendSymbol)
         std::cout << "Bild konnte nicht geladen werden\n";
     else
     {
         zustandLabel->setPixmap(*fahrendSymbol);
     }

}

void MainWindow::handleFehler(Fehler *dz)
{
    nameLabel->setText(begruessungsText);
    hinweisLabel->setText("\nEs ist ein Fehler aufgetreten. Wenden Sie sich ans Personal.");
    for(int i=0;i<8;i++)
    {
        zielButton[i]->hide();
    }

    abbrechenButton->hide();
    zustandLabel->show();
    if(!wartendSymbol)
         std::cout << "Bild konnte nicht geladen werden\n";
     else
     {
         zustandLabel->setPixmap(*fehlerSymbol);
     }

}

void MainWindow::handleVerabschiedend(Verabschiedend *dz)
{
    nameLabel->setText(begruessungsText);
    hinweisLabel->setText("\nWir sind am Ziel. Auf Wiedersehen.");
    for(int i=0;i<8;i++)
    {
        zielButton[i]->hide();
    }

    abbrechenButton->hide();
    zustandLabel->show();
    if(!wartendSymbol)
         std::cout << "Bild konnte nicht geladen werden\n";
     else
     {
         zustandLabel->setPixmap(*verabschiedendSymbol);
     }

}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

}  // namespace pds

