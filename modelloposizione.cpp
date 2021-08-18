#include "modelloposizione.h"

ModelloPosizione::ModelloPosizione()
{
    reset();
}

Player ModelloPosizione::operator()(unsigned short row, unsigned short col) const
{
    if(row>10 && col>10){
        return none;
    }
    if(turn==giocatore.Turno){
        return grigliaComputer[row*10+col];
    }else{
        return grigliaGiocatore[row*10+col];
    }
}

void ModelloPosizione::move(unsigned short X, unsigned short Y)
{
    if(grigliaGiocatore[X*10+Y]) throw  new MoveException(X,Y);

if(giocatore.numeroNaviPosizionate==0){
    //static_cast<NaveAssalto*>(giocatore.navi[0]->get())->check_posizione(X,Y)
    if(!static_cast<NaveAssalto*>(giocatore.navi[0].get())->check_posizione(X,Y)) throw new MoveException(X,Y);
    //!giocatore.assalto.NaveAssalto::check_posizione(X,Y)0
        if(static_cast<NaveAssalto*>(giocatore.navi[0].get())->counter()<2){
            grigliaGiocatore[X*10+Y]=playerG;
            static_cast<NaveAssalto*>(giocatore.navi[0].get())->assegna(X,Y);

            std::cout<<"mostrare x e y del contenitore navi[0]: "<<(static_cast<NaveAssalto*>(giocatore.navi[0].get()))->ShowX()<<" "<<static_cast<NaveAssalto*>(giocatore.navi[0].get())->ShowY()<<" "<<static_cast<NaveAssalto*>(giocatore.navi[0].get())->counter()<<std::endl;

        }
        if(static_cast<NaveAssalto*>(giocatore.navi[0].get())->counter()==2) {
            giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
        }

}else{
if(giocatore.numeroNaviPosizionate==1){
    if(!static_cast<NaveCrociere*>(giocatore.navi[1].get())->check_posizione(X,Y)) throw new MoveException(X,Y);
        if(static_cast<NaveCrociere*>(giocatore.navi[1].get())->counter()<3){
             grigliaGiocatore[X*10+Y]=playerG;
            static_cast<NaveCrociere*>(giocatore.navi[1].get())->assegna(X,Y);

        }
            if(static_cast<NaveCrociere*>(giocatore.navi[1].get())->counter()==3){
                giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
            }
}else{
if(giocatore.numeroNaviPosizionate==2){
    if(!static_cast<NaveCorazzata*>(giocatore.navi[2].get())->check_posizione(X,Y)) throw new MoveException(X,Y);
    if(static_cast<NaveCorazzata*>(giocatore.navi[2].get())->counter()<4){
        grigliaGiocatore[X*10+Y]=playerG;
        static_cast<NaveCorazzata*>(giocatore.navi[2].get())->assegna(X,Y);

        }
        if(static_cast<NaveCorazzata*>(giocatore.navi[2].get())->counter()==4) {
            giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
        }
}else{
if(giocatore.numeroNaviPosizionate==3){
    if(!static_cast<NavePortaerei*>(giocatore.navi[3].get())->check_posizione(X,Y)) throw new MoveException(X,Y);
    if(static_cast<NavePortaerei*>(giocatore.navi[3].get())->counter()<5 ){
        grigliaGiocatore[X*10+Y]=playerG;
        static_cast<NavePortaerei*>(giocatore.navi[3].get())->assegna(X,Y);

    }
    if(static_cast<NavePortaerei*>(giocatore.navi[3].get())->counter()==5) giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
}
            }
        }
    }
turn=!turn;
}


