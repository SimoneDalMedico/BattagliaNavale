#include "naveportaerei.h"

NavePortaerei::NavePortaerei()
{
    NavePortaerei::reset();
}

void NavePortaerei::assegna(unsigned short X, unsigned short Y)
{
    if(NavePortaerei::caselleNave.size()<5){
            cella posizione(X,Y);

            NavePortaerei::caselleNave.push_back(posizione);
    }
}

void NavePortaerei::operator=(NavePortaerei a)
{
    std::list<cella>::iterator it;
    for(it=a.caselleNave.begin();it!=a.caselleNave.end();it++){
        cella posizione(it->ShowX(), it->ShowY());
        caselleNave.push_back(posizione);
    }
}
