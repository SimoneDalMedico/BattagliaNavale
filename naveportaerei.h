#ifndef NAVEPORTAEREI_H
#define NAVEPORTAEREI_H
#include "nave.h"
#include "dimensione.h"
class NavePortaerei : public Nave, public Dimensione
{
    friend class Giocatore;
    friend class Computer;
public:
    NavePortaerei();

    ~NavePortaerei()=default;
    void assegna(unsigned short int, unsigned short int);
    void operator=(NavePortaerei);
};

#endif // NAVEPORTAEREI_H
