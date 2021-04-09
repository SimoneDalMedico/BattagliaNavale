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
    if(!giocatore.assalto.NaveAssalto::check_posizione(X,Y)) throw new MoveException(X,Y);
        if(giocatore.assalto.NaveAssalto::counter()<2){
            grigliaGiocatore[X*10+Y]=playerG;
            giocatore.assalto.NaveAssalto::assegna(X,Y);

        }
        if(giocatore.assalto.NaveAssalto::counter()==2) {
            giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
        }

}else{
if(giocatore.numeroNaviPosizionate==1){
    if(!giocatore.crociere.NaveCrociere::check_posizione(X,Y)) throw new MoveException(X,Y);
        if(giocatore.crociere.NaveCrociere::counter()<3){
             grigliaGiocatore[X*10+Y]=playerG;
            giocatore.crociere.NaveCrociere::assegna(X,Y);

        }
            if(giocatore.crociere.NaveCrociere::counter()==3){
                giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
            }
}else{
if(giocatore.numeroNaviPosizionate==2){
    if(!giocatore.corazzata.NaveCorazzata::check_posizione(X,Y)) throw new MoveException(X,Y);
    if(giocatore.corazzata.NaveCorazzata::counter()<4){
        grigliaGiocatore[X*10+Y]=playerG;
        giocatore.corazzata.NaveCorazzata::assegna(X,Y);

        }
        if(giocatore.corazzata.NaveCorazzata::counter()==4) giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
}else{
if(giocatore.numeroNaviPosizionate==3){
    if(!giocatore.portaerei.NavePortaerei::check_posizione(X,Y)) throw new MoveException(X,Y);
    if(giocatore.portaerei.NavePortaerei::counter()<5 ){
        grigliaGiocatore[X*10+Y]=playerG;
        giocatore.portaerei.NavePortaerei::assegna(X,Y);

    }
    if(giocatore.portaerei.NavePortaerei::counter()==5) giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
}
            }
        }
    }
turn=!turn;
}


void ModelloPosizione::moveC()
{
    if(computer.numeroNaviPosizionate==0){
        if(computer.assalto.counter()==0){
            unsigned short X;
            unsigned short Y;
            do{
            X=rand() % 10;

            Y=rand() % 10;
            }while(grigliaComputer[X*10+Y]!=none);
                if(computer.assalto.check_posizione(X,Y)){
                    grigliaComputer[X*10+Y]=playerC;
                    computer.assalto.assegna(X,Y);
                }

        }else{
            if(computer.assalto.counter()>0 && computer.assalto.counter()<2){
                computer.assalto.Posizionamentocomputer();
                grigliaComputer[computer.assalto.PosizionaGrigliaC()]=playerC;
            }


        if(computer.assalto.counter()==2) computer.numeroNaviPosizionate++;
    }
        }else{
        if(computer.numeroNaviPosizionate==1){
            if(computer.crociere.counter()==0){
                unsigned short X;
                unsigned short Y;
                do{
                X=rand() % 10;
                Y=rand() % 10;
                }while(grigliaComputer[X*10+Y]!=none);

                    if(computer.crociere.check_posizione(X,Y)){
                        grigliaComputer[X*10+Y]=playerC;
                        computer.crociere.assegna(X,Y);
                    }

            }else{
                if(computer.crociere.counter()>0 && computer.crociere.counter()<3){
                    computer.crociere.Posizionamentocomputer();
                    grigliaComputer[computer.crociere.PosizionaGrigliaC()]=playerC;
                }
                if(computer.crociere.counter()==3) computer.numeroNaviPosizionate++;
            }
        }else{
            if(computer.numeroNaviPosizionate==2){
                if(computer.corazzata.counter()==0){
                    unsigned short X;
                    unsigned short Y;
                    do{
                    X=rand() % 10;
                    Y=rand() % 10;
                    }while(grigliaComputer[X*10+Y]!=none);

                        if(computer.corazzata.check_posizione(X,Y)){
                            grigliaComputer[X*10+Y]=playerC;
                            computer.corazzata.assegna(X,Y);
                        }

                }else{
                    if(computer.corazzata.counter()>0 && computer.corazzata.counter()<4){
                        computer.corazzata.Posizionamentocomputer();
                        grigliaComputer[computer.corazzata.PosizionaGrigliaC()]=playerC;
                    }
                    if(computer.corazzata.counter()==4) computer.numeroNaviPosizionate++;
                }
            }else{
                if(computer.numeroNaviPosizionate==3){
                    if(computer.portaerei.counter()==0){
                        unsigned short X;
                        unsigned short Y;
                        do{
                        X=rand() % 10;
                        Y=rand() % 10;
                        }while(!checkSpazioNave(X,Y));
                        std::cout<<"X: "<<X<<std::endl;
                        std::cout<<"Y: "<<Y<<std::endl;

                            if(computer.portaerei.check_posizione(X,Y)){
                                grigliaComputer[X*10+Y]=playerC;
                                computer.portaerei.assegna(X,Y);
                            }
                    }else{
                        if(computer.portaerei.counter()>0 && computer.portaerei.counter()<5){
                            computer.portaerei.Posizionamentocomputer();
                            grigliaComputer[computer.portaerei.PosizionaGrigliaC()]=playerC;
                        }
                       if(computer.portaerei.counter()==5) computer.numeroNaviPosizionate++;
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

    giocatore.assalto.reset();
    giocatore.crociere.reset();
    giocatore.corazzata.reset();
    giocatore.portaerei.reset();

    computer.assalto.reset();
    computer.crociere.reset();
    computer.corazzata.reset();
    computer.portaerei.reset();
}

bool ModelloPosizione::CeckFinePosizionamento()
{
    if(giocatore.assalto.counter()==2 && giocatore.crociere.counter()==3 && giocatore.corazzata.counter()==4 && giocatore.portaerei.counter()==5){
        return true;
    }
    return false;
}

bool ModelloPosizione::checkPosizione(unsigned short x, unsigned short y)
{
    if(turn==giocatore.Turno){
        if(giocatore.numeroNaviPosizionate==0){
            return giocatore.assalto.check_posizione(x,y);
        }
        if(giocatore.numeroNaviPosizionate==1){
            return giocatore.crociere.check_posizione(x,y);
        }
        if(giocatore.numeroNaviPosizionate==2){
            return giocatore.corazzata.check_posizione(x,y);
        }
        if(giocatore.numeroNaviPosizionate==3){
            return giocatore.portaerei.check_posizione(x,y);
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

