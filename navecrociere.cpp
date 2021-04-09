#include "navecrociere.h"
NaveCrociere::NaveCrociere()
{
    NaveCrociere::reset();

}

NaveCrociere::~NaveCrociere()
{
    for(std::map< unsigned short int,tpair>::iterator i=NaveCrociere::caselleNave.begin(); i!=NaveCrociere::caselleNave.end();i++){
        NaveCrociere::caselleNave.erase(i);
    }

}

void NaveCrociere::assegna(unsigned short X, unsigned short Y)
{
    if(NaveCrociere::caselleNave.size()<dimensioneCrociere){
            tpair posizione=std::pair<unsigned short int, unsigned short int>(X,Y);
            std::map<unsigned short int,tpair>::value_type a(NaveCrociere::caselleNave.size()+1,posizione);
            NaveCrociere::caselleNave.insert(a);
    }
}

void NaveCrociere::operator=(NaveCrociere cr)
{
    std::map<unsigned short int,tpair>::iterator it2;
    for(it2=cr.NaveCrociere::caselleNave.begin();it2!=cr.NaveCrociere::caselleNave.end();it2++){
        tpair posizione=std::pair<unsigned short int, unsigned short int>(it2->second.first, it2->second.second);
        std::map<int,tpair>::value_type a(it2->first,posizione);
        caselleNave.insert(a);
    }
}
