#ifndef GIOCATORE_H
#define GIOCATORE_H
//#include "nave.h"
#include "naveassalto.h"
#include "navecorazzata.h"
#include "navecrociere.h"
#include "naveportaerei.h"
#include "contenitore.h"
#include "cella.h"
#include "deep_ptr.h"

class Giocatore
{
    friend class Model;
    friend class ModelloGioco;
    friend class ModelloPosizione;
public:
    Giocatore();
    Giocatore(const Giocatore&);
    ~Giocatore()=default;
    void operator=(Giocatore);
protected:
    contenitore<deep_ptr<cella>> navi;
    static const int Turno=0;
    int numero_Navi_Affondate;
    int numeroNaviPosizionate;
};

#endif // GIOCATORE_H
