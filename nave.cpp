#include "nave.h"

void Nave::reset()
{
    std::map<unsigned short int,cella>::iterator it;
    caselleNave.clear();
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
    std::map<unsigned short int,cella>::iterator it=caselleNave.begin();
    std::map<unsigned short int,cella>::iterator it2=caselleNave.end();
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
    return false;
}

void Nave::Posizionamentocomputer()
{

    std::map<unsigned short int,cella>::iterator it=caselleNave.begin();
    std::map<unsigned short int,cella>::iterator it2=caselleNave.end();
    it2--;
    if(it->first==it2->first && counter()==1){
if(it->second.ShowX()==0 && it->second.ShowY()==9){
            unsigned short int x0=(it->second.ShowX());
            unsigned short int x1=(it->second.ShowX())+1;
            unsigned short int y0=(it->second.ShowY());
            unsigned short int y1=(it->second.ShowY())-1;
            unsigned short int x[2]={x0,x1};
            unsigned short int randomX=rand() % 2;
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
    unsigned short int x0=(it->second.ShowX());
    unsigned short int x1=(it->second.ShowX())-1;
    unsigned short int y0=(it->second.ShowY());
    unsigned short int y1=(it->second.ShowY())+1;
    unsigned short int x[2]={x0,x1};
    unsigned short int randomX=rand() % 2;
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
            unsigned short int x0=(it->second.ShowX());
            unsigned short int x1=(it->second.ShowX())+1;

            unsigned short int x[2]={x0,x1};
            unsigned short int randomX=rand() % 2;
            if(x[randomX]==x0){
                unsigned short int y0=(it->second.ShowY())-1;
                unsigned short int y1=(it->second.ShowY())+1;
                unsigned short int y[2]={y0,y1};
                unsigned short int randomY=rand() % 2;
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
    unsigned short int y0=(it->second.ShowY());
    unsigned short int y1=(it->second.ShowY())+1;
    unsigned short int y[2]={y0,y1};
    unsigned short int randomY=rand() % 2;
    if(y[randomY]==y0){
        unsigned short int x0=(it->second.ShowX())-1;
        unsigned short int x1=(it->second.ShowX())+1;
        unsigned short int x[2]={x0,x1};
        unsigned short int randomX=rand() % 2;
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
    unsigned short int x0=(it->second.ShowX());
    unsigned short int x1=(it->second.ShowX())+1;
    unsigned short int x[2]={x0,x1};
    unsigned short int randomX=rand() % 2;
    if(x[randomX]==x0){
        unsigned short int y1=(it->second.ShowY())+1;
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
       unsigned short int x0=(it->second.ShowX());
       unsigned short int x1=(it->second.ShowX())-1;
       unsigned short int x[2]={x0,x1};
       unsigned short int randomX=rand() % 2;
       if(x[randomX]==x0){
           unsigned short int y1=(it->second.ShowY())-1;
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
           unsigned short int x0=it->second.ShowX();
           unsigned short int x1=it->second.ShowX()-1;
           unsigned short int x[2]={x0,x1};
           unsigned short int randomX=rand()%2;
           if(x[randomX]==x0){
               unsigned short int y1=it->second.ShowY()-1;
               unsigned short int y2=it->second.ShowY()+1;
               unsigned short int y[2]={y1,y2};
               unsigned short int randomY=rand()%2;
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
               unsigned short int y0=it->second.ShowY();
               unsigned short int y1=it->second.ShowY()-1;
               unsigned short int y[2]={y0,y1};
               unsigned short int randomY=rand()%2;
               if(y[randomY]==y0){
                   unsigned short int x1=it->second.ShowX()-1;
                   unsigned short int x2=it->second.ShowX()+1;
                   unsigned short int x[2]={x1,x2};
                   unsigned short int randomX=rand()%2;
                   cella posizione(x[randomX],y0);
                   std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                   caselleNave.insert(a);
               }else{
                   cella posizione(it->second.ShowX(),y1);
                   std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                   caselleNave.insert(a);
               }
           }else{
               unsigned short int x0=(it->second.ShowX())-1;
               unsigned short int x2=(it->second.ShowX())+1;
               unsigned short int y0=(it->second.ShowY())-1;
               unsigned short int y2=(it->second.ShowY())+1;
               unsigned short int x[3]={x0,it->second.ShowX(),x2};
               unsigned short int y[3]={y0,it->second.ShowY(),y2};

               unsigned short int randomX=rand() % 3; //prima era %3
               unsigned short int randomY=rand() % 3; //prima era %3
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
        if(counter()>1){
            if(it->second.ShowX()==it2->second.ShowX()){
                if((it->second.ShowX()==0 && it->second.ShowY()==0) || (it2->second.ShowX()==0 && it2->second.ShowY()==0)){
                    if(it->second.ShowY()<it2->second.ShowY()){
                        unsigned short int y1=it2->second.ShowY()+1;
                        cella posizione(it2->second.ShowX(),y1);
                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                        caselleNave.insert(a);
                    }else{
                        unsigned short int y1=it->second.ShowY()+1;
                        cella posizione(it->second.ShowX(),y1);
                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                        caselleNave.insert(a);
                    }
                }else{
                    if((it->second.ShowX()==0 && it->second.ShowY()==9) || (it2->second.ShowX()==0 && it2->second.ShowY()==9)){
                        if(it->second.ShowY()<it2->second.ShowY()){
                            unsigned short int y1=it->second.ShowY()-1;
                            cella posizione(it->second.ShowX(),y1);
                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                            caselleNave.insert(a);
                        }else{
                            unsigned short int y1=it2->second.ShowY()-1;
                            cella posizione(it->second.ShowX(),y1);
                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                            caselleNave.insert(a);
                        }
                    }else{
                        if((it->second.ShowX()==9 && it->second.ShowY()==0) || (it2->second.ShowX()==9 && it2->second.ShowY()==0)){
                            if(it->second.ShowY()<it2->second.ShowY()){
                                unsigned short int y1=it2->second.ShowY()+1;
                                cella posizione(it2->second.ShowX(),y1);
                                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                caselleNave.insert(a);
                            }else{
                                unsigned short int y1=it->second.ShowY()+1;
                                cella posizione(it->second.ShowX(),y1);
                                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                caselleNave.insert(a);
                            }
                        }else{
                            if((it->second.ShowX()==9 && it->second.ShowY()==9) || (it2->second.ShowX()==9 && it2->second.ShowY()==9)){
                                if(it->second.ShowY()<it2->second.ShowY()){
                                    unsigned short int y1=it->second.ShowY()-1;
                                    cella posizione(it->second.ShowX(),y1);
                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }else{
                                    unsigned short int y1=it2->second.ShowY()-1;
                                    cella posizione(it2->second.ShowX(),y1);
                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }
                            }else{
                                if((it->second.ShowX()>0 && it->second.ShowX()<9 && it->second.ShowY()==0)||(it2->second.ShowX()>0 && it2->second.ShowX()<9 && it2->second.ShowY()==0)){
                                    if(it->second.ShowY()<it2->second.ShowY()){
                                        unsigned short int y1=it2->second.ShowY()+1;
                                        cella posizione(it2->second.ShowX(),y1);
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }else{
                                        unsigned short int y1=it->second.ShowY()+1;
                                        cella posizione(it->second.ShowX(),y1);
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }
                                }else{
                                    if((it->second.ShowX()>0 && it->second.ShowX()<9 && it->second.ShowY()==9) || (it2->second.ShowX()>0 && it2->second.ShowX()<9 && it2->second.ShowY()==9)){
                                        if(it->second.ShowY()<it2->second.ShowY()){
                                            unsigned short int y1=it->second.ShowY()-1;
                                            cella posizione(it->second.ShowX(),y1);
                                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }else{
                                            unsigned short int y1=it2->second.ShowY()-1;
                                            cella posizione(it2->second.ShowX(),y1);
                                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }
                                    }else{
                                    if(it->second.ShowY()<it2->second.ShowY()){
                                        unsigned short int y1=it->second.ShowY()-1;
                                        unsigned short int y2=it2->second.ShowY() +1;
                                        unsigned short int y[2]={y1,y2};

                                        unsigned short int random=rand() % 2;
                                        cella posizione(it->second.ShowX(),y[random]);
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }else{
                                        unsigned short int y1=it2->second.ShowY()-1;
                                        unsigned short int y2=it->second.ShowY() +1;

                                        unsigned short int y[2]={y1,y2};

                                        unsigned short int random=rand() % 2;
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
                    }else{
                        if(it->second.ShowY()==it2->second.ShowY()){
                            if((it->second.ShowX()==0 && it->second.ShowY()==0) || (it2->second.ShowX()==0 && it2->second.ShowY()==0)){
                                if(it->second.ShowX()<it2->second.ShowX()){
                                    unsigned short int x1=it2->second.ShowX()+1;
                                    cella posizione(x1,it->second.ShowY());
                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }else{
                                    unsigned short int x1=it->second.ShowX()+1;
                                    cella posizione(x1,it->second.ShowY());
                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }
                            }else{
                                if((it->second.ShowX()==0 && it->second.ShowY()==9) || (it2->second.ShowX()==0 && it2->second.ShowY()==9)){
                                    if(it->second.ShowX()<it2->second.ShowX()){
                                        unsigned short int x1=it2->second.ShowX()+1;
                                        cella posizione(x1,it->second.ShowY());
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }else{
                                        unsigned short int x1=it->second.ShowX()+1;
                                        cella posizione(x1,it->second.ShowY());
                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }
                                }else{
                                    if((it->second.ShowX()==9 && it->second.ShowY()==0) || (it2->second.ShowX()==9 && it2->second.ShowY()==0)){
                                        if(it->second.ShowX()<it->second.ShowX()){
                                            unsigned short int x1=it->second.ShowX()-1;
                                            cella posizione(x1,it->second.ShowY());
                                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }else{
                                            unsigned short int x1=it2->second.ShowX()-1;
                                            cella posizione(x1,it2->second.ShowY());
                                            std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }
                                    }else{
                                        if((it->second.ShowX()==9 && it->second.ShowY()==9) || (it2->second.ShowX()==9 && it2->second.ShowY()==9)){
                                            if(it->second.ShowX()<it2->second.ShowX()){
                                                unsigned short int x1=it->second.ShowX()-1;
                                                cella posizione(x1,it->second.ShowY());
                                                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                caselleNave.insert(a);
                                            }else{
                                                unsigned short int x1=it2->second.ShowX()-1;
                                                cella posizione(x1,it->second.ShowY());
                                                std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                caselleNave.insert(a);
                                            }
                                        }else{
                                            if((it->second.ShowX()==0 && it->second.ShowY()>0 && it->second.ShowY()<9) || (it2->second.ShowX()==0 && it2->second.ShowY()>0 && it2->second.ShowY()<9)){
                                                if(it->second.ShowX()<it2->second.ShowX()){
                                                    unsigned short int x1=it2->second.ShowX()+1;
                                                    cella posizione(x1,it->second.ShowY());
                                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                    caselleNave.insert(a);
                                                }else{
                                                    unsigned short int x1=it->second.ShowX()+1;
                                                    cella posizione(x1,it->second.ShowY());
                                                    std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                    caselleNave.insert(a);
                                                }
                                            }else{
                                                if((it->second.ShowX()==9 && it->second.ShowY()>0 && it->second.ShowY()<9) || (it2->second.ShowX()==9 && it2->second.ShowY()>0 && it2->second.ShowY()<9)){
                                                    if(it->second.ShowX()<it2->second.ShowX()){
                                                        unsigned short int x1=it->second.ShowX()-1;
                                                        cella posizione(x1,it->second.ShowY());
                                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                        caselleNave.insert(a);
                                                    }else{
                                                        unsigned short int x1=it2->second.ShowX()-1;
                                                        cella posizione(x1,it->second.ShowY());
                                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                        caselleNave.insert(a);
                                                    }
                                                }else{
                                                    if(it->second.ShowX()<it2->second.ShowX()){
                                                        unsigned short int x1=(it->second.ShowX())-1;
                                                        unsigned short int x2=(it2->second.ShowX())+1;
                                                        unsigned short int x[2]={x1,x2};
                                                        unsigned short int random=rand() % 2;

                                                        cella posizione(x[random],it->second.ShowY());
                                                        std::map<int,cella>::value_type a(caselleNave.size()+1 ,posizione);
                                                        caselleNave.insert(a);
                                                    }else{
                                                        unsigned short int x1=(it2->second.ShowX())-1;
                                                        unsigned short int x2=(it->second.ShowX())+1;

                                                        unsigned short int x[2]={x1,x2};
                                                        unsigned short int random=rand() % 2;

                                                        cella posizione(x[random],it->second.ShowY());
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
                        }
                    }
                }
}


unsigned short Nave::PosizionaGrigliaC()
{
    std::map<unsigned short int,cella>::iterator it=caselleNave.end();
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
    for(std::map<unsigned short int,cella>::iterator it=caselleNave.begin();it!=caselleNave.end();it++){
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
