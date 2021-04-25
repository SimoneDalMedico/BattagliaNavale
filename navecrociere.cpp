#include "navecrociere.h"
NaveCrociere::NaveCrociere()
{
    NaveCrociere::reset();

}

NaveCrociere::~NaveCrociere()
{
    for(std::map< unsigned short int,cella>::iterator i=NaveCrociere::caselleNave.begin(); i!=NaveCrociere::caselleNave.end();i++){
        NaveCrociere::caselleNave.erase(i);
    }

}

void NaveCrociere::assegna(unsigned short X, unsigned short Y)
{
    if(NaveCrociere::caselleNave.size()<3){
            cella posizione(X,Y);
            std::map<unsigned short int,cella>::value_type a(NaveCrociere::caselleNave.size()+1,posizione);
            NaveCrociere::caselleNave.insert(a);
    }
}

void NaveCrociere::operator=(NaveCrociere cr)
{
    std::map<unsigned short int,cella>::iterator it2;
    for(it2=cr.NaveCrociere::caselleNave.begin();it2!=cr.NaveCrociere::caselleNave.end();it2++){
        cella posizione(it2->second.ShowX(), it2->second.ShowY());
        std::map<int,cella>::value_type a(it2->first,posizione);
        caselleNave.insert(a);
    }
}
