#include "nave.h"

void Nave::reset()
{
    std::list<cella>::iterator it;
    caselleNave.clear();
}

int Nave::counter()
{
    int count=static_cast<int>(caselleNave.size());
    return count;
}

bool Nave::check_posizione(unsigned short x, unsigned short y)
{
    std::cout<<"inizio check posizione"<<std::endl;
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
    std::cout<<"return FALSE checkposizione!"<<std::endl;
    return false;
}

void Nave::Posizionamentocomputer()
{

    cella it=caselleNave.front();
    cella it2=caselleNave.back();
//    it2--;
    if(it==it2 && counter()==1){
        std::cout<<"inizio caso inserimneto seconda casella"<<std::endl;
if(it.ShowX()==0 && it.ShowY()==9){
            unsigned short x0=(it.ShowX());
            unsigned short x1=(it.ShowX())+1;
            unsigned short y0=(it.ShowY());
            unsigned short y1=(it.ShowY())-1;
            unsigned short x[2]={x0,x1};
            unsigned short randomX=rand() % 2;
            if(x[randomX]==x0){
                cella posizione(x0,y1); //direzione <--
                caselleNave.push_front(posizione);
            }else{
                cella posizione(x1,y0); //direzione da alto a basso

                caselleNave.push_back(posizione);
            }
}else{
if(it.ShowX()==9 && it.ShowY()==0){
    unsigned short x0=(it.ShowX());
    unsigned short x1=(it.ShowX())-1;
    unsigned short y0=(it.ShowY());
    unsigned short y1=(it.ShowY())+1;
    unsigned short x[2]={x0,x1};
    unsigned short randomX=rand() % 2;
    if(x[randomX]==x0){
        cella posizione(x0,y1);
        caselleNave.push_back(posizione);
    }else{
        cella posizione(x1,y0);

        caselleNave.push_front(posizione);
    }
}else{
if(it.ShowX()==0 && it.ShowY()<9 && it.ShowY()>0){
            unsigned short x0=(it.ShowX());
            unsigned short x1=(it.ShowX())+1;

            unsigned short x[2]={x0,x1};
            unsigned short randomX=rand() % 2;
            if(x[randomX]==x0){
                unsigned short y0=(it.ShowY())-1;
                unsigned short y1=(it.ShowY())+1;
                unsigned short y[2]={y0,y1};
                unsigned short randomY=rand() % 2;
                cella posizione(x0,y[randomY]);
                if(y[randomY]<it.ShowY()){
                    //inserisco davanti alla lista
                    caselleNave.push_front(posizione);
                }else{
                    caselleNave.push_back(posizione);
                }

            }else{
                cella posizione(x1,it.ShowY());
                caselleNave.push_back(posizione);
            }


}else{
if(it.ShowX()<9 && it.ShowY()==0 && it.ShowX()>0){
    unsigned short y0=(it.ShowY());
    unsigned short y1=(it.ShowY())+1;
    unsigned short y[2]={y0,y1};
    unsigned short randomY=rand() % 2;
    if(y[randomY]==y0){
        unsigned short x0=(it.ShowX())-1;
        unsigned short x1=(it.ShowX())+1;
        unsigned short x[2]={x0,x1};
        unsigned short randomX=rand() % 2;
        cella posizione(x[randomX],y0);
        if(x[randomX]<it.ShowX()){
            caselleNave.push_front(posizione);
        }else{
            caselleNave.push_back(posizione);
        }

    }else{
        cella posizione(it.ShowX(),y1);

        caselleNave.push_back(posizione);
    }
}else{
if(it.ShowX()==0 && it.ShowY()==0){
    unsigned short x0=(it.ShowX());
    unsigned short x1=(it.ShowX())+1;
    unsigned short x[2]={x0,x1};
    unsigned short randomX=rand() % 2;
    if(x[randomX]==x0){
        unsigned short y1=(it.ShowY())+1;
        cella posizione(x0,y1);
        caselleNave.push_back(posizione);
    }else{
        cella posizione(x1,it.ShowY());
        caselleNave.push_back(posizione);
    }
}else{
   if(it.ShowX()==9 && it.ShowY()==9){
       unsigned short x0=(it.ShowX());
       unsigned short x1=(it.ShowX())-1;
       unsigned short x[2]={x0,x1};
       unsigned short randomX=rand() % 2;
       if(x[randomX]==x0){
           unsigned short y1=(it.ShowY())-1;
           cella posizione(x0,y1);
           caselleNave.push_front(posizione);
       }else{
           cella posizione(x1,it.ShowY());
           caselleNave.push_front(posizione);
       }
   } else{
       if(it.ShowX()==9 && it.ShowY()<9 && it.ShowY()>0){
           unsigned short x0=it.ShowX();
           unsigned short x1=it.ShowX()-1;
           unsigned short x[2]={x0,x1};
           unsigned short randomX=rand()%2;
           if(x[randomX]==x0){
               unsigned short y1=it.ShowY()-1;
               unsigned short y2=it.ShowY()+1;
               unsigned short y[2]={y1,y2};
               unsigned short randomY=rand()%2;
               cella posizione(x0,y[randomY]);
               if(y[randomY]<it.ShowY()){
                   caselleNave.push_front(posizione);
               }else{
                   caselleNave.push_back(posizione);
               }
           }else{
               cella posizione(x1,it.ShowY());
               caselleNave.push_front(posizione);
           }
       }else{
           if(it.ShowX()<9 && it.ShowX()>0 && it.ShowY()==9){
               unsigned short y0=it.ShowY();
               unsigned short y1=it.ShowY()-1;
               unsigned short y[2]={y0,y1};
               unsigned short randomY=rand()%2;
               if(y[randomY]==y0){
                   unsigned short x1=it.ShowX()-1;
                   unsigned short x2=it.ShowX()+1;
                   unsigned short x[2]={x1,x2};
                   unsigned short randomX=rand()%2;
                   cella posizione(x[randomX],y0);
                   if(x[randomX]<it.ShowX()){
                        caselleNave.push_front(posizione);
                   }else{
                        caselleNave.push_back(posizione);
                   }
               }else{
                   cella posizione(it.ShowX(),y1);

                   caselleNave.push_front(posizione);
               }
           }else{
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
            //x1==x2    caso orizzonale
            std::cout<<"inizio caso orizzzontale"<<std::endl;
            if(it.ShowX()==it2.ShowX()){
                if((it.ShowX()==0 && it.ShowY()==0) || (it2.ShowX()==0 && it2.ShowY()==0)){
                    unsigned short y1=it2.ShowY()+1;
                    cella posizione(it2.ShowX(),y1);
                    caselleNave.push_back(posizione);
                    //DA VERIFICARE: TEORICAMNETE SONO GAI MESSI IN ORDINE QUIDNI NON SERVE FARE CONTROLLO SE IT<>IT2!!!!!

//                    if(it.ShowY()<it2.ShowY()){
//                        unsigned short y1=it2.ShowY()+1;
//                        cella posizione(it2.ShowX(),y1);

//                        caselleNave.push_back(posizione);
//                    }else{
//                        unsigned short y1=it.ShowY()+1;
//                        cella posizione(it.ShowX(),y1);

//                        caselleNave.insert(a);
//                    }
                }else{
                    if((it.ShowX()==0 && it.ShowY()==9) || (it2.ShowX()==0 && it2.ShowY()==9)){
                        unsigned short y1=it.ShowY()-1;
                        cella posizione(it.ShowX(),y1);
                        caselleNave.push_front(posizione);
//                        if(it.ShowY()<it2.ShowY()){
//                            unsigned short y1=it.ShowY()-1;
//                            cella posizione(it.ShowX(),y1);

//                            caselleNave.insert(a);
//                        }else{
//                            unsigned short y1=it2.ShowY()-1;
//                            cella posizione(it.ShowX(),y1);

//                            caselleNave.insert(a);
//                        }
                    }else{
                        if((it.ShowX()==9 && it.ShowY()==0) || (it2.ShowX()==9 && it2.ShowY()==0)){
                            unsigned short y1=it2.ShowY()+1;
                            cella posizione(it2.ShowX(),y1);
                            caselleNave.push_back(posizione);
//                            if(it.ShowY()<it2.ShowY()){
//                                unsigned short y1=it2.ShowY()+1;
//                                cella posizione(it2.ShowX(),y1);

//                                caselleNave.insert(a);
//                            }else{
//                                unsigned short y1=it.ShowY()+1;
//                                cella posizione(it.ShowX(),y1);

//                                caselleNave.insert(a);
//                            }
                        }else{
                            if((it.ShowX()==9 && it.ShowY()==9) || (it2.ShowX()==9 && it2.ShowY()==9)){
                                unsigned short y1=it.ShowY()-1;
                                cella posizione(it.ShowX(),y1);
                                caselleNave.push_front(posizione);
//                                if(it.ShowY()<it2.ShowY()){
//                                    unsigned short y1=it.ShowY()-1;
//                                    cella posizione(it.ShowX(),y1);

//                                    caselleNave.insert(a);
//                                }else{
//                                    unsigned short y1=it2.ShowY()-1;
//                                    cella posizione(it2.ShowX(),y1);

//                                    caselleNave.insert(a);
//                                }
                            }else{
                                if((it.ShowX()>0 && it.ShowX()<9 && it.ShowY()==0)||(it2.ShowX()>0 && it2.ShowX()<9 && it2.ShowY()==0)){ //da verificare se è giusto inserire y1 (forse è x1)
                                    unsigned short y1=it2.ShowY()+1;
                                    cella posizione(it2.ShowX(),y1);
                                    caselleNave.push_back(posizione);

//                                    if(it.ShowY()<it2.ShowY()){
//                                        unsigned short y1=it2.ShowY()+1;
//                                        cella posizione(it2.ShowX(),y1);

//                                        caselleNave.insert(a);
//                                    }else{
//                                        unsigned short y1=it.ShowY()+1;
//                                        cella posizione(it.ShowX(),y1);

//                                        caselleNave.insert(a);
//                                    }
                                }else{
                                    if((it.ShowX()>0 && it.ShowX()<9 && it.ShowY()==9) || (it2.ShowX()>0 && it2.ShowX()<9 && it2.ShowY()==9)){
                                        unsigned short y1=it.ShowY()-1;
                                        cella posizione(it.ShowX(),y1);
                                        caselleNave.push_front(posizione);

//                                        if(it.ShowY()<it2.ShowY()){
//                                            unsigned short y1=it.ShowY()-1;
//                                            cella posizione(it.ShowX(),y1);

//                                            caselleNave.insert(a);
//                                        }else{
//                                            unsigned short y1=it2.ShowY()-1;
//                                            cella posizione(it2.ShowX(),y1);

//                                            caselleNave.insert(a);
//                                        }
                                    }else{
//                                    if(it.ShowY()<it2.ShowY()){
                                        unsigned short y1=it.ShowY()-1;
                                        unsigned short y2=it2.ShowY()+1;
                                        unsigned short y[2]={y1,y2};
                                        std::cout<<"showX:"<<it2.ShowX()<<std::endl;
                                        std::cout<<"showY it:"<<it.ShowY()<<std::endl;
                                        std::cout<<"showY it2:"<<it2.ShowY()<<std::endl;
                                        unsigned short random=rand() % 2;
                                        std::cout<<"nuova Y:"<<y[random]<<std::endl;
                                        //provo a sostituire il random all' interno di posizione con una variabile standard
//                                        unsigned short yf=y[random];
                                        cella posizione(it.ShowX(),y[random]);
                                        if(y[random]<it.ShowY()){
                                            caselleNave.push_front(posizione);
                                        }else{
                                         caselleNave.push_back(posizione);
                                        }

//                                    }else{
//                                        if(it.ShowY()>it2.ShowY()){ //agginto condizione if per evitare caso it2.showY()==it.showY()
//                                            unsigned short y1=it2.ShowY()-1;
//                                            unsigned short y2=it.ShowY() +1;

//                                            unsigned short y[2]={y1,y2};

//                                            unsigned short random=rand() % 2;
//                                            cella posizione(it.ShowX(),y[random]);

//                                            caselleNave.insert(a);
//                                        }
//                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else{ //y1==y2
                std::cout<<"inizio caso verticale"<<std::endl;
                        if(it.ShowY()==it2.ShowY()){
                            //casi verticali
                            if((it.ShowX()==0 && it.ShowY()==0) || (it2.ShowX()==0 && it2.ShowY()==0)){
                                unsigned short x1=it2.ShowX()+1;
                                cella posizione(x1,it.ShowY());
                                caselleNave.push_back(posizione);


//                                std::cout<<"inizio caso verticale X=0 Y=0"<<std::endl;
//                                if(it.ShowX()<it2.ShowX()){
//                                    unsigned short x1=it2.ShowX()+1;
//                                    cella posizione(x1,it.ShowY());

//                                    caselleNave.insert(a);
//                                }else{
//                                    unsigned short x1=it.ShowX()+1;
//                                    cella posizione(x1,it.ShowY());

//                                    caselleNave.insert(a);
//                                }
                            }else{
                                if((it.ShowX()==0 && it.ShowY()==9) || (it2.ShowX()==0 && it2.ShowY()==9)){
                                    std::cout<<"inizio caso verticale X=0 Y=9"<<std::endl;
                                    unsigned short x1=it2.ShowX()+1;
                                    cella posizione(x1,it.ShowY());
                                    caselleNave.push_back(posizione);

//                                    if(it.ShowX()<it2.ShowX()){
//                                        unsigned short x1=it2.ShowX()+1;
//                                        cella posizione(x1,it.ShowY());

//                                        caselleNave.insert(a);
//                                    }else{
//                                        unsigned short x1=it.ShowX()+1;
//                                        cella posizione(x1,it.ShowY());

//                                        caselleNave.insert(a);
//                                    }
                                }else{
                                    if((it.ShowX()==9 && it.ShowY()==0) || (it2.ShowX()==9 && it2.ShowY()==0)){
                                        std::cout<<"inizio caso verticale X=9 Y=0"<<std::endl;
                                        unsigned short x1=it.ShowX()-1;
                                        cella posizione(x1,it.ShowY());
                                        caselleNave.push_front(posizione);

//                                        if(it.ShowX()<it.ShowX()){
//                                            unsigned short x1=it.ShowX()-1;
//                                            cella posizione(x1,it.ShowY());

//                                            caselleNave.insert(a);
//                                        }else{
//                                            unsigned short x1=it2.ShowX()-1;
//                                            cella posizione(x1,it2.ShowY());

//                                            caselleNave.insert(a);
//                                        }
                                    }else{
                                        if((it.ShowX()==9 && it.ShowY()==9) || (it2.ShowX()==9 && it2.ShowY()==9)){
                                            std::cout<<"inizio caso verticale X=9 Y=9"<<std::endl;
                                            unsigned short x1=it.ShowX()-1;
                                            cella posizione(x1,it.ShowY());
                                            caselleNave.push_front(posizione);

//                                            if(it.ShowX()<it2.ShowX()){
//                                                unsigned short x1=it.ShowX()-1;
//                                                cella posizione(x1,it.ShowY());

//                                                caselleNave.insert(a);
//                                            }else{
//                                                unsigned short x1=it2.ShowX()-1;
//                                                cella posizione(x1,it.ShowY());

//                                                caselleNave.insert(a);
//                                            }
                                        }else{
                                            if((it.ShowX()==0 && it.ShowY()>0 && it.ShowY()<9) || (it2.ShowX()==0 && it2.ShowY()>0 && it2.ShowY()<9)){
                                                std::cout<<"inizio caso verticale X=0 0<Y<9"<<std::endl;
                                                unsigned short x1=it2.ShowX()+1;
                                                cella posizione(x1,it.ShowY());
                                                caselleNave.push_back(posizione);

//                                                if(it.ShowX()<it2.ShowX()){
//                                                    unsigned short x1=it2.ShowX()+1;
//                                                    cella posizione(x1,it.ShowY());

//                                                    caselleNave.insert(a);
//                                                }else{
//                                                    unsigned short x1=it.ShowX()+1;
//                                                    cella posizione(x1,it.ShowY());

//                                                    caselleNave.insert(a);
//                                                }
                                            }else{
                                                if((it.ShowX()==9 && it.ShowY()>0 && it.ShowY()<9) || (it2.ShowX()==9 && it2.ShowY()>0 && it2.ShowY()<9)){
                                                    std::cout<<"inizio caso verticale X=9 0<Y<9"<<std::endl;
                                                    unsigned short x1=it.ShowX()-1;
                                                    cella posizione(x1,it.ShowY());
                                                    caselleNave.push_front(posizione);

//                                                    if(it.ShowX()<it2.ShowX()){
//                                                        std::cout<<"caso it<it2"<<std::endl;
//                                                        unsigned short x1=it.ShowX()-1;
//                                                        cella posizione(x1,it.ShowY());

//                                                        caselleNave.insert(a);
//                                                    }else{
//                                                        std::cout<<"inizio it>it2"<<std::endl;
//                                                        unsigned short x1=it2.ShowX()-1;
//                                                        cella posizione(x1,it.ShowY());

//                                                        caselleNave.insert(a);
//                                                    }
                                                }else{
//                                                    if(it.ShowX()<it2.ShowX()){
                                                        std::cout<<"inizio caso base verticale it<it2"<<std::endl;
                                                        unsigned short x1=(it.ShowX())-1;
                                                        unsigned short x2=(it2.ShowX())+1;
                                                        unsigned short x[2]={x1,x2};
                                                        unsigned short random=rand() % 2;
                                                          std::cout<<"random: "<<random<<std::endl;
                                                        cella posizione(x[random],it.ShowY());
                                                        if(x[random]<it.ShowX()){
                                                            caselleNave.push_front(posizione);
                                                        }else{
                                                            caselleNave.push_back(posizione);
                                                        }
//                                                    }else{
//                                                        if(it.ShowX()>it2.ShowX()){ //agginto condizione if per evitare caso it2.showX()==it.showX()
//                                                            std::cout<<"inizio caso base verticale it>it2"<<std::endl;
//                                                            unsigned short x1=(it2.ShowX())-1;
//                                                            unsigned short x2=(it.ShowX())+1;

//                                                            unsigned short x[2]={x1,x2};
//                                                            int random=rand() % 2;
//                                                            std::cout<<"random: "<<random<<std::endl;
//                                                            std::cout<<"x1="<<x1<<std::endl;
//                                                            std::cout<<"x2="<<x2<<std::endl;
//                                                            std::cout<<"x["<<random<<"]="<<x[random]<<std::endl;
//                                                            std::cout<<"inizializzo cella posizione"<<std::endl;
//                                                            cella posizione(x[random],it.ShowY());
//                                                            std::cout<<"fine cella posizione"<<std::endl;
//                                                            std::cout<<"inizializzo map a"<<std::endl;
//                                                            std::list<cella>::iterator::value_type a(caselleNave.size()+1 ,posizione);
//                                                            std::cout<<"fine map a"<<std::endl;
//                                                            std::cout<<"insert a"<<std::endl;
//                                                            caselleNave.insert(a);
//                                                            std::cout<<"fine insert a"<<std::endl;
//                                                        }
                                                        }


                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
    it=caselleNave.front();
    it2=caselleNave.back();
    for(std::list<cella>::iterator it=caselleNave.begin();it!=caselleNave.end();it++){
        std::cout<<"x:"<<it->ShowX()<<" Y:"<<it->ShowY()<<std::endl;
    }
        std::cout<<"it: "<<it.ShowX()<<" "<<it.ShowY()<<std::endl;
        std::cout<<"it2: "<<it2.ShowX()<<" "<<it2.ShowY()<<std::endl;
        std::cout<<"fine caso verticale"<<std::endl;
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



Nave::Nave(unsigned short X, unsigned short Y)
{
    cella posizione(X,Y);
    caselleNave.push_back(posizione);
//
//    caselleNave.insert(a);
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
