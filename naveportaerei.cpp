#include "naveportaerei.h"

NavePortaerei::NavePortaerei()
{
    NavePortaerei::reset();
}

void NavePortaerei::assegna(unsigned short X, unsigned short Y)
{
    if(NavePortaerei::caselleNave.size()<5){
        cella nuova(X,Y);
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}

void NavePortaerei::operator=(NavePortaerei a)
{
    deep_ptr<cella>* it;
    for(it=a.caselleNave.begin();it!=a.caselleNave.end();it++){
        cella nuova(it->info.ShowX(), it->info.ShowY());
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}
