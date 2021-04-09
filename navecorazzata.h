#ifndef NAVECORAZZATA_H
#define NAVECORAZZATA_H
#include "nave.h"
#include "dimensione.h"
class NaveCorazzata : public Nave, public Dimensione
{
    friend class Giocatore;
    friend class Computer;
public:
    NaveCorazzata();
    ~NaveCorazzata()=default;
    void assegna(unsigned short int, unsigned short int);
    void operator=(NaveCorazzata);
};

#endif // NAVECORAZZATA_H
