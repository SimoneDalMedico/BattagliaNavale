#ifndef NAVE_H
#define NAVE_H
#include "cella.h"
#include <random>
#include <map>
#include <iostream>
//#include <QRandomGenerator>
#include <vector>
//typedef std::pair<unsigned short int, unsigned short int> tpair;

class Nave : public cella
{

public:
    Nave() =default;
//    virtual ~Nave() =default;
    Nave(unsigned short int, unsigned short int);
    bool colpita(unsigned short int, unsigned short int);
    bool affondata();
    virtual void assegna(unsigned short int, unsigned short int) =0;
    void reset();
    int counter();
    bool check_posizione(unsigned short int, unsigned short int);
    void Posizionamentocomputer();
    unsigned short int PosizionaGrigliaC();

protected:

    std::map<unsigned short int, cella> caselleNave;

};

#endif // NAVE_H
