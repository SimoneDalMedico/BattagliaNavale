#ifndef MODELLOPOSIZIONE_H
#define MODELLOPOSIZIONE_H
#include "model.h"
class ModelloPosizione: public Model
{
    friend class ModelloGioco;
public:
    ModelloPosizione();

    ~ModelloPosizione()=default;
    Player operator()(unsigned short int, unsigned short int) const;
    void move(unsigned short int, unsigned short int) override;
    void moveC();
    void reset() override;

    bool CeckFinePosizionamento();
    bool checkPosizione(unsigned short int, unsigned short int);
    int NaviPosizionateG();
    int NaviPosizionateC();
    bool checkSpazioNave(unsigned short int, unsigned short int);

protected:
    Giocatore giocatore;
    Computer computer;


};

#endif // MODELLOPOSIZIONE_H
