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
    contenitore<deep_ptr<cella>>::iterator itG=giocatore.navi.begin();
if(giocatore.numeroNaviPosizionate==0){
    //static_cast<NaveAssalto*>(giocatore.navi[0]->get())->check_posizione(X,Y)
    if(!static_cast<NaveAssalto*>(itG->get())->check_posizione(X,Y)) throw new MoveException(X,Y);
    //!giocatore.assalto.NaveAssalto::check_posizione(X,Y)0
        if(static_cast<NaveAssalto*>(itG->get())->counter()<2){
            grigliaGiocatore[X*10+Y]=playerG;
            static_cast<NaveAssalto*>(itG->get())->assegna(X,Y);

        }
        if(static_cast<NaveAssalto*>(itG->get())->counter()==2) {
            giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
            ++itG;
        }

}else{
if(giocatore.numeroNaviPosizionate==1){
    if(!static_cast<NaveCrociere*>(itG->get())->check_posizione(X,Y)) throw new MoveException(X,Y);
        if(static_cast<NaveCrociere*>(itG->get())->counter()<3){
             grigliaGiocatore[X*10+Y]=playerG;
            static_cast<NaveCrociere*>(itG->get())->assegna(X,Y);

        }
            if(static_cast<NaveCrociere*>(itG->get())->counter()==3){
                giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
                ++itG;
            }
}else{
if(giocatore.numeroNaviPosizionate==2){
    if(!static_cast<NaveCorazzata*>(itG->get())->check_posizione(X,Y)) throw new MoveException(X,Y);
    if(static_cast<NaveCorazzata*>(itG->get())->counter()<4){
        grigliaGiocatore[X*10+Y]=playerG;
        static_cast<NaveCorazzata*>(itG->get())->assegna(X,Y);

        }
        if(static_cast<NaveCorazzata*>(itG->get())->counter()==4) {
            giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
            ++itG;
        }
}else{
if(giocatore.numeroNaviPosizionate==3){
    if(!static_cast<NavePortaerei*>(itG->get())->check_posizione(X,Y)) throw new MoveException(X,Y);
    if(static_cast<NavePortaerei*>(itG->get())->counter()<5 ){
        grigliaGiocatore[X*10+Y]=playerG;
        static_cast<NavePortaerei*>(itG->get())->assegna(X,Y);

    }
    if(static_cast<NavePortaerei*>(itG->get())->counter()==5) giocatore.numeroNaviPosizionate=(giocatore.numeroNaviPosizionate)+1;
}
            }
        }
    }
turn=!turn;
}


