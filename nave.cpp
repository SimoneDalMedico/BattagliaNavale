#include "nave.h"

void Nave::reset()
{
    std::map<unsigned short,cella>::iterator it;
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
    std::map<unsigned short,cella>::iterator it=caselleNave.begin();
    std::map<unsigned short,cella>::iterator it2=caselleNave.end();
    it2--;
        if(it->first==it2->first){
            if((x==(it2->second.ShowX())-1 && y==it2->second.ShowY()) || (x==(it2->second.ShowX())+1 && y==it2->second.ShowY()) || (x==it2->second.ShowX() && y==(it2->second.ShowY())-1) || (x==it2->second.ShowX() && y==(it2->second.ShowY())+1)){
                return true;
            }
        }else{
            if(it->second.ShowX()==it2->second.ShowX() && x==it2->second.ShowX() && (y==(it2->second.ShowY())+1 || y==(it2->second.ShowY())-1)){
                return true;
            }
            if(it->second.ShowY()==it2->second.ShowY() && y==it2->second.ShowY() && (x==(it2->second.ShowX())+1 || x==(it2->second.ShowX())-1)){
                return true;
            }
        }
    }
    std::cout<<"return FALSE checkposizione!"<<std::endl;
    return false;
}

void Nave::Posizionamentocomputer()
{

    std::map<unsigned short,cella>::iterator it=caselleNave.begin();
    std::map<unsigned short,cella>::iterator it2=caselleNave.end();
    it2--;
    if(it->first==it2->first && counter()==1){
        std::cout<<"inizio caso inserimneto seconda casella"<<std::endl;
if(it->second.ShowX()==0 && it->second.ShowY()==9){
            unsigned short x0=(it->second.ShowX());
            unsigned short x1=(it->second.ShowX())+1;
            unsigned short y0=(it->second.ShowY());
            unsigned short y1=(it->second.ShowY())-1;
            unsigned short x[2]={x0,x1};
            unsigned short randomX=rand() % 2;
            if(x[randomX]==x0){
                cella posizione(x0,y1);
                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                caselleNave.insert(a);
            }else{
                cella posizione(x1,y0);
                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                caselleNave.insert(a);
            }
}else{
if(it->second.ShowX()==9 && it->second.ShowY()==0){
    unsigned short x0=(it->second.ShowX());
    unsigned short x1=(it->second.ShowX())-1;
    unsigned short y0=(it->second.ShowY());
    unsigned short y1=(it->second.ShowY())+1;
    unsigned short x[2]={x0,x1};
    unsigned short randomX=rand() % 2;
    if(x[randomX]==x0){
        cella posizione(x0,y1);
        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }else{
        cella posizione(x1,y0);
        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }
}else{
if(it->second.ShowX()==0 && it->second.ShowY()<9 && it->second.ShowY()>0){
            unsigned short x0=(it->second.ShowX());
            unsigned short x1=(it->second.ShowX())+1;

            unsigned short x[2]={x0,x1};
            unsigned short randomX=rand() % 2;
            if(x[randomX]==x0){
                unsigned short y0=(it->second.ShowY())-1;
                unsigned short y1=(it->second.ShowY())+1;
                unsigned short y[2]={y0,y1};
                unsigned short randomY=rand() % 2;
                cella posizione(x0,y[randomY]);
                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                caselleNave.insert(a);
            }else{
                cella posizione(x1,it->second.ShowY());
                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                caselleNave.insert(a);
            }


}else{
if(it->second.ShowX()<9 && it->second.ShowY()==0 && it->second.ShowX()>0){
    unsigned short y0=(it->second.ShowY());
    unsigned short y1=(it->second.ShowY())+1;
    unsigned short y[2]={y0,y1};
    unsigned short randomY=rand() % 2;
    if(y[randomY]==y0){
        unsigned short x0=(it->second.ShowX())-1;
        unsigned short x1=(it->second.ShowX())+1;
        unsigned short x[2]={x0,x1};
        unsigned short randomX=rand() % 2;
        cella posizione(x[randomX],y0);
        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }else{
        cella posizione(it->second.ShowX(),y1);
        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }
}else{
if(it->second.ShowX()==0 && it->second.ShowY()==0){
    unsigned short x0=(it->second.ShowX());
    unsigned short x1=(it->second.ShowX())+1;
    unsigned short x[2]={x0,x1};
    unsigned short randomX=rand() % 2;
    if(x[randomX]==x0){
        unsigned short y1=(it->second.ShowY())+1;
        cella posizione(x0,y1);
        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }else{
        cella posizione(x1,it->second.ShowY());
        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }
}else{
   if(it->second.ShowX()==9 && it->second.ShowY()==9){
       unsigned short x0=(it->second.ShowX());
       unsigned short x1=(it->second.ShowX())-1;
       unsigned short x[2]={x0,x1};
       unsigned short randomX=rand() % 2;
       if(x[randomX]==x0){
           unsigned short y1=(it->second.ShowY())-1;
           cella posizione(x0,y1);
           std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
           caselleNave.insert(a);
       }else{
           cella posizione(x1,it->second.ShowY());
           std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
           caselleNave.insert(a);
       }
   } else{
       if(it->second.ShowX()==9 && it->second.ShowY()<9 && it->second.ShowY()>0){
           unsigned short x0=it->second.ShowX();
           unsigned short x1=it->second.ShowX()-1;
           unsigned short x[2]={x0,x1};
           unsigned short randomX=rand()%2;
           if(x[randomX]==x0){
               unsigned short y1=it->second.ShowY()-1;
               unsigned short y2=it->second.ShowY()+1;
               unsigned short y[2]={y1,y2};
               unsigned short randomY=rand()%2;
               cella posizione(x0,y[randomY]);
               std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
               caselleNave.insert(a);
           }else{
               cella posizione(x1,it->second.ShowY());
               std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
               caselleNave.insert(a);
           }
       }else{
           if(it->second.ShowX()<9 && it->second.ShowX()>0 && it->second.ShowY()==9){
               unsigned short y0=it->second.ShowY();
               unsigned short y1=it->second.ShowY()-1;
               unsigned short y[2]={y0,y1};
               unsigned short randomY=rand()%2;
               if(y[randomY]==y0){
                   unsigned short x1=it->second.ShowX()-1;
                   unsigned short x2=it->second.ShowX()+1;
                   unsigned short x[2]={x1,x2};
                   unsigned short randomX=rand()%2;
                   cella posizione(x[randomX],y0);
                   std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                   caselleNave.insert(a);
               }else{
                   cella posizione(it->second.ShowX(),y1);
                   std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                   caselleNave.insert(a);
               }
           }else{
               unsigned short x0=(it->second.ShowX())-1;
               unsigned short x2=(it->second.ShowX())+1;
               unsigned short y0=(it->second.ShowY())-1;
               unsigned short y2=(it->second.ShowY())+1;
               unsigned short x[3]={x0,it->second.ShowX(),x2};
               unsigned short y[3]={y0,it->second.ShowY(),y2};

               unsigned short randomX=rand() % 3; //prima era %3
               unsigned short randomY=rand() % 3; //prima era %3
               while(!((x[randomX]==x0 && y[randomY]==y[1]) || (x[randomX]==x[1] && y[randomY]==y0) || (x[randomX]==x[1] && y[randomY]==y2) || (x[randomX]==x2 && y[randomY]==y[1]))){
                        randomX=rand() % 3;
                        randomY=rand() % 3;
               }
               cella posizione(x[randomX],y[randomY]);
               std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
               caselleNave.insert(a);
           }
       }
   }
}
}
}
}
}

}else{
        if(counter()>1){//x1==x2
            std::cout<<"inizio caso orizzzontale"<<std::endl;
            if(it->second.ShowX()==it2->second.ShowX()){
                if((it->second.ShowX()==0 && it->second.ShowY()==0) || (it2->second.ShowX()==0 && it2->second.ShowY()==0)){
                    if(it->second.ShowY()<it2->second.ShowY()){
                        unsigned short y1=it2->second.ShowY()+1;
                        cella posizione(it2->second.ShowX(),y1);
                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                        caselleNave.insert(a);
                    }else{
                        unsigned short y1=it->second.ShowY()+1;
                        cella posizione(it->second.ShowX(),y1);
                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                        caselleNave.insert(a);
                    }
                }else{
                    if((it->second.ShowX()==0 && it->second.ShowY()==9) || (it2->second.ShowX()==0 && it2->second.ShowY()==9)){
                        if(it->second.ShowY()<it2->second.ShowY()){
                            unsigned short y1=it->second.ShowY()-1;
                            cella posizione(it->second.ShowX(),y1);
                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                            caselleNave.insert(a);
                        }else{
                            unsigned short y1=it2->second.ShowY()-1;
                            cella posizione(it->second.ShowX(),y1);
                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                            caselleNave.insert(a);
                        }
                    }else{
                        if((it->second.ShowX()==9 && it->second.ShowY()==0) || (it2->second.ShowX()==9 && it2->second.ShowY()==0)){
                            if(it->second.ShowY()<it2->second.ShowY()){
                                unsigned short y1=it2->second.ShowY()+1;
                                cella posizione(it2->second.ShowX(),y1);
                                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                caselleNave.insert(a);
                            }else{
                                unsigned short y1=it->second.ShowY()+1;
                                cella posizione(it->second.ShowX(),y1);
                                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                caselleNave.insert(a);
                            }
                        }else{
                            if((it->second.ShowX()==9 && it->second.ShowY()==9) || (it2->second.ShowX()==9 && it2->second.ShowY()==9)){
                                if(it->second.ShowY()<it2->second.ShowY()){
                                    unsigned short y1=it->second.ShowY()-1;
                                    cella posizione(it->second.ShowX(),y1);
                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }else{
                                    unsigned short y1=it2->second.ShowY()-1;
                                    cella posizione(it2->second.ShowX(),y1);
                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }
                            }else{
                                if((it->second.ShowX()>0 && it->second.ShowX()<9 && it->second.ShowY()==0)||(it2->second.ShowX()>0 && it2->second.ShowX()<9 && it2->second.ShowY()==0)){ //da verificare se è giusto inserire y1 (forse è x1)
                                    if(it->second.ShowY()<it2->second.ShowY()){
                                        unsigned short y1=it2->second.ShowY()+1;
                                        cella posizione(it2->second.ShowX(),y1);
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }else{
                                        unsigned short y1=it->second.ShowY()+1;
                                        cella posizione(it->second.ShowX(),y1);
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }
                                }else{
                                    if((it->second.ShowX()>0 && it->second.ShowX()<9 && it->second.ShowY()==9) || (it2->second.ShowX()>0 && it2->second.ShowX()<9 && it2->second.ShowY()==9)){
                                        if(it->second.ShowY()<it2->second.ShowY()){
                                            unsigned short y1=it->second.ShowY()-1;
                                            cella posizione(it->second.ShowX(),y1);
                                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }else{
                                            unsigned short y1=it2->second.ShowY()-1;
                                            cella posizione(it2->second.ShowX(),y1);
                                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }
                                    }else{
                                    if(it->second.ShowY()<it2->second.ShowY()/* && aggiunto la variabile x1==x2 it->second.ShowX()==it2->second.ShowX()*/){
                                        unsigned short y1=it->second.ShowY()-1;
                                        unsigned short y2=it2->second.ShowY()+1;
                                        unsigned short y[2]={y1,y2};
                                        std::cout<<"showX:"<<it2->second.ShowX()<<std::endl;
                                        std::cout<<"showY it:"<<it->second.ShowY()<<std::endl;
                                        std::cout<<"showY it2:"<<it2->second.ShowY()<<std::endl;
                                        unsigned short random=rand() % 2;
                                        std::cout<<"nuova Y:"<<y[random]<<std::endl;
                                        //provo a sostituire il random all' interno di posizione con una variabile standard
                                        unsigned short yf=y[random];

                                        cella posizione(it->second.ShowX(),yf);
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }else{
                                        if(it->second.ShowY()>it2->second.ShowY()){ //agginto condizione if per evitare caso it2.showY()==it.showY()
                                            unsigned short y1=it2->second.ShowY()-1;
                                            unsigned short y2=it->second.ShowY() +1;

                                            unsigned short y[2]={y1,y2};

                                            unsigned short random=rand() % 2;
                                            cella posizione(it->second.ShowX(),y[random]);
                                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
                    }else{ //y1==y2
                std::cout<<"inizio caso verticale"<<std::endl;
                        if(it->second.ShowY()==it2->second.ShowY()){
                            if((it->second.ShowX()==0 && it->second.ShowY()==0) || (it2->second.ShowX()==0 && it2->second.ShowY()==0)){
                                std::cout<<"inizio caso verticale X=0 Y=0"<<std::endl;
                                if(it->second.ShowX()<it2->second.ShowX()){
                                    unsigned short x1=it2->second.ShowX()+1;
                                    cella posizione(x1,it->second.ShowY());
                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }else{
                                    unsigned short x1=it->second.ShowX()+1;
                                    cella posizione(x1,it->second.ShowY());
                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }
                            }else{
                                if((it->second.ShowX()==0 && it->second.ShowY()==9) || (it2->second.ShowX()==0 && it2->second.ShowY()==9)){
                                    std::cout<<"inizio caso verticale X=0 Y=9"<<std::endl;
                                    if(it->second.ShowX()<it2->second.ShowX()){
                                        unsigned short x1=it2->second.ShowX()+1;
                                        cella posizione(x1,it->second.ShowY());
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }else{
                                        unsigned short x1=it->second.ShowX()+1;
                                        cella posizione(x1,it->second.ShowY());
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }
                                }else{
                                    if((it->second.ShowX()==9 && it->second.ShowY()==0) || (it2->second.ShowX()==9 && it2->second.ShowY()==0)){
                                        std::cout<<"inizio caso verticale X=9 Y=0"<<std::endl;
                                        if(it->second.ShowX()<it->second.ShowX()){
                                            unsigned short x1=it->second.ShowX()-1;
                                            cella posizione(x1,it->second.ShowY());
                                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }else{
                                            unsigned short x1=it2->second.ShowX()-1;
                                            cella posizione(x1,it2->second.ShowY());
                                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }
                                    }else{
                                        if((it->second.ShowX()==9 && it->second.ShowY()==9) || (it2->second.ShowX()==9 && it2->second.ShowY()==9)){
                                            std::cout<<"inizio caso verticale X=9 Y=9"<<std::endl;
                                            if(it->second.ShowX()<it2->second.ShowX()){
                                                unsigned short x1=it->second.ShowX()-1;
                                                cella posizione(x1,it->second.ShowY());
                                                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                caselleNave.insert(a);
                                            }else{
                                                unsigned short x1=it2->second.ShowX()-1;
                                                cella posizione(x1,it->second.ShowY());
                                                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                caselleNave.insert(a);
                                            }
                                        }else{
                                            if((it->second.ShowX()==0 && it->second.ShowY()>0 && it->second.ShowY()<9) || (it2->second.ShowX()==0 && it2->second.ShowY()>0 && it2->second.ShowY()<9)){
                                                std::cout<<"inizio caso verticale X=0 0<Y<9"<<std::endl;
                                                if(it->second.ShowX()<it2->second.ShowX()){
                                                    unsigned short x1=it2->second.ShowX()+1;
                                                    cella posizione(x1,it->second.ShowY());
                                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                    caselleNave.insert(a);
                                                }else{
                                                    unsigned short x1=it->second.ShowX()+1;
                                                    cella posizione(x1,it->second.ShowY());
                                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                    caselleNave.insert(a);
                                                }
                                            }else{
                                                if((it->second.ShowX()==9 && it->second.ShowY()>0 && it->second.ShowY()<9) || (it2->second.ShowX()==9 && it2->second.ShowY()>0 && it2->second.ShowY()<9)){
                                                    std::cout<<"inizio caso verticale X=9 0<Y<9"<<std::endl;
                                                    if(it->second.ShowX()<it2->second.ShowX()){
                                                        std::cout<<"caso it<it2"<<std::endl;
                                                        unsigned short x1=it->second.ShowX()-1;
                                                        cella posizione(x1,it->second.ShowY());
                                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                        caselleNave.insert(a);
                                                    }else{
                                                        std::cout<<"inizio it>it2"<<std::endl;
                                                        unsigned short x1=it2->second.ShowX()-1;
                                                        cella posizione(x1,it->second.ShowY());
                                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                        caselleNave.insert(a);
                                                    }
                                                }else{
                                                    if(it->second.ShowX()<it2->second.ShowX()){
                                                        std::cout<<"inizio caso base verticale it<it2"<<std::endl;
                                                        unsigned short x1=(it->second.ShowX())-1;
                                                        unsigned short x2=(it2->second.ShowX())+1;
                                                        unsigned short x[2]={x1,x2};
                                                        unsigned short random=rand() % 2;
                                                          std::cout<<"random: "<<random<<std::endl;
                                                        cella posizione(x[random],it->second.ShowY());
                                                        std::map<unsigned short,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                        caselleNave.insert(a);
                                                    }else{
                                                        if(it->second.ShowX()>it2->second.ShowX()){ //agginto condizione if per evitare caso it2.showX()==it.showX()
                                                            std::cout<<"inizio caso base verticale it>it2"<<std::endl;
                                                            unsigned short x1=(it2->second.ShowX())-1;
                                                            unsigned short x2=(it->second.ShowX())+1;

                                                            unsigned short x[2]={x1,x2};
                                                            int random=rand() % 2;
                                                            std::cout<<"random: "<<random<<std::endl;
                                                            std::cout<<"x1="<<x1<<std::endl;
                                                            std::cout<<"x2="<<x2<<std::endl;
                                                            std::cout<<"x["<<random<<"]="<<x[random]<<std::endl;
                                                            std::cout<<"inizializzo cella posizione"<<std::endl;
                                                            cella posizione(x[random],it->second.ShowY());
                                                            std::cout<<"fine cella posizione"<<std::endl;
                                                            std::cout<<"inizializzo map a"<<std::endl;
                                                            std::map<unsigned short,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                            std::cout<<"fine map a"<<std::endl;
                                                            std::cout<<"insert a"<<std::endl;
                                                            caselleNave.insert(a);
                                                            std::cout<<"fine insert a"<<std::endl;
                                                        }
                                                        }


                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        std::cout<<"fine caso verticale"<<std::endl;
                        }
                    }
                }
}


unsigned short Nave::PosizionaGrigliaC()
{
    std::map<unsigned short,cella>::iterator it=caselleNave.end();
    it--;
    return (((it->second.ShowX())*10)+it->second.ShowY());
}



Nave::Nave(unsigned short X, unsigned short Y)
{
    cella posizione(X,Y);
    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
    caselleNave.insert(a);
}

bool Nave::colpita(unsigned short X, unsigned short Y)
{
    for(std::map<unsigned short,cella>::iterator it=caselleNave.begin();it!=caselleNave.end();it++){
        if(it->second.ShowX()==X && it->second.ShowY()==Y){
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