void ModelloPosizione::moveC()
{
    if(computer.numeroNaviPosizionate==0){
        if(static_cast<NaveAssalto*>(computer.navi[0].get())->counter()==0){
            unsigned short X;
            unsigned short Y;
            do{
            X=rand() % 10;

            Y=rand() % 10;
            }while(grigliaComputer[X*10+Y]!=none);
                if(static_cast<NaveAssalto*>(computer.navi[0].get())->check_posizione(X,Y)){
                    grigliaComputer[X*10+Y]=playerC;
                    static_cast<NaveAssalto*>(computer.navi[0].get())->assegna(X,Y);
                }

        }else{
            if(static_cast<NaveAssalto*>(computer.navi[0].get())->counter()>0 && static_cast<NaveAssalto*>(computer.navi[0].get())->counter()<2){
                std::cout<<"inizio posizionamento computer"<<std::endl;
                static_cast<NaveAssalto*>(computer.navi[0].get())->Posizionamentocomputer();
                if(grigliaComputer[static_cast<NaveAssalto*>(computer.navi[0].get())->PosizionaGrigliaCInizio()]==none){
                    grigliaComputer[static_cast<NaveAssalto*>(computer.navi[0].get())->PosizionaGrigliaCInizio()]=playerC;
                }else{
                    if(grigliaComputer[static_cast<NaveAssalto*>(computer.navi[0].get())->PosizionaGrigliaCFine()]==none){
                        grigliaComputer[static_cast<NaveAssalto*>(computer.navi[0].get())->PosizionaGrigliaCFine()]=playerC;
                    }
                }

            }


        if(static_cast<NaveAssalto*>(computer.navi[0].get())->counter()==2) {
            computer.numeroNaviPosizionate=computer.numeroNaviPosizionate+1;
        }
    }
        }else{
        if(computer.numeroNaviPosizionate==1){
            if(static_cast<NaveCrociere*>(computer.navi[1].get())->counter()==0){
                unsigned short X;
                unsigned short Y;
                do{
                X=rand() % 10;
                Y=rand() % 10;
                }while(grigliaComputer[X*10+Y]!=none);

                    if(static_cast<NaveCrociere*>(computer.navi[1].get())->check_posizione(X,Y)){
                        grigliaComputer[X*10+Y]=playerC;
                        static_cast<NaveCrociere*>(computer.navi[1].get())->assegna(X,Y);
                    }

            }else{
                if(static_cast<NaveCrociere*>(computer.navi[1].get())->counter()>0 && static_cast<NaveCrociere*>(computer.navi[1].get())->counter()<3){
                    static_cast<NaveCrociere*>(computer.navi[1].get())->Posizionamentocomputer();
//                    grigliaComputer[static_cast<NaveCrociere*>(computer.navi[1].get())->PosizionaGrigliaC()]=playerC;
                    std::cout<<"entra dentro if POsizionaGriglieINIzio"<<std::endl;
                    if(grigliaComputer[static_cast<NaveCrociere*>(computer.navi[1].get())->PosizionaGrigliaCInizio()]==none){
                        grigliaComputer[static_cast<NaveCrociere*>(computer.navi[1].get())->PosizionaGrigliaCInizio()]=playerC;
                    }else{
                        if(grigliaComputer[static_cast<NaveCrociere*>(computer.navi[1].get())->PosizionaGrigliaCFine()]==none){
                            std::cout<<"entra dentro if POsizionaGriglieFine"<<std::endl;
                            grigliaComputer[static_cast<NaveCrociere*>(computer.navi[1].get())->PosizionaGrigliaCFine()]=playerC;
                        }
                    }
                }
                if(static_cast<NaveCrociere*>(computer.navi[1].get())->counter()==3) {
                    computer.numeroNaviPosizionate=computer.numeroNaviPosizionate+1;
                }
            }
        }else{
            if(computer.numeroNaviPosizionate==2){
                if(static_cast<NaveCorazzata*>(computer.navi[2].get())->counter()==0){
                    unsigned short X;
                    unsigned short Y;
                    do{
                        std::cout<<"inzio ciclo while nave da 4"<<std::endl;
                    X=rand() % 10;
                    Y=rand() % 10;
                    std::cout<<"X: "<<X<<std::endl;
                    std::cout<<"Y: "<<Y<<std::endl;
                    }while(grigliaComputer[X*10+Y]!=none);
                        std::cout<<"fine ciclo while nave da 4"<<std::endl;
                        if(static_cast<NaveCorazzata*>(computer.navi[2].get())->check_posizione(X,Y)){
                            grigliaComputer[X*10+Y]=playerC;
                            static_cast<NaveCorazzata*>(computer.navi[2].get())->assegna(X,Y);
                        }

                }else{
                    if(static_cast<NaveCorazzata*>(computer.navi[2].get())->counter()>0 && static_cast<NaveCorazzata*>(computer.navi[2].get())->counter()<4){
                        static_cast<NaveCorazzata*>(computer.navi[2].get())->Posizionamentocomputer();
//                        grigliaComputer[static_cast<NaveCorazzata*>(computer.navi[2].get())->PosizionaGrigliaC()]=playerC;
                        if(grigliaComputer[static_cast<NaveCorazzata*>(computer.navi[2].get())->PosizionaGrigliaCInizio()]==none){
                            grigliaComputer[static_cast<NaveCorazzata*>(computer.navi[2].get())->PosizionaGrigliaCInizio()]=playerC;
                        }else{
                            if(grigliaComputer[static_cast<NaveCorazzata*>(computer.navi[2].get())->PosizionaGrigliaCFine()]==none){
                                grigliaComputer[static_cast<NaveCorazzata*>(computer.navi[2].get())->PosizionaGrigliaCFine()]=playerC;
                            }
                        }
                    }
                    if(static_cast<NaveCorazzata*>(computer.navi[2].get())->counter()==4) {
                        computer.numeroNaviPosizionate=computer.numeroNaviPosizionate+1;
                    }
                }
            }else{
                if(computer.numeroNaviPosizionate==3){
                    if(static_cast<NavePortaerei*>(computer.navi[3].get())->counter()==0){
                        unsigned short X;
                        unsigned short Y;
                        do{
                            std::cout<<"inzio ciclo while nave da 5"<<std::endl;
                        X=rand() % 10;
                        Y=rand() % 10;
                        std::cout<<"X: "<<X<<std::endl;
                        std::cout<<"Y: "<<Y<<std::endl;
                        }while(!checkSpazioNave(X,Y));
                        std::cout<<"fine ciclo while nave da 5"<<std::endl;

                            if(static_cast<NavePortaerei*>(computer.navi[3].get())->check_posizione(X,Y)){
                                grigliaComputer[X*10+Y]=playerC;
                                static_cast<NavePortaerei*>(computer.navi[3].get())->assegna(X,Y);
                            }
                    }else{
                        if(static_cast<NavePortaerei*>(computer.navi[3].get())->counter()>0 && static_cast<NavePortaerei*>(computer.navi[3].get())->counter()<5){
                            std::cout<<"inizio posizionamento computer nave da 5 caselle"<<std::endl;
                            static_cast<NavePortaerei*>(computer.navi[3].get())->Posizionamentocomputer();
                            std::cout<<"fineposizionamento nave da 5"<<std::endl;
//                            grigliaComputer[static_cast<NavePortaerei*>(computer.navi[3].get())->PosizionaGrigliaC()]=playerC;
                            if(grigliaComputer[static_cast<NavePortaerei*>(computer.navi[3].get())->PosizionaGrigliaCInizio()]==none){
                                grigliaComputer[static_cast<NavePortaerei*>(computer.navi[3].get())->PosizionaGrigliaCInizio()]=playerC;
                            }else{
                                if(grigliaComputer[static_cast<NavePortaerei*>(computer.navi[3].get())->PosizionaGrigliaCFine()]==none){
                                    grigliaComputer[static_cast<NavePortaerei*>(computer.navi[3].get())->PosizionaGrigliaCFine()]=playerC;
                                }
                            }
                        }
                       if(static_cast<NavePortaerei*>(computer.navi[3].get())->counter()==5) computer.numeroNaviPosizionate=computer.numeroNaviPosizionate+1;
                    }
                }
            }
        }
    }
turn=!turn;
}

