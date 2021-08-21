#ifndef NAVECROCIERE_H
#define NAVECROCIERE_H
#include"nave.h"

class NaveCrociere : public Nave
{
    friend class Giocatore;
    friend class Computer;
public:
    NaveCrociere();
    void assegna(unsigned short int, unsigned short int);
    void assegnaC(unsigned short int, unsigned short int);
    void operator=(NaveCrociere);
};

#endif // NAVECROCIERE_H
