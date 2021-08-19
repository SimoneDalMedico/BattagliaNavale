#include "navecorazzata.h"

NaveCorazzata::NaveCorazzata()
{
    NaveCorazzata::reset();
}

void NaveCorazzata::assegna(unsigned short X, unsigned short Y)
{
    if(NaveCorazzata::caselleNave.size()<4){
           cella posizione(X,Y);
           NaveCorazzata::caselleNave.push_back(posizione);
    }
}


void NaveCorazzata::assegnaC(unsigned short X, unsigned short Y)
{
    if(NaveCorazzata::caselleNave.size()<4 && SceltePosizionamentoComputer[X*10+Y]){
           cella posizione(X,Y);
           NaveCorazzata::caselleNave.push_back(posizione);
           SceltePosizionamentoComputer.erase(X*10+Y);
    }
}

void NaveCorazzata::operator=(NaveCorazzata co)
{
    
    std::list<cella>::iterator it;
    for(it=co.caselleNave.begin();it!=co.caselleNave.end();it++){
        cella posizione(it->ShowX(), it->ShowY());
        caselleNave.push_back(posizione);
    }
}
