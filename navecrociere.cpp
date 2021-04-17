#include "navecrociere.h"
NaveCrociere::NaveCrociere()
{
    NaveCrociere::reset();

}

NaveCrociere::~NaveCrociere()
{
    for(deep_ptr<cella>* i=NaveCrociere::caselleNave.begin(); i!=NaveCrociere::caselleNave.end();i++){
        NaveCrociere::caselleNave.erase(i);
    }

}

void NaveCrociere::assegna(unsigned short X, unsigned short Y)
{
    if(NaveCrociere::caselleNave.size()<3){
        cella nuova(X,Y);
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}

void NaveCrociere::operator=(NaveCrociere cr)
{
    deep_ptr<cella>* it2;
    for(it2=cr.NaveCrociere::caselleNave.begin();it2!=cr.NaveCrociere::caselleNave.end();it2++){
        cella nuova(it2->info.ShowX(), it2->info.ShowY());
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}
