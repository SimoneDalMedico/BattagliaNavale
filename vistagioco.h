#ifndef VISTAGIOCO_H
#define VISTAGIOCO_H

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
#include <QVBoxLayout>
#include <sstream>
#include <QLayoutItem>
#include <QString>
#include <stdexcept>
#include "vistaposizione.h"

class vistaGioco : public QWidget
{
    Q_OBJECT
public:
    vistaGioco(Controller*,QWidget* parent=nullptr);
//    ~vistaGioco() =default;
    void update();
    void updateC();
    void resetGame();
    void showWinner();
    void updatePannelo();
    void ShowMessage(const QString &);
    void inizializza_Griglie();

private:
    Controller* controller;
    QHBoxLayout* mainLayout;
    QGridLayout* grigliaGiocatore;
    QGridLayout* grigliaComputer;
    QVBoxLayout* PannelloInformazioni;
    void setSchermata();
    void addMenu();
    void addButton();
    void addLabel();
};

#endif // VISTAGIOCO_H