void ModelloPosizione::reset()
{
    turn=0;

    for(int i=0; i<100;i++){
        grigliaGiocatore[i]=none;
        grigliaComputer[i]=none;
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

bool ModelloPosizione::CeckFinePosizionamento()
{
    if(static_cast<NaveAssalto*>(giocatore.navi[0].get())->counter()==2 && static_cast<NaveCrociere*>(giocatore.navi[1].get())->counter()==3 && static_cast<NaveCorazzata*>(giocatore.navi[2].get())->counter()==4 && static_cast<NavePortaerei*>(giocatore.navi[3].get())->counter()==5){
        return true;
    }
    return false;
}

bool ModelloPosizione::checkPosizione(unsigned short x, unsigned short y)
{
    if(turn==giocatore.Turno){
        if(giocatore.numeroNaviPosizionate==0){
            //output prova
            std::cout<<static_cast<NaveAssalto*>(giocatore.navi[0].get())->ShowX()<<" "<<static_cast<NaveAssalto*>(giocatore.navi[0].get())->ShowX()<<std::endl;
            return static_cast<NaveAssalto*>(giocatore.navi[0].get())->check_posizione(x,y);
        }
        if(giocatore.numeroNaviPosizionate==1){
            return static_cast<NaveCrociere*>(giocatore.navi[1].get())->check_posizione(x,y);
        }
        if(giocatore.numeroNaviPosizionate==2){
            return static_cast<NaveCorazzata*>(giocatore.navi[2].get())->check_posizione(x,y);
        }
        if(giocatore.numeroNaviPosizionate==3){
            return static_cast<NavePortaerei*>(giocatore.navi[3].get())->check_posizione(x,y);
        }
    }
    return false;
}

int ModelloPosizione::NaviPosizionateG()
{
     return giocatore.numeroNaviPosizionate;
}

int ModelloPosizione::NaviPosizionateC()
{
    return computer.numeroNaviPosizionate;
}



bool ModelloPosizione::checkSpazioNave(unsigned short X, unsigned short Y)
{

    if(grigliaComputer[X*10+Y]==none){
        unsigned short int caselle=0;
        bool check1=true;

        for(unsigned short int key=0;caselle<5 && check1;key=key+10){
            if(grigliaComputer[(X*10+Y)+key]==none && (X*10+Y)+key<100){
                caselle++;
            }else{
                check1=false;
            }
        }
        caselle=0;
        bool check2=true;
        for(unsigned short int key=0;caselle<5 && check2; key=key+10){
            if(grigliaComputer[(X*10+Y)-key]==none && (X*10+Y)-key>0){
                caselle++;
            }else{
                check2=false;
            }
        }
        caselle=0;
        bool check3=true;
        for(unsigned short int key=0;caselle<5 && check3; key++){
            if(grigliaComputer[(X*10+Y)-key]==none && (X*10+Y)-key>0){
                caselle++;
            }else{
                check3=false;
            }
        }
        caselle=0;
        bool check4=true;
        for(unsigned short int key=0;caselle<5 && check4; key++){
            if(grigliaComputer[(X*10+Y)+key]==none && (X*10+Y)+key<100){
                caselle++;
            }else{
                check4=false;
            }
        }

    if(check1==true && check2==true && check3==true && check4==true){
        return true;
    }else{
        return false;
    }
}
return false;
}

