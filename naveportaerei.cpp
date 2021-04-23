#include "naveportaerei.h"

NavePortaerei::NavePortaerei()
{
    NavePortaerei::reset();
}

void NavePortaerei::assegna(unsigned short X, unsigned short Y)
{
    if(NavePortaerei::caselleNave.size()<5){
            tpair posizione=std::pair<unsigned short int, unsigned short int>(X,Y);
            std::map<unsigned short int,tpair>::value_type a(NavePortaerei::caselleNave.size()+1,posizione);
            NavePortaerei::caselleNave.insert(a);
    }
}

void NavePortaerei::operator=(NavePortaerei a)
{
    std::map<unsigned short int,tpair>::iterator it;
    for(it=a.caselleNave.begin();it!=a.caselleNave.end();it++){
        tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first, it->second.second);
        std::map<int,tpair>::value_type a(it->first,posizione);
        caselleNave.insert(a);
    }
}
