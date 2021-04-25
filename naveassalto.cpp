#include "naveassalto.h"
NaveAssalto::NaveAssalto()
{
    NaveAssalto::reset();
}

void NaveAssalto::assegna(unsigned short int X, unsigned short int Y)
{
    if(NaveAssalto::caselleNave.size()<2){
            cella posizione(X,Y);
            std::map<int,cella>::value_type a(NaveAssalto::caselleNave.size()+1 ,posizione);
            NaveAssalto::caselleNave.insert(a);
    }
}

void NaveAssalto::operator=(NaveAssalto a)
{
    std::map<unsigned short int,cella>::iterator it;

    for(it=a.caselleNave.begin();it!=a.caselleNave.end();it++){
        cella posizione(it->second.ShowX(), it->second.ShowY());
        std::map<int,cella>::value_type a(it->first,posizione);
        caselleNave.insert(a);
    }
}


