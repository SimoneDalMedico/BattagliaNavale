#ifndef NAVE_H
#define NAVE_H
#include <random>
#include <map>
#include <iostream>
//#include <QRandomGenerator>
#include <vector>
typedef std::pair<unsigned short int, unsigned short int> tpair;

class Nave
{

public:

    bool colpita(unsigned short int, unsigned short int);
    bool affondata();
    virtual void assegna(unsigned short int, unsigned short int) =0;
    void reset();
    int counter();
    bool check_posizione(unsigned short int, unsigned short int);
    void Posizionamentocomputer();
    unsigned short int PosizionaGrigliaC();

protected:

    std::map<unsigned short int, tpair> caselleNave;

};

#endif // NAVE_H
