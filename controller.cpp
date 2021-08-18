#include "controller.h"

Controller::Controller(ModelloPosizione* p,QObject* parent):QObject(parent), vistaP(nullptr),modelloP(p){resetGameP();}//aggiunto resetGameP come prova

Controller::Controller(ModelloGioco * g, QObject *parent):QObject(parent),vistaG(nullptr),modelloG(g) {}

Controller::Controller(ModelloPosizione *p, ModelloGioco *g, QObject *parent):QObject(parent),vistaP(nullptr), vistaG(nullptr),modelloP(p),modelloG(g){}

void Controller::setViewG(vistaGioco* g)
{
    vistaG=g;
}

void Controller::setViewP(VistaPosizione* p)
{
    vistaP=p;
}

int Controller::getPlayer(unsigned short x, unsigned short y) const
{
    return (*modelloG)(x,y);
}

int Controller::getComp(unsigned short x, unsigned short y) const
{
    //meotdo da eliminare: solo per verificare posizione navi computer
    return modelloG->GetComp(x,y);
}


int Controller::getPlayerG(unsigned short x, unsigned short y) const
{
    return modelloG->GetPlayer(x,y);
}

int Controller::getPlayerP(unsigned short x, unsigned short y) const
{
    return (*modelloP)(x,y);
}

int Controller::getWinner() const
{
    return modelloG->winner();
}

bool Controller::CheckColpito(unsigned short row, unsigned short col)
{
    return modelloG->checkNaveColpita(row,col);
}

bool Controller::checkAffondato()
{
    return modelloG->checkNaveAffondata();
}

bool Controller::Turn()
{
    return modelloG->getTurn();
}

int Controller::showNaviAffondateG()
{
    return modelloG->numNaviAffondateG();
}

int Controller::showNaviAffondateC()
{
    return modelloG->numNaviAffondateC();
}

int Controller::showNaviPosizionateG()
{
    return modelloP->NaviPosizionateG();
}

int Controller::showNaviPosizionateC()
{
    return modelloP->NaviPosizionateC();
}

bool Controller::CheckPosizionato(unsigned short int x, unsigned short int y)
{
    return modelloP->checkPosizione(x,y);
}

void Controller::moveG(unsigned short row, unsigned short col)
{
    std::cout<<"controller->moveG->start"<<std::endl;
    try {
        modelloG->move(row,col);
        vistaG->update();



        if(modelloG->checkNaveColpita(row,col)==true){
            if(modelloG->checkNaveAffondata()==true){
                vistaG->updatePannelo();
            }
        }
        unsigned short int mossacomputer=static_cast<unsigned short int>(modelloG->SceltaComputer());
        modelloG->move(mossacomputer/10,mossacomputer%10);
        vistaG->updateC();
        if(modelloG->checkNaveColpita(mossacomputer/10,mossacomputer%10)==true){
            if(modelloG->checkNaveAffondata()==true){
                vistaG->updatePannelo();
            }
        }
        if(modelloG->winner()){
            vistaP->show();
            vistaG->hide();
            vistaG->showWinner();
            vistaG->resetGame();
            modelloG->reset();
            modelloP->reset();
            vistaP->resetPosizione();
            vistaP->updatePanelloP();

        }
    std::cout<<"controller->moveG->end"<<std::endl;
    } catch (std::exception*exc) {

        vistaG->ShowMessage(exc->what());
    }

}

void Controller::posiziona(unsigned short row, unsigned short col)
{

    try {
       modelloP->move(row,col);
       vistaP->update();
       vistaP->updatePanelloP();
       modelloP->moveC();
       vistaP->updateC(); //da eliminare
       vistaP->updatePanelloP();
       if(modelloP->CeckFinePosizionamento()){
            vistaG->show();
            vistaG->resetGame();
            vistaP->close();
            vistaG->ShowMessage("finita fase di posizionamento, Adesso si gioca!");
            vistaG->updatePannelo();
            modelloG->riempiGriglie(modelloP);
            vistaG->inizializza_Griglie();
       }
   } catch (std::exception* exc) {
        vistaP->ShowMessage(exc->what());
    }
}

void Controller::resetGameG()
{
    modelloG->reset();
    modelloP->reset();

    vistaP->resetPosizione();

    vistaG->close();
    vistaP->show();
    vistaP->updatePanelloP();
}

void Controller::resetGameP()
{
    modelloP->reset();
    vistaP->resetPosizione();
    vistaP->updatePanelloP();
}
void Controller::sendHelp(){
    vistaG->showHelp();
}

