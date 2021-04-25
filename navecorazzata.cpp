#include "navecorazzata.h"

NaveCorazzata::NaveCorazzata()
{
    NaveCorazzata::reset();
}


void NaveCorazzata::assegna(unsigned short X, unsigned short Y)
{
    if(NaveCorazzata::caselleNave.size()<4){
           cella posizione(X,Y);
           std::map< unsigned short int,cella>::value_type a(NaveCorazzata::caselleNave.size()+1,posizione);
           NaveCorazzata::caselleNave.insert(a);
    }
}

void NaveCorazzata::operator=(NaveCorazzata co)
{
    
    std::map<unsigned short int,cella>::iterator it;
    for(it=co.caselleNave.begin();it!=co.caselleNave.end();it++){
        cella posizione(it->second.ShowX(), it->second.ShowY());
        std::map<int,cella>::value_type a(it->first,posizione);
        caselleNave.insert(a);
    }
}
