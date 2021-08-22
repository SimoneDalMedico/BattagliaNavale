#ifndef NAVECORAZZATA_H
#define NAVECORAZZATA_H
#include "nave.h"

class NaveCorazzata : public Nave
{
    friend class Giocatore;
    friend class Computer;
public:
    NaveCorazzata();
    void assegna(unsigned short int, unsigned short int);
    void assegnaC(unsigned short int, unsigned short int);
    void operator=(NaveCorazzata);
};

#endif // NAVECORAZZATA_H
