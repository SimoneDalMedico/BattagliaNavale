#include "giocatore.h"

Giocatore::Giocatore()
{
    numeroNaviPosizionate=0;
    numero_Navi_Affondate=0;
}

void Giocatore::operator=(Giocatore pos)
{
    assalto=pos.assalto;
    crociere=pos.crociere;
    corazzata=pos.corazzata;
    portaerei=pos.portaerei;
}
