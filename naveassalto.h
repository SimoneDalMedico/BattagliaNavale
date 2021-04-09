#ifndef NAVEASSALTO_H
#define NAVEASSALTO_H
#include "nave.h"
#include "dimensione.h"
class NaveAssalto: public Nave, public Dimensione
{
    friend class Giocatore;
    friend class Computer;
public:
    NaveAssalto();
    ~NaveAssalto()=default;
    void assegna(unsigned short, unsigned short);
    void operator=(NaveAssalto);
};
#endif // NAVEASSALTO_H
