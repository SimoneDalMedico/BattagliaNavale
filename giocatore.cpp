#include "giocatore.h"
#include "contenitore.h"

Giocatore::Giocatore()
{
    numeroNaviPosizionate=0;
    numero_Navi_Affondate=0;
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
}

Giocatore::Giocatore(const Giocatore & G)
{
    numeroNaviPosizionate=0;
    numero_Navi_Affondate=0;
    navi=G.navi;
}

void Giocatore::operator=(Giocatore pos)
{
    navi=pos.navi;
}
