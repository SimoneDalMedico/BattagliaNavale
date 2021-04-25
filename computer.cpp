#include "computer.h"

Computer::Computer()
{
    numeroNaviPosizionate=0;
    numero_Navi_Affondate=0;

    for(unsigned short int i=0;i<100;i++){
        std::map<unsigned short int, unsigned short int>::value_type v(i,i);
        SceltePossibili.insert(v);
    }

    cella* cella_assalto=new NaveAssalto();
    deep_ptr<cella> assalto(cella_assalto);
    navi.pushBack(assalto);

    cella* cella_crociere=new NaveCrociere();
    deep_ptr<cella> crociere(cella_crociere);
    navi.pushBack(crociere);

    cella* cella_corazzata=new NaveCorazzata();
    deep_ptr<cella> corazzata(cella_corazzata);
    navi.pushBack(corazzata);

    cella* cella_portaaerei=new NavePortaerei();
    deep_ptr<cella> portaaerei(cella_portaaerei);
    navi.pushBack(portaaerei);

//    deep_ptr<cella> assalto=new NaveAssalto();
//    navi.pushBack(assalto);
//    deep_ptr<cella> crociere=new NaveCrociere();
//    navi.pushBack(crociere);
//    deep_ptr<cella> corazzata=new NaveCorazzata();
//    navi.pushBack(corazzata);
//    deep_ptr<cella> portarei=new NavePortaerei();
//    navi.pushBack(portarei);

}

void Computer::operator=(Computer pos)
{
    for(unsigned short int i=0;i<100;i++){
        std::map<unsigned short int, unsigned short int>::value_type v(i,i);
        SceltePossibili.insert(v);
    }
    navi=pos.navi;
}

unsigned short int Computer::SceltaComputer()
{
    unsigned short int n=0;
    unsigned short int A[SceltePossibili.size()];

    for(std::map<unsigned short int, unsigned short int>::iterator it=SceltePossibili.begin(); it!=SceltePossibili.end();it++){
       A[n]=it->second;
        n++;
    }
     unsigned short int scelta=rand()% n;
     return A[scelta];
}
