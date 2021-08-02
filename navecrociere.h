#ifndef NAVECROCIERE_H
#define NAVECROCIERE_H
#include"nave.h"
#include "dimensione.h"
class NaveCrociere : public Nave
{
    friend class Giocatore;
    friend class Computer;
public:
    NaveCrociere();
//    ~NaveCrociere();
    void assegna(unsigned short int, unsigned short int);
    void operator=(NaveCrociere);
};

#endif // NAVECROCIERE_H
