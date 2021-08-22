#include "nave.h"

std::map<unsigned short, unsigned short> Nave::SceltePosizionamentoComputer;

void Nave::reset()
{

    std::list<cella>::iterator it;
    caselleNave.clear();
    SceltePosizionamentoComputer.clear();
    for(unsigned short i=0;i<100;i++){
        std::map<unsigned short, unsigned short>::value_type v(i,i);
        SceltePosizionamentoComputer.insert(v);
    }

}

int Nave::counter()
{
    int count=static_cast<int>(caselleNave.size());
    return count;
}

bool Nave::check_posizione(unsigned short x, unsigned short y)
{
    if(caselleNave.empty()){
        return true;
    }else{
        cella it=caselleNave.front();
        cella it2=caselleNave.back();
        if(it==it2){
            //una sola casella
            if((x==(it2.ShowX())-1 && y==it2.ShowY()) || (x==(it2.ShowX())+1 && y==it2.ShowY()) || (x==it2.ShowX() && y==(it2.ShowY())-1) || (x==it2.ShowX() && y==(it2.ShowY())+1)){
                return true;
            }
        }else{
            //piu caselle

            //caso orizzontale
            if(it.ShowX()==it2.ShowX() && x==it2.ShowX() && (y==(it2.ShowY())+1 || y==(it2.ShowY())-1)){
                return true;
            }
            //caso verticale
            if(it.ShowY()==it2.ShowY() && y==it2.ShowY() && (x==(it2.ShowX())+1 || x==(it2.ShowX())-1)){
                return true;
            }
        }
    }
    return false;
}

