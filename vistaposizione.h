#ifndef VISTAPOSIZIONE_H
#define VISTAPOSIZIONE_H
#include <QWidget>
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
#include "buttonb.h"
class Controller;

class VistaPosizione: public QWidget
{
    Q_OBJECT
    friend class vistaGioco;
public:
    VistaPosizione(Controller*, QWidget* parent=nullptr);
    VistaPosizione(VistaPosizione* );
//    ~VistaPosizione()=default;
    void update();
    void updatePanelloP();
    void resetPosizione();
    void ShowMessage(const QString&);

protected:
   Controller* controller;
   QHBoxLayout * mainLayout;
   QVBoxLayout* PannelloInformazioniP;
   QGridLayout* grigliaComputer;
   QGridLayout* grigliaGiocatore;
   void setSchermata();
   void addMenu();
   void addButton();
   void addLabelP();
};
#endif //VISTAPOSIZIONE_H
