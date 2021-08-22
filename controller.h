#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "modellogioco.h"
#include "modelloposizione.h"
#include "vistagioco.h"
#include "vistaposizione.h"

class Controller:public QObject
{
    Q_OBJECT
public:
    explicit Controller( ModelloPosizione*, QObject* parent=nullptr);
    explicit Controller(ModelloGioco*, QObject* prent=nullptr);
    explicit Controller(ModelloPosizione* , ModelloGioco*, QObject* prent=nullptr);
    void setViewG(vistaGioco*);
    void setViewP(VistaPosizione*);
    int getPlayer(unsigned short, unsigned short) const;
    int getPlayerG(unsigned short, unsigned short) const;
    int getPlayerP(unsigned short int, unsigned short int) const;
    int getWinner() const;
    bool CheckColpito(unsigned short, unsigned short);
    bool checkAffondato();
    bool Turn();
    int showNaviAffondateG();
    int showNaviAffondateC();
    int showNaviPosizionateG();
    int showNaviPosizionateC();
    bool CheckPosizionato(unsigned short int, unsigned short int);
public slots:
    void posiziona(unsigned short , unsigned short);
    void moveG(unsigned short , unsigned short);
    void resetGameG();
    void resetGameP();
    void sendHelp();
private:
    VistaPosizione* vistaP;
    vistaGioco* vistaG;
    ModelloPosizione* modelloP;
    ModelloGioco* modelloG;
};

#endif // CONTROLLER_H
