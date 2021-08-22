#ifndef NAVE_H
#define NAVE_H
#include "cella.h"
#include <random>
#include <map>
#include <iostream>
#include <list>

class Nave : public cella
{

public:
    Nave();
    Nave(unsigned short int, unsigned short int);
    bool colpita(unsigned short int, unsigned short int);
    bool affondata();
    virtual void assegna(unsigned short int, unsigned short int) =0;
    virtual void assegnaC(unsigned short int, unsigned short int)=0;
    void reset();
    int counter();
    bool check_posizione(unsigned short int, unsigned short int);
    void Posizionamentocomputer();
    unsigned short int PosizionaGrigliaCFine();
    unsigned short int PosizionaGrigliaCInizio();
protected:
      std::list<cella> caselleNave;
      static std::map<unsigned short, unsigned short> SceltePosizionamentoComputer;
};



#endif // NAVE_H