void ModelloPosizione::moveC()
{
    contenitore<deep_ptr<cella>>::iterator itC=computer.navi.begin();
    if(computer.numeroNaviPosizionate==0){
        if(static_cast<NaveAssalto*>(itC->get())->counter()==0){
            unsigned short X;
            unsigned short Y;
            do{
            X=rand() % 10;

            Y=rand() % 10;
            }while(grigliaComputer[X*10+Y]!=none);
                if(static_cast<NaveAssalto*>(itC->get())->check_posizione(X,Y)){
                    grigliaComputer[X*10+Y]=playerC;
                    static_cast<NaveAssalto*>(itC->get())->assegna(X,Y);
                }

        }else{
            if(static_cast<NaveAssalto*>(itC->get())->counter()>0 && static_cast<NaveAssalto*>(itC->get())->counter()<2){
                static_cast<NaveAssalto*>(itC->get())->Posizionamentocomputer();
                grigliaComputer[static_cast<NaveAssalto*>(itC->get())->PosizionaGrigliaC()]=playerC;
            }


        if(static_cast<NaveAssalto*>(itC->get())->counter()==2) {
            computer.numeroNaviPosizionate++;
            ++itC;
        }
    }
        }else{
        if(computer.numeroNaviPosizionate==1){
            if(static_cast<NaveCrociere*>(itC->get())->counter()==0){
                unsigned short X;
                unsigned short Y;
                do{
                X=rand() % 10;
                Y=rand() % 10;
                }while(grigliaComputer[X*10+Y]!=none);

                    if(static_cast<NaveCrociere*>(itC->get())->check_posizione(X,Y)){
                        grigliaComputer[X*10+Y]=playerC;
                        static_cast<NaveCrociere*>(itC->get())->assegna(X,Y);
                    }

            }else{
                if(static_cast<NaveCrociere*>(itC->get())->counter()>0 && static_cast<NaveCrociere*>(itC->get())->counter()<3){
                    static_cast<NaveCrociere*>(itC->get())->Posizionamentocomputer();
                    grigliaComputer[static_cast<NaveCrociere*>(itC->get())->PosizionaGrigliaC()]=playerC;
                }
                if(static_cast<NaveCrociere*>(itC->get())->counter()==3) {
                    computer.numeroNaviPosizionate++;
                    ++itC;
                }
            }
        }else{
            if(computer.numeroNaviPosizionate==2){
                if(static_cast<NaveCorazzata*>(itC->get())->counter()==0){
                    unsigned short X;
                    unsigned short Y;
                    do{
                    X=rand() % 10;
                    Y=rand() % 10;
                    }while(grigliaComputer[X*10+Y]!=none);

                        if(static_cast<NaveCorazzata*>(itC->get())->check_posizione(X,Y)){
                            grigliaComputer[X*10+Y]=playerC;
                            static_cast<NaveCorazzata*>(itC->get())->assegna(X,Y);
                        }

                }else{
                    if(static_cast<NaveCorazzata*>(itC->get())->counter()>0 && static_cast<NaveCorazzata*>(itC->get())->counter()<4){
                        static_cast<NaveCorazzata*>(itC->get())->Posizionamentocomputer();
                        grigliaComputer[static_cast<NaveCorazzata*>(itC->get())->PosizionaGrigliaC()]=playerC;
                    }
                    if(static_cast<NaveCorazzata*>(itC->get())->counter()==4) {
                        computer.numeroNaviPosizionate++;
                        ++itC;
                    }
                }
            }else{
                if(computer.numeroNaviPosizionate==3){
                    if(static_cast<NavePortaerei*>(itC->get())->counter()==0){
                        unsigned short X;
                        unsigned short Y;
                        do{
                        X=rand() % 10;
                        Y=rand() % 10;
                        }while(!checkSpazioNave(X,Y));
                        std::cout<<"X: "<<X<<std::endl;
                        std::cout<<"Y: "<<Y<<std::endl;

                            if(static_cast<NavePortaerei*>(itC->get())->check_posizione(X,Y)){
                                grigliaComputer[X*10+Y]=playerC;
                                static_cast<NavePortaerei*>(itC->get())->assegna(X,Y);
                            }
                    }else{
                        if(static_cast<NavePortaerei*>(itC->get())->counter()>0 && static_cast<NavePortaerei*>(itC->get())->counter()<5){
                            static_cast<NavePortaerei*>(itC->get())->Posizionamentocomputer();
                            grigliaComputer[static_cast<NavePortaerei*>(itC->get())->PosizionaGrigliaC()]=playerC;
                        }
                       if(static_cast<NavePortaerei*>(itC->get())->counter()==5) computer.numeroNaviPosizionate++;
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
    contenitore<deep_ptr<cella>>::iterator itG=giocatore.navi.begin();
    contenitore<deep_ptr<cella>>::iterator itC=computer.navi.begin();
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

    static_cast<NaveAssalto*>(itG->get())->reset();
    ++itG;
    static_cast<NaveCrociere*>(itG->get())->reset();
    ++itG;
    static_cast<NaveCorazzata*>(itG->get())->reset();
    ++itG;
    static_cast<NavePortaerei*>(itG->get())->reset();

    static_cast<NaveAssalto*>(itC->get())->reset();
    ++itC;
    static_cast<NaveCrociere*>(itC->get())->reset();
    ++itC;
    static_cast<NaveCorazzata*>(itC->get())->reset();
    ++itC;
    static_cast<NavePortaerei*>(itC->get())->reset();
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

