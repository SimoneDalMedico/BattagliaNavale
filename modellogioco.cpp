#include "modellogioco.h"

ModelloGioco::ModelloGioco()
{
    reset();
}

ModelloGioco::ModelloGioco(ModelloPosizione* p): giocatore(p->giocatore), computer(p->computer)
{
    giocatore.numero_Navi_Affondate=0;
    computer.numero_Navi_Affondate=0;
    for(unsigned short int i=0;i<100;i++){
        grigliaComputer[i]=p->grigliaComputer[i];
        grigliaGiocatore[i]=p->grigliaGiocatore[i];
//        std::cout<<grigliaComputer[i]<<std::endl;
//        std::cout<<grigliaGiocatore[i]<<std::endl;
//        std::cout<<std::endl;
    }
    //giocatore=p->giocatore;
    //computer=p->computer;
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
        std::cout<<"Modello gioco::move"<<std::endl;
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

    static_cast<NaveAssalto*>(giocatore.navi[0].get())->reset();
    static_cast<NaveCrociere*>(giocatore.navi[1].get())->reset();
    static_cast<NaveCorazzata*>(giocatore.navi[2].get())->reset();
    static_cast<NavePortaerei*>(giocatore.navi[3].get())->reset();

    static_cast<NaveAssalto*>(computer.navi[0].get())->reset();
    static_cast<NaveCrociere*>(computer.navi[1].get())->reset();
    static_cast<NaveCorazzata*>(computer.navi[2].get())->reset();
    static_cast<NavePortaerei*>(computer.navi[3].get())->reset();
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
{   unsigned short counter=0;
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
      std::map<int,cella>::iterator it;
        if(turn==Giocatore::Turno){
            if(static_cast<NaveAssalto*>(giocatore.navi[0].get())->colpita(x,y)){
                return true;
            }
            if(static_cast<NaveCrociere*>(giocatore.navi[1].get())->colpita(x,y)){
                return true;
            }
            if(static_cast<NaveCorazzata*>(giocatore.navi[2].get())->colpita(x,y)){
                return true;
            }
            if(static_cast<NavePortaerei*>(giocatore.navi[3].get())->colpita(x,y)){
                return true;
            }
        }else{
            if(static_cast<NaveAssalto*>(computer.navi[0].get())->colpita(x,y)){
                return true;
            }
            if(static_cast<NaveCrociere*>(computer.navi[1].get())->colpita(x,y)){
                return true;
            }
            if(static_cast<NaveCorazzata*>(computer.navi[2].get())->colpita(x,y)){
                return true;
            }
            if(static_cast<NavePortaerei*>(computer.navi[3].get())->colpita(x,y)){
                return true;
            }
        }
        return false;
}

bool ModelloGioco::checkNaveAffondata()
{
    if(turn==computer.Turno){
        computer.numero_Navi_Affondate=0;
        if(static_cast<NaveAssalto*>(computer.navi[0].get())->affondata()){
            computer.numero_Navi_Affondate++;
        }
        if(static_cast<NaveCrociere*>(computer.navi[1].get())->affondata()){
            computer.numero_Navi_Affondate++;
        }
        if(static_cast<NaveCorazzata*>(computer.navi[2].get())->affondata()){
            computer.numero_Navi_Affondate++;
        }
        if(static_cast<NavePortaerei*>(computer.navi[3].get())->affondata()){
            computer.numero_Navi_Affondate++;
        }
        if(computer.numero_Navi_Affondate>0){
            return true;
        }
        return false;

    }else{
        giocatore.numero_Navi_Affondate=0;
        if(static_cast<NaveAssalto*>(giocatore.navi[0].get())->affondata()){
            giocatore.numero_Navi_Affondate++;
        }
        if(static_cast<NaveCrociere*>(giocatore.navi[1].get())->affondata()){
            giocatore.numero_Navi_Affondate++;
        }
        if(static_cast<NaveCorazzata*>(giocatore.navi[2].get())->affondata()){
            giocatore.numero_Navi_Affondate++;
        }
        if(static_cast<NavePortaerei*>(giocatore.navi[3].get())->affondata()){
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
    //da numeri random!
    giocatore=p->giocatore;
    computer=p->computer;


    contenitore<deep_ptr<cella>>::iterator it=giocatore.navi.begin();
    std::cout<<"test riempi griglie"<<std::endl;
    for(it=giocatore.navi.begin();it!=giocatore.navi.end(); ++it){
        std::cout<<it->get()->ShowX()<<" "<<it->get()->ShowY()<<std::endl;
    }

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













