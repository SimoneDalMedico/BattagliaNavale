#include "naveassalto.h"
NaveAssalto::NaveAssalto()
{
    NaveAssalto::reset();
}

void NaveAssalto::assegna(unsigned short int X, unsigned short int Y)
{
    if(NaveAssalto::caselleNave.size()<2){
        cella nuova(X,Y);
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}

void NaveAssalto::operator=(NaveAssalto a)
{
    deep_ptr<cella>* it;

    for(it=a.caselleNave.begin();it!=a.caselleNave.end();it++){
        cella nuova(it->info.ShowX(),it->info.ShowY());
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}


