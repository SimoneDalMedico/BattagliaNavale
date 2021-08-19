#include "navecrociere.h"
NaveCrociere::NaveCrociere()
{
    NaveCrociere::reset();

}

void NaveCrociere::assegna(unsigned short X, unsigned short Y)
{
    if(NaveCrociere::caselleNave.size()<3){
            cella posizione(X,Y);

            NaveCrociere::caselleNave.push_back(posizione);
    }
}

//NaveCrociere::~NaveCrociere()
//{
//    for(std::map< unsigned short int,cella>::iterator i=NaveCrociere::caselleNave.begin(); i!=NaveCrociere::caselleNave.end();i++){
//        NaveCrociere::caselleNave.erase(i);
//    }

//}

void NaveCrociere::assegnaC(unsigned short X, unsigned short Y)
{
    if(NaveCrociere::caselleNave.size()<3 && SceltePosizionamentoComputer[X*10+Y]){
            cella posizione(X,Y);

            NaveCrociere::caselleNave.push_back(posizione);
            SceltePosizionamentoComputer.erase(X*10+Y);
    }
}

void NaveCrociere::operator=(NaveCrociere cr)
{
    std::list<cella>::iterator it2;
    for(it2=cr.NaveCrociere::caselleNave.begin();it2!=cr.NaveCrociere::caselleNave.end();it2++){
        cella posizione(it2->ShowX(), it2->ShowY());
        caselleNave.push_back(posizione);
    }
}
