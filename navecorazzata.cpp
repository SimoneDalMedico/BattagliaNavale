#include "navecorazzata.h"

NaveCorazzata::NaveCorazzata()
{
    NaveCorazzata::reset();
}


void NaveCorazzata::assegna(unsigned short X, unsigned short Y)
{
    if(NaveCorazzata::caselleNave.size()<4){
        cella nuova(X,Y);
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}

void NaveCorazzata::operator=(NaveCorazzata co)
{
    
    deep_ptr<cella>* it;
    for(it=co.caselleNave.begin();it!=co.caselleNave.end();it++){
        cella nuova(it->info.ShowX(),it->info.ShowY());
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}
