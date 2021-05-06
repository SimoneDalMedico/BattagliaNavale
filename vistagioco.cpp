#include "vistagioco.h"
#include "controller.h"

vistaGioco::vistaGioco(Controller* c,QWidget* parent): QWidget(parent), controller(c)
{
    mainLayout=new QHBoxLayout(this);
    grigliaComputer=new QGridLayout(parent);
    grigliaGiocatore=new QGridLayout(parent);
    PannelloInformazioni=new QVBoxLayout(parent);

    addMenu();

    addButton();

    addLabel();

    setSchermata();

    mainLayout->addLayout(grigliaComputer);

    mainLayout->addLayout(grigliaGiocatore);

    mainLayout->addLayout(PannelloInformazioni);

    setLayout(mainLayout);
}

void vistaGioco::update()
{
    std::cout<<"vistaGioco->update->start"<<std::endl;
    for(unsigned short int i=0;i<100;i++){
        int player=controller->getPlayer(i/10, i%10);
        if(player!=none){
            QLayoutItem* item=grigliaComputer->itemAtPosition(i/10,i%10);
            QPushButton* button=static_cast<QPushButton*>(item->widget());

                if(player==playerMancata){
                    button->setIcon(QIcon(":/risorse/XMancata.jpg"));
                }else{
                    if(player==playerG){
                        button->setIcon(QIcon(":/risorse/Affondata.png"));
                    }
                }
                if(player!=playerC){
                    button->setEnabled(false);
                }
        }
    }
    std::cout<<"vistaGioco->update->end"<<std::endl;

}

void vistaGioco::updateC()
{
    for(unsigned short int i=0;i<100;i++){
        int player=controller->getPlayer(i/10, i%10);
        if(player!=0){
            QLayoutItem* item=grigliaGiocatore->itemAtPosition(i/10,i%10);
            QPushButton* button=static_cast<QPushButton*>(item->widget());
                if(player==playerMancata){
                    button->setIcon(QIcon(":/risorse/XMancata.jpg"));
                }else{
                    if(player==playerC){
                        button->setIcon(QIcon(":/risorse/Affondata.png"));
                    }
                }
        }
    }
}

void vistaGioco::resetGame()
{
    for(unsigned short int i=0;i<100;i++){
        QPushButton* button=static_cast<QPushButton*>(grigliaComputer->itemAtPosition(i/10,i%10)->widget());
        button->setIcon(QIcon());
        button->setEnabled(true);
    }
    for(unsigned short int i=0;i<100;i++){
        QPushButton* buttonG=static_cast<QPushButton*>(grigliaGiocatore->itemAtPosition(i/10,i%10)->widget());
        buttonG->setIcon(QIcon());
        buttonG->setEnabled(false);
    }
}

void vistaGioco::showWinner()
{
    QDialog* dialog=new QDialog(this);
    QHBoxLayout* layout=new QHBoxLayout(dialog);
    int winner=controller->getWinner();
    std::stringstream text;
    if(winner==1){
        text<<"ha vinto il Giocatore";
    }else{
        text<<"ha vinto il Computer";
    }
    layout->addWidget(new QLabel(QString::fromStdString(text.str()),dialog));
    dialog->show();
}

void vistaGioco::updatePannelo()
{
    QLayoutItem* itemC=PannelloInformazioni->itemAt(0);
    std::stringstream naviComputer;
    QLabel* naveC=static_cast<QLabel*>(itemC->widget());

    int numeroNaviAffondateComputer=controller->showNaviAffondateC();
    naviComputer<<"numero navi Computer affondate: "<<numeroNaviAffondateComputer;
    naveC->setText(QString::fromStdString(naviComputer.str()));

    QLayoutItem* itemG=PannelloInformazioni->itemAt(1);
    std::stringstream naviGiocatore;
    QLabel* naveG=static_cast<QLabel*>(itemG->widget());
    int numeroNaviAffondateGiocatore=controller->showNaviAffondateG();
    naviGiocatore<<"numero navi Giocatore affondate: "<<numeroNaviAffondateGiocatore;
    naveG->setText(QString::fromStdString(naviGiocatore.str()));
}

void vistaGioco::ShowMessage(const QString & message)
{
    QDialog* dialog=new QDialog(this);
    QVBoxLayout* layout=new QVBoxLayout(dialog);
    layout->addWidget(new QLabel(message,dialog));
    dialog->show();
}

void vistaGioco::setSchermata()
{
    grigliaComputer->setSpacing(0);
    grigliaGiocatore->setSpacing(0);

    setMinimumSize(QSize(400,400));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QFile file(":/risorse/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}

void vistaGioco::addButton()
{
    for(unsigned short int i=0;i<100;i++){
        ButtonB* button1=new ButtonB(i/10,i%10,this);
        button1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        connect(button1,SIGNAL(clickedCell(unsigned short, unsigned short)), controller, SLOT(moveG(unsigned short, unsigned short)));
        button1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        grigliaComputer->addWidget(button1, i/10, i%10);
        button1->setEnabled(true);
        ButtonB* button2=new ButtonB(i/10,i%10,this);
        button2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        grigliaGiocatore->addWidget(button2, i/10, i%10);
        button2->setEnabled(false);
    }
}

void vistaGioco::addLabel()
{
    std::stringstream naviG;
    std::stringstream naviC;

    naviC<<"numero navi Computer affondate: "<<controller->showNaviAffondateC();
    naviG<<"numero navi giocatore affondate: "<<controller->showNaviAffondateG();

    QLabel* naviComputerAffonfate=new QLabel(QString::fromStdString(naviC.str()));
    QLabel* naviGiocatoreAffondate=new QLabel(QString::fromStdString(naviG.str()));

    PannelloInformazioni->addWidget(naviComputerAffonfate);
    PannelloInformazioni->addWidget(naviGiocatoreAffondate);
}

void vistaGioco::inizializza_Griglie()
{
    for(unsigned short int i=0;i<100;i++){
        int playerG=controller->getPlayerG(i/10,i%10);
        if(playerG==1){
            QLayoutItem* item=grigliaGiocatore->itemAtPosition(i/10,i%10);
            QPushButton* buttonG=static_cast<QPushButton*>(item->widget());
            buttonG->setIcon(QIcon(":/risorse/quadratoRosso.png"));
        }
    }
}

void vistaGioco::addMenu()
{
    QMenuBar*menuBar=new QMenuBar(this);
    QMenu* menu=new QMenu("File",menuBar);
    QAction* exit=new QAction("Exit",menu);
    QAction* reset=new QAction("Reset", menu);
    connect(reset,SIGNAL(triggered()),controller,SLOT(resetGameG()));
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));

    menu->addAction(exit);

    menu->addAction(reset);

    menuBar->addMenu(menu);

    mainLayout->addWidget(menuBar);
}







