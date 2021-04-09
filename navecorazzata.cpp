#include "navecorazzata.h"

NaveCorazzata::NaveCorazzata()
{
    NaveCorazzata::reset();
}


void NaveCorazzata::assegna(unsigned short X, unsigned short Y)
{
    if(NaveCorazzata::caselleNave.size()<dimensioneCorzzata){
           tpair posizione=std::pair<unsigned short int, unsigned short int>(X,Y);
           std::map< unsigned short int,tpair>::value_type a(NaveCorazzata::caselleNave.size()+1,posizione);
           NaveCorazzata::caselleNave.insert(a);
    }
}

void NaveCorazzata::operator=(NaveCorazzata co)
{
    
    std::map<unsigned short int,tpair>::iterator it;
    for(it=co.caselleNave.begin();it!=co.caselleNave.end();it++){
        tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first, it->second.second);
        std::map<int,tpair>::value_type a(it->first,posizione);
        caselleNave.insert(a);
    }
}
