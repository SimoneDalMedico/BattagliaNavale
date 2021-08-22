#ifndef COMPUTER_H
#define COMPUTER_H

#include "naveassalto.h"
#include "navecorazzata.h"
#include "navecrociere.h"
#include "naveportaerei.h"
#include "contenitore.h"
#include "cella.h"
#include "deep_ptr.h"

class Computer
{
    friend class Modello;
    friend class ModelloGioco;
    friend class ModelloPosizione;
public:
    Computer();
    Computer(const Computer&);
    void operator=(Computer);
    unsigned short int SceltaComputer();
protected:

    std::map<unsigned short int,unsigned short int> SceltePossibili;
    contenitore<deep_ptr<cella>> navi;
    static const int Turno=1;
    int numero_Navi_Affondate;
    int numeroNaviPosizionate;
};

#endif // COMPUTER_H
