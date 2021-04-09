#ifndef MODELLOGIOCO_H
#define MODELLOGIOCO_H
#include "model.h"
#include "modelloposizione.h"
//#include <QRandomGenerator>

class ModelloGioco: public Model
{
public:
    ModelloGioco();
    ModelloGioco(ModelloPosizione*);
    ~ModelloGioco()=default;
    void move(unsigned short int, unsigned short int);

    int SceltaComputer();
    void reset();
    Player winner() const;
    unsigned short int countFrame(Player player) const;
    Player operator()(unsigned short, unsigned short);
    bool getTurn();
    bool checkWinner();
    bool checkNaveColpita(unsigned short, unsigned short);
    bool checkNaveAffondata();
    bool CheckScelta(unsigned short int, unsigned short int);
    void riempiGriglie(ModelloPosizione*);
    Player GetPlayer(unsigned short int, unsigned short int);
    int numNaviAffondateG();
    int numNaviAffondateC();
private:
    Giocatore giocatore;
    Computer computer;






};

#endif // MODELLOGIOCO_H
