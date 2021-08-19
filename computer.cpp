#include "computer.h"

Computer::Computer()
{
    numeroNaviPosizionate=0;
    numero_Navi_Affondate=0;
    SceltePossibili.clear();
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

Computer::Computer(const Computer &C)
{
    navi=C.navi;
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
    std::cout<<"computer->sceltacomputer->start"<<std::endl;
    unsigned short int n=0;
    unsigned short int A[SceltePossibili.size()];
    std::cout<<"computer->sceltacomputer->Sceltepossibili.size = "<<SceltePossibili.size()<<std::endl;
    std::cout<<"computer->sceltacomputer->iniziofor"<<std::endl;
    for(std::map<unsigned short int, unsigned short int>::iterator it=SceltePossibili.begin(); it!=SceltePossibili.end();it++){
       A[n]=it->second;
        n++;
    }
    std::cout<<"computer->sceltacomputer->finefor"<<std::endl;
     unsigned short int scelta=rand()% n;
//     SceltePossibili.erase(scelta);
     std::cout<<"computer->sceltacomputer->scelta = "<<scelta<<std::endl;
     std::cout<<"computer->sceltacomputer->A[scelta] = "<<A[scelta]<<std::endl;
     return A[scelta];
}
