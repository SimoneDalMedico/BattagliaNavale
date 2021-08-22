#include "naveassalto.h"

NaveAssalto::NaveAssalto()
{
    NaveAssalto::reset();
}

void NaveAssalto::assegna(unsigned short X, unsigned short Y)
{
    if(NaveAssalto::caselleNave.size()<2){
            cella posizione(X,Y);
            NaveAssalto::caselleNave.push_back(posizione);
    }
}

void NaveAssalto::assegnaC(unsigned short int X, unsigned short int Y)
{
    if(NaveAssalto::caselleNave.size()<2){
            cella posizione(X,Y);

            NaveAssalto::caselleNave.push_back(posizione);
            SceltePosizionamentoComputer.erase(X*10+Y);
    }
}

void NaveAssalto::operator=(NaveAssalto a)
{
    std::list<cella>::iterator it;
    for(it=a.caselleNave.begin();it!=a.caselleNave.end();it++){
        cella posizione(it->ShowX(), it->ShowY());
        caselleNave.push_back(posizione);
    }
}


