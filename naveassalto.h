#ifndef NAVEASSALTO_H
#define NAVEASSALTO_H
#include "nave.h"
#include "dimensione.h"
class NaveAssalto: public Nave
{
    friend class Giocatore;
    friend class Computer;
public:
    NaveAssalto();
//    ~NaveAssalto()=default;
    void assegna(unsigned short int, unsigned short int);
    void operator=(NaveAssalto);
};
#endif // NAVEASSALTO_H
