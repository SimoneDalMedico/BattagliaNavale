#include "giocatore.h"

Giocatore::Giocatore()
{
    numeroNaviPosizionate=0;
    numero_Navi_Affondate=0;
    deep_ptr<cella> assalto=new NaveAssalto();
    navi.pushBack(assalto);
    deep_ptr<cella> crociere=new NaveCrociere();
    navi.pushBack(crociere);
    deep_ptr<cella> corazzata=new NaveCorazzata();
    navi.pushBack(corazzata);
    deep_ptr<cella> portarei=new NavePortaerei();
    navi.pushBack(portarei);
}

void Giocatore::operator=(Giocatore pos)
{
    navi=pos.navi;
//    assalto=pos.assalto;
//    crociere=pos.crociere;
//    corazzata=pos.corazzata;
//    portaerei=pos.portaerei;
}