void Nave::Posizionamentocomputer()
{

    cella it=caselleNave.front();
    cella it2=caselleNave.back();
    if(it==it2 && counter()==1){
        //inizio caso inserimneto seconda casella
        if(it.ShowX()==0 && it.ShowY()==9 && (SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)] || SceltePosizionamentoComputer[(it.ShowX()+1)*10+it.ShowY()])){
            unsigned short x0=(it.ShowX());
            unsigned short x1=(it.ShowX())+1;
            unsigned short y0=(it.ShowY());
            unsigned short y1=(it.ShowY())-1;
            unsigned short x[2]={x0,x1};
            unsigned short randomX=rand() % 2;
            if(x[randomX]==x0 && SceltePosizionamentoComputer[x0*10+y1]){
                cella posizione(x0,y1);
                caselleNave.push_front(posizione);
                SceltePosizionamentoComputer.erase(x0+10+y1);
            }else{
                if(SceltePosizionamentoComputer[x1*10+y0]){
                    cella posizione(x1,y0);
                    caselleNave.push_back(posizione);
                    SceltePosizionamentoComputer.erase(x1*10+y1);
                }
            }
        }else{
            if(it.ShowX()==9 && it.ShowY()==0 && (SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()+1)] || SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()])){
                unsigned short x0=(it.ShowX());
                unsigned short x1=(it.ShowX())-1;
                unsigned short y0=(it.ShowY());
                unsigned short y1=(it.ShowY())+1;
                unsigned short x[2]={x0,x1};
                unsigned short randomX=rand() % 2;
                if(x[randomX]==x0 && SceltePosizionamentoComputer[x0*10+y1]){
                    cella posizione(x0,y1);
                    caselleNave.push_back(posizione);
                    SceltePosizionamentoComputer.erase(x0*10+y1);
                }else{
                    if(SceltePosizionamentoComputer[x1*10+y0]){
                        cella posizione(x1,y0);
                        caselleNave.push_front(posizione);
                        SceltePosizionamentoComputer.erase(x1*10+y0);
                    }
                }
            }else{
                if(it.ShowX()==0 && it.ShowY()<9 && it.ShowY()>0 && (it.ShowX()*10+(it.ShowY()-1) || SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()+1)] || SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()] || SceltePosizionamentoComputer[(it.ShowX()+1)*10+it.ShowY()])){
                    unsigned short x0=(it.ShowX());
                    unsigned short x1=(it.ShowX())+1;
                    unsigned short y0=(it.ShowY())-1;
                    unsigned short y1=(it.ShowY())+1;
                    unsigned short x[2]={x0,x1};
                    unsigned short randomX=rand() % 2;
                    if(x[randomX]==x0 && (SceltePosizionamentoComputer[x0*10+y0] || SceltePosizionamentoComputer[x0*10+y1])){
                        unsigned short y[2]={y0,y1};
                        unsigned short randomY=rand() % 2;
                        while(!SceltePosizionamentoComputer[x0*10+y[randomY]]){ //rischio loop infinito (poco probabile)
                            randomY=rand() % 2;
                        }

                        cella posizione(x0,y[randomY]);
                        if(y[randomY]<it.ShowY()){
                            caselleNave.push_front(posizione);
                        }else{
                            caselleNave.push_back(posizione);
                        }
                        SceltePosizionamentoComputer.erase(x0*10+y[randomY]);
                    }else{
                        if(SceltePosizionamentoComputer[x1*10+it.ShowY()]){
                            cella posizione(x1,it.ShowY());
                            caselleNave.push_back(posizione);
                            SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                        }
                    }
                }else{
                    if(it.ShowX()<9 && it.ShowY()==0 && it.ShowX()>0 && (SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()] || SceltePosizionamentoComputer[(it.ShowX()+1)*10+it.ShowY()] || SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()+1)])){
                        unsigned short y0=(it.ShowY());
                        unsigned short y1=(it.ShowY())+1;
                        unsigned short x0=(it.ShowX())-1;
                        unsigned short x1=(it.ShowX())+1;
                        unsigned short y[2]={y0,y1};
                        unsigned short randomY=rand() % 2;
                        if(y[randomY]==y0 || (SceltePosizionamentoComputer[x0*10+y0] || SceltePosizionamentoComputer[x0*10+y1])){

                            unsigned short x[2]={x0,x1};
                            unsigned short randomX=rand() % 2;
                            while(!SceltePosizionamentoComputer[x[randomX]*10+y0]){
                                randomX=rand() % 2;
                            }
                            cella posizione(x[randomX],y0);
                            if(x[randomX]<it.ShowX()){
                                caselleNave.push_front(posizione);
                            }else{
                                caselleNave.push_back(posizione);
                            }
                            SceltePosizionamentoComputer.erase(x[randomX]*10+y0);
                        }else{
                            if(SceltePosizionamentoComputer[it.ShowX()*10+y1]){
                                cella posizione(it.ShowX(),y1);
                                caselleNave.push_back(posizione);
                                SceltePosizionamentoComputer.erase(it.ShowX()*10+y1);
                            }
                        }
                    }else{
                        if(it.ShowX()==0 && it.ShowY()==0 && (SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()+1)] || SceltePosizionamentoComputer[(it.ShowX()+1)*10+it.ShowY()])){
                            unsigned short x0=(it.ShowX());
                            unsigned short x1=(it.ShowX())+1;
                            unsigned short y1=(it.ShowY())+1;
                            unsigned short x[2]={x0,x1};
                            unsigned short randomX=rand() % 2;
                            if(x[randomX]==x0 && SceltePosizionamentoComputer[x0*10+y1]){
                                cella posizione(x0,y1);
                                caselleNave.push_back(posizione);
                                SceltePosizionamentoComputer.erase(x0*10+y1);
                            }else{
                                if(SceltePosizionamentoComputer[x1*10+it.ShowY()]){
                                    cella posizione(x1,it.ShowY());
                                    caselleNave.push_back(posizione);
                                    SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                                }
                            }
                        }else{
                            if(it.ShowX()==9 && it.ShowY()==9 && (SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)] || SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()])){
                                unsigned short x0=(it.ShowX());
                                unsigned short x1=(it.ShowX())-1;
                                unsigned short y1=(it.ShowY())-1;
                                unsigned short x[2]={x0,x1};
                                unsigned short randomX=rand() % 2;
                                if(x[randomX]==x0 && SceltePosizionamentoComputer[x0*10+y1]){
                                    cella posizione(x0,y1);
                                    caselleNave.push_front(posizione);
                                    SceltePosizionamentoComputer.erase(x0*10+y1);
                                }else{
                                    if(SceltePosizionamentoComputer[x1*10+it.ShowY()]){
                                        cella posizione(x1,it.ShowY());
                                        caselleNave.push_front(posizione);
                                        SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                                    }
                                }
                            } else{
                                if(it.ShowX()==9 && it.ShowY()<9 && it.ShowY()>0 && (SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)] || SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)] || SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()])){
                                    unsigned short x0=it.ShowX();
                                    unsigned short x1=it.ShowX()-1;
                                    unsigned short x[2]={x0,x1};
                                    unsigned short y1=it.ShowY()-1;
                                    unsigned short y2=it.ShowY()+1;
                                    unsigned short randomX=rand()%2;
                                    if(x[randomX]==x0 && (SceltePosizionamentoComputer[x0*10+y1] || SceltePosizionamentoComputer[x0*10+y2])){
                                        unsigned short y[2]={y1,y2};
                                        unsigned short randomY=rand()%2;
                                        while(!SceltePosizionamentoComputer[x0*10+y[randomY]]){
                                            randomY=rand() % 2;
                                        }
                                        cella posizione(x0,y[randomY]);
                                        if(y[randomY]<it.ShowY()){
                                            caselleNave.push_front(posizione);
                                        }else{
                                            caselleNave.push_back(posizione);
                                        }
                                        SceltePosizionamentoComputer.erase(x0*10+y[randomY]);
                                    }else{
                                        if(SceltePosizionamentoComputer[x1*10+it.ShowY()]){
                                            cella posizione(x1,it.ShowY());
                                            caselleNave.push_front(posizione);
                                            SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                                        }
                                    }
                                }else{
                                    if(it.ShowX()<9 && it.ShowX()>0 && it.ShowY()==9 && (SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()] || SceltePosizionamentoComputer[(it.ShowX()+1)*10+it.ShowY()] || SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)])){
                                        unsigned short y0=it.ShowY();
                                        unsigned short y1=it.ShowY()-1;
                                        unsigned short x1=it.ShowX()-1;
                                        unsigned short x2=it.ShowX()+1;
                                        unsigned short y[2]={y0,y1};
                                        unsigned short randomY=rand()%2;
                                        if(y[randomY]==y0 && (SceltePosizionamentoComputer[x1*10+y0] || SceltePosizionamentoComputer[x2*10+y0])){
                                            unsigned short x[2]={x1,x2};
                                            unsigned short randomX=rand()%2;
                                            cella posizione(x[randomX],y0);
                                            if(x[randomX]<it.ShowX()){
                                                caselleNave.push_front(posizione);
                                            }else{
                                                caselleNave.push_back(posizione);
                                            }
                                            SceltePosizionamentoComputer.erase(x[randomX]*10+y0);
                                        }else{
                                            if(SceltePosizionamentoComputer[it.ShowX()*10+y1]){
                                                cella posizione(it.ShowX(),y1);
                                                caselleNave.push_front(posizione);
                                                SceltePosizionamentoComputer.erase(it.ShowX()*10+y1);
                                            }
                                        }
                                    }else{
                                        if(SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()] || SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)] || SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()+1)] || SceltePosizionamentoComputer[(it.ShowX()+1)*10+it.ShowY()]){
                                            unsigned short x0=(it.ShowX())-1;
                                            unsigned short x2=(it.ShowX())+1;
                                            unsigned short y0=(it.ShowY())-1;
                                            unsigned short y2=(it.ShowY())+1;
                                            unsigned short x[3]={x0,it.ShowX(),x2};
                                            unsigned short y[3]={y0,it.ShowY(),y2};
                                            unsigned short randomX=rand() % 3;
                                            unsigned short randomY=rand() % 3;
                                            while(!((x[randomX]==x0 && y[randomY]==y[1]) || (x[randomX]==x[1] && y[randomY]==y0) || (x[randomX]==x[1] && y[randomY]==y2) || (x[randomX]==x2 && y[randomY]==y[1]))){
                                                randomX=rand() % 3;
                                                randomY=rand() % 3;
                                            }
                                            cella posizione(x[randomX],y[randomY]);
                                            if(x[randomX]<it.ShowX() || y[randomY]<it.ShowY()){
                                                caselleNave.push_front(posizione);
                                            }else{
                                                caselleNave.push_back(posizione);
                                            }
                                            SceltePosizionamentoComputer.erase(x[randomX]*10+y[randomY]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else{
        if(counter()>1){ //gia posizionate almeno due caselle
            if(it.ShowX()==it2.ShowX()){
                //  caso orizzonale
                if((it.ShowX()==0 && it.ShowY()==0) && SceltePosizionamentoComputer[it2.ShowX()*10+(it2.ShowY()+1)]){
                    unsigned short y1=it2.ShowY()+1;
                    cella posizione(it2.ShowX(),y1);
                    caselleNave.push_back(posizione);
                    SceltePosizionamentoComputer.erase(it2.ShowX()*10+y1);
                }else{
                    if((it2.ShowX()==0 && it2.ShowY()==9) && SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)]){
                        unsigned short y1=it.ShowY()-1;
                        cella posizione(it.ShowX(),y1);
                        caselleNave.push_front(posizione);
                        SceltePosizionamentoComputer.erase(it.ShowX()*10+y1);
                    }else{
                        if((it.ShowX()==9 && it.ShowY()==0) && SceltePosizionamentoComputer[it2.ShowX()*10+(it.ShowY()+1)]){
                            unsigned short y1=it2.ShowY()+1;
                            cella posizione(it2.ShowX(),y1);
                            caselleNave.push_back(posizione);
                            SceltePosizionamentoComputer.erase(it2.ShowX()*10+y1);
                        }else{
                            if((it2.ShowX()==9 && it2.ShowY()==9) && SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)]){
                                unsigned short y1=it.ShowY()-1;
                                cella posizione(it.ShowX(),y1);
                                caselleNave.push_front(posizione);
                                SceltePosizionamentoComputer.erase(it.ShowX()*10+y1);
                            }else{
                                if((it.ShowX()>0 && it.ShowX()<9 && it.ShowY()==0) && SceltePosizionamentoComputer[it2.ShowX()*10+(it2.ShowY()+1)]){
                                    unsigned short y1=it2.ShowY()+1;
                                    cella posizione(it2.ShowX(),y1);
                                    caselleNave.push_back(posizione);
                                    SceltePosizionamentoComputer.erase(it2.ShowX()*10+y1);
                                }else{
                                    if((it2.ShowX()>0 && it2.ShowX()<9 && it2.ShowY()==9) && SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)]){
                                        unsigned short y1=it.ShowY()-1;
                                        cella posizione(it.ShowX(),y1);
                                        caselleNave.push_front(posizione);
                                        SceltePosizionamentoComputer.erase(it.ShowX()*10+y1);
                                    }else{
                                        if(SceltePosizionamentoComputer[it.ShowX()*10+(it.ShowY()-1)] || SceltePosizionamentoComputer[it.ShowX()*10+(it2.ShowY()+1)]){
                                            unsigned short y1=it.ShowY()-1;
                                            unsigned short y2=it2.ShowY()+1;
                                            unsigned short y[2]={y1,y2};
                                            unsigned short random=rand() % 2;
                                            while(!SceltePosizionamentoComputer[it.ShowX()*10+y[random]]){
                                                random=rand() % 2;
                                            }
                                            cella posizione(it.ShowX(),y[random]);
                                            if(y[random]<it.ShowY()){
                                                caselleNave.push_front(posizione);
                                            }else{
                                                caselleNave.push_back(posizione);
                                            }
                                            SceltePosizionamentoComputer.erase(it.ShowX()*10+y[random]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }else{ //y1==y2
                if(it.ShowY()==it2.ShowY()){
                    //casi verticali
                    if((it.ShowX()==0 && it.ShowY()==0) && SceltePosizionamentoComputer[(it2.ShowX()+1)*10+it.ShowY()]){
                        unsigned short x1=it2.ShowX()+1;
                        cella posizione(x1,it.ShowY());
                        caselleNave.push_back(posizione);
                        SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                    }else{
                        if((it.ShowX()==0 && it.ShowY()==9) && SceltePosizionamentoComputer[(it2.ShowX()+1)*10+it.ShowY()]){
                            unsigned short x1=it2.ShowX()+1;
                            cella posizione(x1,it.ShowY());
                            caselleNave.push_back(posizione);
                            SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                        }else{
                            if((it2.ShowX()==9 && it2.ShowY()==0) && SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()]){
                                unsigned short x1=it.ShowX()-1;
                                cella posizione(x1,it.ShowY());
                                caselleNave.push_front(posizione);
                                SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                            }else{
                                if((it2.ShowX()==9 && it2.ShowY()==9) && (SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()])){
                                    unsigned short x1=it.ShowX()-1;
                                    cella posizione(x1,it.ShowY());
                                    caselleNave.push_front(posizione);
                                    SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                                }else{
                                    if((it.ShowX()==0 && it.ShowY()>0 && it.ShowY()<9) && SceltePosizionamentoComputer[(it2.ShowX()+1)*10+it.ShowY()]){
                                        unsigned short x1=it2.ShowX()+1;
                                        cella posizione(x1,it.ShowY());
                                        caselleNave.push_back(posizione);
                                        SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                                    }else{
                                        if((it.ShowX()==9 && it.ShowY()>0 && it.ShowY()<9) && SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()]){
                                            unsigned short x1=it.ShowX()-1;
                                            cella posizione(x1,it.ShowY());
                                            caselleNave.push_front(posizione);
                                            SceltePosizionamentoComputer.erase(x1*10+it.ShowY());
                                        }else{
                                            if(SceltePosizionamentoComputer[(it.ShowX()-1)*10+it.ShowY()] || SceltePosizionamentoComputer[(it2.ShowX()+1)*10+it.ShowY()]){
                                                unsigned short x1=(it.ShowX())-1;
                                                unsigned short x2=(it2.ShowX())+1;
                                                unsigned short x[2]={x1,x2};
                                                unsigned short random=rand() % 2;
                                                while(!SceltePosizionamentoComputer[x[random]*10+it.ShowY()]){
                                                    random=rand() % 2;
                                                }
                                                cella posizione(x[random],it.ShowY());
                                                if(x[random]<it.ShowX()){
                                                    caselleNave.push_front(posizione);
                                                }else{
                                                    caselleNave.push_back(posizione);
                                                }
                                                SceltePosizionamentoComputer.erase(x[random]*10+it.ShowY());
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
unsigned short Nave::PosizionaGrigliaCInizio()
{
    cella it=caselleNave.front();
    return (((it.ShowX())*10)+it.ShowY());
}

unsigned short Nave::PosizionaGrigliaCFine()
{

    cella it=caselleNave.back();
    return (((it.ShowX())*10)+it.ShowY());
}

Nave::Nave()
{
    for(unsigned short i=0;i<100;i++){
        std::map<unsigned short, unsigned short>::value_type v(i,i);
        SceltePosizionamentoComputer.insert(v);
    }
}

Nave::Nave(unsigned short X, unsigned short Y)
{
    cella posizione(X,Y);
    caselleNave.push_back(posizione);
}

bool Nave::colpita(unsigned short X, unsigned short Y)
{
    for(std::list<cella>::iterator it=caselleNave.begin();it!=caselleNave.end();it++){
        if(it->ShowX()==X && it->ShowY()==Y){
            caselleNave.erase(it);
            return true;
        }
    }
    return false;
}

bool Nave::affondata()
{
    if(caselleNave.empty()){
        return true;
    }
    return  false;
}
