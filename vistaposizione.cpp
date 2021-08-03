#include "vistaposizione.h"
#include "controller.h"
VistaPosizione::VistaPosizione(Controller* c, QWidget* parent):QWidget(parent), controller(c)
{
//    masterLayout=new QBoxLayout(QBoxLayout::TopToBottom);
    masterLayout=new QVBoxLayout();
    mainLayout=new QHBoxLayout(parent);
    grigliaComputer=new QGridLayout(parent);
    grigliaGiocatore=new QGridLayout(parent);
    PannelloInformazioniP=new QVBoxLayout(parent);

    addMenu();

    addButton();



    addLabelP();



    mainLayout->addLayout(grigliaComputer);
    mainLayout->addLayout(grigliaGiocatore);
    mainLayout->addLayout(PannelloInformazioniP);

//    setLayout(mainLayout);
//     addButtonHelp();
     masterLayout->addLayout(mainLayout);
     addButtonHelp();
     setSchermata();
     setLayout(masterLayout);
}

VistaPosizione::VistaPosizione(VistaPosizione * p):controller(p->controller)
{
    mainLayout=p->mainLayout;
    grigliaComputer=p->grigliaComputer;
    grigliaGiocatore=p->grigliaGiocatore;
}

void VistaPosizione::update()
{
    for (unsigned short int i=0;i<100;i++){
        int player=controller->getPlayerP(i/10,i%10);
        if(player==1){
            QLayoutItem* item=grigliaGiocatore->itemAtPosition(i/10,i%10);
            QPushButton* button=static_cast<QPushButton*>(item->widget());
                button->setIcon(QIcon(":/risorse/quadratoRosso.png"));
                button->setEnabled(false);
        }
    }
}

void VistaPosizione::updatePanelloP()
{
   QLayoutItem* itemC=PannelloInformazioniP->itemAt(0);
   std::stringstream naviComputer;
   QLabel* naveC=static_cast<QLabel*>(itemC->widget());
   int numeroNaviPosizionateComputer=controller->showNaviPosizionateC();
   naviComputer<<"numero navi Computer posizionate: "<<numeroNaviPosizionateComputer;
   naveC->setText(QString::fromStdString(naviComputer.str()));

   QLayoutItem* itemG=PannelloInformazioniP->itemAt(1);
   std::stringstream naviGiocatore;
   QLabel* naveG=static_cast<QLabel*>(itemG->widget());
   int numeroNaviPosizionateGiocatore=controller->showNaviPosizionateG();
   naviGiocatore<<"numero navi Giocatore posizionate: "<<numeroNaviPosizionateGiocatore;
   naveG->setText(QString::fromStdString(naviGiocatore.str()));
}

void VistaPosizione::resetPosizione()
{
    for(unsigned short int i=0;i<100;i++){
        QPushButton* button=static_cast<QPushButton*>(grigliaComputer->itemAtPosition(i/10,i%10)->widget());
        button->setIcon(QIcon());
        button->setEnabled(false);
    }
    for(unsigned short int i=0;i<100;i++){
        QPushButton* buttonG=static_cast<QPushButton*>(grigliaGiocatore->itemAtPosition(i/10,i%10)->widget());
        buttonG->setIcon(QIcon());
        buttonG->setEnabled(true);
    }
}

void VistaPosizione::ShowMessage(const QString & message)
{
    QDialog* dialog=new QDialog(this);
    QHBoxLayout* layout=new QHBoxLayout(dialog);

    layout->addWidget(new QLabel(message,dialog));
    dialog->show();
}

void VistaPosizione::addMenu()
{
    QMenuBar*menuBar=new QMenuBar(this);
    QMenu* menu=new QMenu("File",menuBar);
    QAction* reset=new QAction("Reset", menu);
    QAction* quit=new QAction("quit",menuBar);
   connect(reset,SIGNAL(triggered()),controller,SLOT(resetGameP()));
   connect(quit,SIGNAL(triggered()),this,SLOT(close()));

    menu->addAction(reset);
    menu->addAction(quit);
    menuBar->addMenu(menu);

    masterLayout->addWidget(menuBar);
}

void VistaPosizione::addButton()
{
    for(unsigned short int i=0;i<100;i++){
        ButtonB* button1=new ButtonB(i/10,i%10,this);
        button1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        button1->setMinimumSize(45,45);
        button1->setMaximumSize(60,60);
        grigliaComputer->addWidget(button1, i/10, i%10);
        button1->setEnabled(false);
        ButtonB* button2=new ButtonB(i/10,i%10,this);
        button2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        button2->setMinimumSize(45,45);
        button2->setMaximumSize(60,60);
        connect(button2,SIGNAL(clickedCell(unsigned short, unsigned short)), controller, SLOT(posiziona(unsigned short, unsigned short)));
        grigliaGiocatore->addWidget(button2, i/10, i%10);
        button2->setEnabled(true);
    }

}

void VistaPosizione::addButtonHelp()
{
    // HELP BUTTON
    QBoxLayout* posizionamento=new QBoxLayout(QBoxLayout::LeftToRight);
    posizionamento->addSpacing(750);
   QPushButton* helpButton = new QPushButton("Help",this);
    helpButton->setFocusPolicy(Qt::NoFocus);
    helpButton->setStyleSheet(
                            "font-size: 15px;"
                            "border-radius: 5px;"
                            "padding: 0.4em;"
                            "max-width: 35px;"
                            "max-height: 15px;"
                            );


    QObject::connect(helpButton,SIGNAL(clicked(bool)),controller,SLOT(sendHelp()));
    posizionamento->addWidget(helpButton);
    masterLayout->addLayout(posizionamento);
}

void VistaPosizione::addLabelP()
{
    std::stringstream naviG;
    std::stringstream naviC;

     naviC<<"numero navi Computer Pozizionate: "<<controller->showNaviPosizionateC();
     naviG<<"numero navi giocatore Posizionate: "<<controller->showNaviPosizionateG();
     QLabel* naviComputerPosizionate=new QLabel(QString::fromStdString(naviC.str()));
     QLabel* naviGiocatorePosizionate=new QLabel(QString::fromStdString(naviG.str()));
     QLabel* assalto=new QLabel(QString("assalto: 2 caselle"));
     QLabel* crociere=new QLabel(QString("crociere: 3 caselle"));
     QLabel* corazzata=new QLabel(QString("corazzata: 4 caselle"));
     QLabel* portaerei=new QLabel(QString("portaerei: 5 caselle"));
     QLabel* regola=new QLabel(QString("N.B. le navi NON possono essere messe in obliquo!"));
     PannelloInformazioniP->addWidget(naviComputerPosizionate);
     PannelloInformazioniP->addWidget(naviGiocatorePosizionate);
     PannelloInformazioniP->addWidget(assalto);
     PannelloInformazioniP->addWidget(crociere);
     PannelloInformazioniP->addWidget(corazzata);
     PannelloInformazioniP->addWidget(portaerei);
     PannelloInformazioniP->addWidget(regola);
}

void VistaPosizione::setSchermata()
{

    grigliaComputer->setSpacing(0);
    grigliaGiocatore->setSpacing(0);
//    setMinimumSize(QSize(1300,500));
    setMaximumSize(1400,600);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QFile file(":risorse/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}

