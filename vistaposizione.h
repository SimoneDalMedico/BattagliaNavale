#ifndef VISTAPOSIZIONE_H
#define VISTAPOSIZIONE_H
#include <QWidget>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QFile>
#include <QIcon>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include <QLayoutItem>
#include <QString>
#include <stdexcept>
#include <QImage>
#include "buttonb.h"
class Controller;

class VistaPosizione: public QWidget
{
    Q_OBJECT
    friend class vistaGioco;
public:
    VistaPosizione(Controller*, QWidget* parent=nullptr);
    VistaPosizione(VistaPosizione* );
    ~VistaPosizione()=default;
    void update();
    void updateC(); //da eliminare: serve per controllare il osiuzionamento di computer
    void updatePanelloP();
    void resetPosizione();
    void ShowMessage(const QString&);

protected:
   Controller* controller;
   QBoxLayout* masterLayout;
   QHBoxLayout * mainLayout;
   QVBoxLayout* PannelloInformazioniP;
   QGridLayout* grigliaComputer;
   QGridLayout* grigliaGiocatore;
   QImage* image;
   void setSchermata();
   void addMenu();
   void addButton();
   void addButtonHelp();
   void addLabelP();
};
#endif //VISTAPOSIZIONE_H
