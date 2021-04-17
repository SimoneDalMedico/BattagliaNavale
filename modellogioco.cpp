#include "modellogioco.h"

ModelloGioco::ModelloGioco()
{
    reset();
}

ModelloGioco::ModelloGioco(ModelloPosizione* p)
{
    giocatore.numero_Navi_Affondate=0;
    computer.numero_Navi_Affondate=0;
    for(unsigned short int i=0;i<100;i++){
        grigliaComputer[i]=p->grigliaComputer[i];
        grigliaGiocatore[i]=p->grigliaGiocatore[i];
    }

}

void ModelloGioco::move(unsigned short int x, unsigned short int y)
{
    if(turn==giocatore.Turno){
        if(x>10 && y>10){
            throw new std::domain_error("Exception: (" + std::to_string(x) + ", " + std::to_string(y) +") è fuori dal bound della griglia");
        }

        if(grigliaComputer[x*10+y]==playerC){
            grigliaComputer[x*10+y]=playerG;
        }else{
            if(grigliaComputer[x*10+y]==none){
                grigliaComputer[x*10+y]=playerMancata;
            }
        }

    }else{
        std::map<unsigned short int,unsigned short int>::iterator it;
        it=computer.SceltePossibili.find(x*10+y);
                    if(grigliaGiocatore[x*10+y]==playerG){
                        grigliaGiocatore[x*10+y]=playerC;
                    }else{
                        if(grigliaGiocatore[x*10+y]==none){
                            grigliaGiocatore[x*10+y]=playerMancata;
                        }
                    }

        computer.SceltePossibili.erase(it);
    }
    turn=!turn;
}

int ModelloGioco::SceltaComputer()
{
    return computer.SceltaComputer();
}

void ModelloGioco::reset()
{
    turn=0;
    for(u_int i=0;i<100;i++){
        grigliaComputer[i]=none;
        grigliaGiocatore[i]=none;
    }
    computer.SceltePossibili.clear();
    for(unsigned short int i=0;i<100;i++){
        std::map<unsigned short int, unsigned short int>::value_type v(i,i);
        computer.SceltePossibili.insert(v);
    }
    giocatore.numeroNaviPosizionate=0;
    computer.numeroNaviPosizionate=0;

    giocatore.numero_Navi_Affondate=0;
    computer.numero_Navi_Affondate=0;

    giocatore.assalto.reset();
    giocatore.crociere.reset();
    giocatore.corazzata.reset();
    giocatore.portaerei.reset();

    computer.assalto.reset();
    computer.crociere.reset();
    computer.corazzata.reset();
    computer.portaerei.reset();
}

Player ModelloGioco::winner() const
{
    if(giocatore.numero_Navi_Affondate==4){
        return playerC;
    }
    if(computer.numero_Navi_Affondate==4){
        return playerG;
    }
    return none;
}

unsigned short ModelloGioco::countFrame(Player player) const
{   u_int counter=0;
    if(player==playerG){
        for(u_int i=0;i<100;i++){
            counter+=(grigliaGiocatore[i]==player);
        }
    }else{
        for(u_int i=0;i<100;i++){
            counter+=(grigliaComputer[i]==player);
        }
    }
    return counter;
}

Player ModelloGioco::operator()(unsigned short row, unsigned short col)
{
    if(row>10 && col>10){
        return none;
    }
    if(turn==giocatore.Turno){
        return grigliaGiocatore[row*10+col];

    }else{
        return grigliaComputer[row*10+col];
    }
}

bool ModelloGioco::getTurn()
{
    return turn;
}

bool ModelloGioco::checkWinner()
{
    if(giocatore.numero_Navi_Affondate==4 || computer.numero_Navi_Affondate==4){
        return true;
    }
    return false;
}

bool ModelloGioco::checkNaveColpita(unsigned short x, unsigned short y)
{
        if(turn==Giocatore::Turno){
            if(giocatore.assalto.colpita(x,y)){
                return true;
            }
            if(giocatore.corazzata.colpita(x,y)){
                return true;
            }
            if(giocatore.crociere.colpita(x,y)){
                return true;
            }
            if(giocatore.portaerei.colpita(x,y)){
                return true;
            }
        }else{
            if(computer.assalto.colpita(x,y)){
                return true;
            }
            if(computer.corazzata.colpita(x,y)){
                return true;
            }
            if(computer.crociere.colpita(x,y)){
                return true;
            }
            if(computer.portaerei.colpita(x,y)){
                return true;
            }
        }
        return false;
}

bool ModelloGioco::checkNaveAffondata()
{
    if(turn==computer.Turno){
        computer.numero_Navi_Affondate=0;
        if(computer.assalto.affondata()){
            computer.numero_Navi_Affondate++;
        }
        if(computer.crociere.affondata()){
            computer.numero_Navi_Affondate++;
        }
        if(computer.corazzata.affondata()){
            computer.numero_Navi_Affondate++;
        }
        if(computer.portaerei.affondata()){
            computer.numero_Navi_Affondate++;
        }
        if(computer.numero_Navi_Affondate>0){
            return true;
        }
        return false;

    }else{
        giocatore.numero_Navi_Affondate=0;
        if(giocatore.assalto.affondata()){
            giocatore.numero_Navi_Affondate++;
        }
        if(giocatore.crociere.affondata()){
            giocatore.numero_Navi_Affondate++;
        }
        if(giocatore.corazzata.affondata()){
            giocatore.numero_Navi_Affondate++;
        }
        if(giocatore.portaerei.affondata()){
            giocatore.numero_Navi_Affondate++;
        }
        if(giocatore.numero_Navi_Affondate>0){
            return true;
        }
        return false;
    }

}

bool ModelloGioco::CheckScelta(unsigned short X, unsigned short Y)
{
       if(grigliaComputer[X*10+Y]==none){
           return true;
       }
       return false;
}

void ModelloGioco::riempiGriglie(ModelloPosizione *p)
{
    for(int i=0;i<100;i++){
        grigliaGiocatore[i]=p->grigliaGiocatore[i];
        grigliaComputer[i]=p->grigliaComputer[i];
    }
    giocatore=p->giocatore;
    computer=p->computer;
}

Player ModelloGioco::GetPlayer(unsigned short x, unsigned short y)
{
    return grigliaGiocatore[x*10+y];
}

int ModelloGioco::numNaviAffondateG()
{
    return giocatore.numero_Navi_Affondate;
}

int ModelloGioco::numNaviAffondateC()
{
    return computer.numero_Navi_Affondate;
}













