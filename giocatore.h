#ifndef GIOCATORE_H
#define GIOCATORE_H
#include "naveassalto.h"
#include "navecorazzata.h"
#include "navecrociere.h"
#include "naveportaerei.h"

class Giocatore
{
    friend class Model;
    friend class ModelloGioco;
    friend class ModelloPosizione;
public:
    Giocatore();
    void operator=(Giocatore);

protected:
//    contenitore<deep_ptr<cella>> naveAssalto;
    //se inserisco i puntatori all albero di derivazionein giocatore e computer?
    NaveAssalto assalto;
    NaveCrociere crociere;
    NaveCorazzata corazzata;
    NavePortaerei portaerei;
    static const int Turno=0;
    int numero_Navi_Affondate;
    int numeroNaviPosizionate;
};

#endif // GIOCATORE_H
