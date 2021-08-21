#ifndef NAVEASSALTO_H
#define NAVEASSALTO_H
#include "nave.h"

class NaveAssalto: public Nave
{
    friend class Giocatore;
    friend class Computer;
public:
    NaveAssalto();
    void assegna(unsigned short int, unsigned short int);
    void assegnaC(unsigned short int, unsigned short int);
    void operator=(NaveAssalto);
};
#endif // NAVEASSALTO_H
