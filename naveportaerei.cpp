#include "naveportaerei.h"

NavePortaerei::NavePortaerei()
{
    NavePortaerei::reset();
}

void NavePortaerei::assegna(unsigned short X, unsigned short Y)
{
    if(NavePortaerei::caselleNave.size()<5){
            cella posizione(X,Y);
            std::map<unsigned short int,cella>::value_type a(NavePortaerei::caselleNave.size()+1,posizione);
            NavePortaerei::caselleNave.insert(a);
    }
}

void NavePortaerei::operator=(NavePortaerei a)
{
    std::map<unsigned short int,cella>::iterator it;
    for(it=a.caselleNave.begin();it!=a.caselleNave.end();it++){
        cella posizione(it->second.ShowX(), it->second.ShowY());
        std::map<int,cella>::value_type a(it->first,posizione);
        caselleNave.insert(a);
    }
}
