#include "naveassalto.h"
NaveAssalto::NaveAssalto()
{
    NaveAssalto::reset();
}

void NaveAssalto::assegna(unsigned short int X, unsigned short int Y)
{
    if(NaveAssalto::caselleNave.size()<dimensioneAssalto){
            tpair posizione=std::pair<unsigned short int, unsigned short int>(X,Y);
            std::map<int,tpair>::value_type a(NaveAssalto::caselleNave.size()+1 ,posizione);
            NaveAssalto::caselleNave.insert(a);
    }
}

void NaveAssalto::operator=(NaveAssalto a)
{
    std::map<unsigned short int,tpair>::iterator it;

    for(it=a.caselleNave.begin();it!=a.caselleNave.end();it++){
        tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first, it->second.second);
        std::map<int,tpair>::value_type a(it->first,posizione);
        caselleNave.insert(a);
    }
}


