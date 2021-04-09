#include "nave.h"

void Nave::reset()
{
    std::map<unsigned short int,tpair>::iterator it;
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
    std::map<unsigned short int,tpair>::iterator it=caselleNave.begin();
    std::map<unsigned short int,tpair>::iterator it2=caselleNave.end();
    it2--;
        if(it->first==it2->first){
            if((x==(it2->second.first)-1 && y==it2->second.second) || (x==(it2->second.first)+1 && y==it2->second.second) || (x==it2->second.first && y==(it2->second.second)-1) || (x==it2->second.first && y==(it2->second.second)+1)){
                return true;
            }
        }else{
            if(it->second.first==it2->second.first && x==it2->second.first && (y==(it2->second.second)+1 || y==(it2->second.second)-1)){
                return true;
            }
            if(it->second.second==it2->second.second && y==it2->second.second && (x==(it2->second.first)+1 || x==(it2->second.first)-1)){
                return true;
            }
        }
    }
    return false;
}

void Nave::Posizionamentocomputer()
{

    std::map<unsigned short int,tpair>::iterator it=caselleNave.begin();
    std::map<unsigned short int,tpair>::iterator it2=caselleNave.end();
    it2--;
    if(it->first==it2->first && counter()==1){
if(it->second.first==0 && it->second.second==9){
            unsigned short int x0=(it->second.first);
            unsigned short int x1=(it->second.first)+1;
            unsigned short int y0=(it->second.second);
            unsigned short int y1=(it->second.second)-1;
            unsigned short int x[2]={x0,x1};
            unsigned short int randomX=rand() % 2;
            if(x[randomX]==x0){
                tpair posizione=std::pair<unsigned short int, unsigned short int>(x0,y1);
                std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                caselleNave.insert(a);
            }else{
                tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,y0);
                std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                caselleNave.insert(a);
            }
}else{
if(it->second.first==9 && it->second.second==0){
    unsigned short int x0=(it->second.first);
    unsigned short int x1=(it->second.first)-1;
    unsigned short int y0=(it->second.second);
    unsigned short int y1=(it->second.second)+1;
    unsigned short int x[2]={x0,x1};
    unsigned short int randomX=rand() % 2;
    if(x[randomX]==x0){
        tpair posizione=std::pair<unsigned short int, unsigned short int>(x0,y1);
        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }else{
        tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,y0);
        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }
}else{
if(it->second.first==0 && it->second.second<9 && it->second.second>0){
            unsigned short int x0=(it->second.first);
            unsigned short int x1=(it->second.first)+1;

            unsigned short int x[2]={x0,x1};
            unsigned short int randomX=rand() % 2;
            if(x[randomX]==x0){
                unsigned short int y0=(it->second.second)-1;
                unsigned short int y1=(it->second.second)+1;
                unsigned short int y[2]={y0,y1};
                unsigned short int randomY=rand() % 2;
                tpair posizione=std::pair<unsigned short int, unsigned short int>(x0,y[randomY]);
                std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                caselleNave.insert(a);
            }else{
                tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                caselleNave.insert(a);
            }


}else{
if(it->second.first<9 && it->second.second==0 && it->second.first>0){
    unsigned short int y0=(it->second.second);
    unsigned short int y1=(it->second.second)+1;
    unsigned short int y[2]={y0,y1};
    unsigned short int randomY=rand() % 2;
    if(y[randomY]==y0){
        unsigned short int x0=(it->second.first)-1;
        unsigned short int x1=(it->second.first)+1;
        unsigned short int x[2]={x0,x1};
        unsigned short int randomX=rand() % 2;
        tpair posizione=std::pair<unsigned short int, unsigned short int>(x[randomX],y0);
        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }else{
        tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y1);
        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }
}else{
if(it->second.first==0 && it->second.second==0){
    unsigned short int x0=(it->second.first);
    unsigned short int x1=(it->second.first)+1;
    unsigned short int x[2]={x0,x1};
    unsigned short int randomX=rand() % 2;
    if(x[randomX]==x0){
        unsigned short int y1=(it->second.second)+1;
        tpair posizione=std::pair<unsigned short int, unsigned short int>(x0,y1);
        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }else{
        tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
        caselleNave.insert(a);
    }
}else{
   if(it->second.first==9 && it->second.second==9){
       unsigned short int x0=(it->second.first);
       unsigned short int x1=(it->second.first)-1;
       unsigned short int x[2]={x0,x1};
       unsigned short int randomX=rand() % 2;
       if(x[randomX]==x0){
           unsigned short int y1=(it->second.second)-1;
           tpair posizione=std::pair<unsigned short int, unsigned short int>(x0,y1);
           std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
           caselleNave.insert(a);
       }else{
           tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
           std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
           caselleNave.insert(a);
       }
   } else{
       if(it->second.first==9 && it->second.second<9 && it->second.second>0){
           unsigned short int x0=it->second.first;
           unsigned short int x1=it->second.first-1;
           unsigned short int x[2]={x0,x1};
           unsigned short int randomX=rand()%2;
           if(x[randomX]==x0){
               unsigned short int y1=it->second.second-1;
               unsigned short int y2=it->second.second+1;
               unsigned short int y[2]={y1,y2};
               unsigned short int randomY=rand()%2;
               tpair posizione=std::pair<unsigned short int, unsigned short int>(x0,y[randomY]);
               std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
               caselleNave.insert(a);
           }else{
               tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
               std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
               caselleNave.insert(a);
           }
       }else{
           if(it->second.first<9 && it->second.second==9){
               unsigned short int y0=it->second.second;
               unsigned short int y1=it->second.second-1;
               unsigned short int y[2]={y0,y1};
               unsigned short int randomY=rand()%2;
               if(y[randomY]==y0){
                   unsigned short int x1=it->second.first-1;
                   unsigned short int x2=it->second.first+1;
                   unsigned short int x[2]={x1,x2};
                   unsigned short int randomX=rand()%2;
                   tpair posizione=std::pair<unsigned short int, unsigned short int>(x[randomX],y0);
                   std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                   caselleNave.insert(a);
               }else{
                   tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y1);
                   std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                   caselleNave.insert(a);
               }
           }else{
               unsigned short int x0=(it->second.first)-1;
               unsigned short int x2=(it->second.first)+1;
               unsigned short int y0=(it->second.second)-1;
               unsigned short int y2=(it->second.second)+1;
               unsigned short int x[3]={x0,it->second.first,x2};
               unsigned short int y[3]={y0,it->second.second,y2};

               unsigned short int randomX=rand() % 3;
               unsigned short int randomY=rand() % 3;
               while(!((x[randomX]==x0 && y[randomY]==y[1]) || (x[randomX]==x[1] && y[randomY]==y0) || (x[randomX]==x[1] && y[randomY]==y2) || (x[randomX]==x2 && y[randomY]==y[1]))){
                        randomX=rand() % 3;
                        randomY=rand() % 3;
               }
               tpair posizione=std::pair<unsigned short int, unsigned short int>(x[randomX],y[randomY]);
               std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
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
            if(it->second.first==it2->second.first){
                if((it->second.first==0 && it->second.second==0) || (it2->second.first==0 && it2->second.second==0)){
                    if(it->second.second<it2->second.second){
                        unsigned short int y1=it2->second.second+1;
                        tpair posizione=std::pair<unsigned short int, unsigned short int>(it2->second.first,y1);
                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                        caselleNave.insert(a);
                    }else{
                        unsigned short int y1=it->second.second+1;
                        tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y1);
                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                        caselleNave.insert(a);
                    }
                }else{
                    if((it->second.first==0 && it->second.second==9) || (it2->second.first==0 && it2->second.second==9)){
                        if(it->second.second<it2->second.second){
                            unsigned short int y1=it->second.second-1;
                            tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y1);
                            std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                            caselleNave.insert(a);
                        }else{
                            unsigned short int y1=it2->second.second-1;
                            tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y1);
                            std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                            caselleNave.insert(a);
                        }
                    }else{
                        if((it->second.first==9 && it->second.second==0) || (it2->second.first==9 && it2->second.second==0)){
                            if(it->second.second<it2->second.second){
                                unsigned short int y1=it2->second.second+1;
                                tpair posizione=std::pair<unsigned short int, unsigned short int>(it2->second.first,y1);
                                std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                caselleNave.insert(a);
                            }else{
                                unsigned short int y1=it->second.second+1;
                                tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y1);
                                std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                caselleNave.insert(a);
                            }
                        }else{
                            if((it->second.first==9 && it->second.second==9) || (it2->second.first==9 && it2->second.second==9)){
                                if(it->second.second<it2->second.second){
                                    unsigned short int y1=it->second.second-1;
                                    tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y1);
                                    std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }else{
                                    unsigned short int y1=it2->second.second-1;
                                    tpair posizione=std::pair<unsigned short int, unsigned short int>(it2->second.first,y1);
                                    std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }
                            }else{
                                if((it->second.first>0 && it->second.first<9 && it->second.second==0)||(it2->second.first>0 && it2->second.first<9 && it2->second.second==0)){
                                    if(it->second.second<it2->second.second){
                                        unsigned short int y1=it2->second.second+1;
                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(it2->second.first,y1);
                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }else{
                                        unsigned short int y1=it->second.second+1;
                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y1);
                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }
                                }else{
                                    if((it->second.first>0 && it->second.first<9 && it->second.second==9) || (it2->second.first>0 && it2->second.first<9 && it2->second.second==9)){
                                        if(it->second.second<it2->second.second){
                                            unsigned short int y1=it->second.second-1;
                                            tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y1);
                                            std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }else{
                                            unsigned short int y1=it2->second.second-1;
                                            tpair posizione=std::pair<unsigned short int, unsigned short int>(it2->second.first,y1);
                                            std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }
                                    }else{
                                    if(it->second.second<it2->second.second){
                                        unsigned short int y1=it->second.second-1;
                                        unsigned short int y2=it2->second.second +1;
                                        unsigned short int y[2]={y1,y2};

                                        unsigned short int random=rand() % 2;
                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y[random]);
                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }else{
                                        unsigned short int y1=it2->second.second-1;
                                        unsigned short int y2=it->second.second +1;

                                        unsigned short int y[2]={y1,y2};

                                        unsigned short int random=rand() % 2;
                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(it->second.first,y[random]);
                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }
                                }
                            }
                        }
                    }
                }
            }
                    }else{
                        if(it->second.second==it2->second.second){
                            if((it->second.first==0 && it->second.second==0) || (it2->second.first==0 && it2->second.second==0)){
                                if(it->second.first<it2->second.first){
                                    unsigned short int x1=it2->second.first+1;
                                    tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                    std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }else{
                                    unsigned short int x1=it->second.first+1;
                                    tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                    std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                    caselleNave.insert(a);
                                }
                            }else{
                                if((it->second.first==0 && it->second.second==9) || (it2->second.first==0 && it2->second.second==9)){
                                    if(it->second.first<it2->second.first){
                                        unsigned short int x1=it2->second.first+1;
                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }else{
                                        unsigned short int x1=it->second.first+1;
                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                        caselleNave.insert(a);
                                    }
                                }else{
                                    if((it->second.first==9 && it->second.second==0) || (it2->second.first==9 && it2->second.second==0)){
                                        if(it->second.first<it->second.first){
                                            unsigned short int x1=it->second.first-1;
                                            tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                            std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }else{
                                            unsigned short int x1=it2->second.first-1;
                                            tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it2->second.second);
                                            std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                            caselleNave.insert(a);
                                        }
                                    }else{
                                        if((it->second.first==9 && it->second.second==9) || (it2->second.first==9 && it2->second.second==9)){
                                            if(it->second.first<it2->second.first){
                                                unsigned short int x1=it->second.first-1;
                                                tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                                std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                                caselleNave.insert(a);
                                            }else{
                                                unsigned short int x1=it2->second.first-1;
                                                tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                                std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                                caselleNave.insert(a);
                                            }
                                        }else{
                                            if((it->second.first==0 && it->second.second>0 && it->second.second<9) || (it2->second.first==0 && it2->second.second>0 && it2->second.second<9)){
                                                if(it->second.first<it2->second.first){
                                                    unsigned short int x1=it2->second.first+1;
                                                    tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                                    std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                                    caselleNave.insert(a);
                                                }else{
                                                    unsigned short int x1=it->second.first+1;
                                                    tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                                    std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                                    caselleNave.insert(a);
                                                }
                                            }else{
                                                if((it->second.first==9 && it->second.second>0 && it->second.second<9) || (it2->second.first==9 && it2->second.second>0 && it2->second.second<9)){
                                                    if(it->second.first<it2->second.first){
                                                        unsigned short int x1=it->second.first-1;
                                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                                        caselleNave.insert(a);
                                                    }else{
                                                        unsigned short int x1=it2->second.first-1;
                                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(x1,it->second.second);
                                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                                        caselleNave.insert(a);
                                                    }
                                                }else{
                                                    if(it->second.first<it2->second.first){
                                                        unsigned short int x1=(it->second.first)-1;
                                                        unsigned short int x2=(it2->second.first)+1;
                                                        unsigned short int x[2]={x1,x2};
                                                        unsigned short int random=rand() % 2;

                                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(x[random],it->second.second);
                                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                                                        caselleNave.insert(a);
                                                    }else{
                                                        unsigned short int x1=(it2->second.first)-1;
                                                        unsigned short int x2=(it->second.first)+1;

                                                        unsigned short int x[2]={x1,x2};
                                                        unsigned short int random=rand() % 2;

                                                        tpair posizione=std::pair<unsigned short int, unsigned short int>(x[random],it->second.second);
                                                        std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
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
    std::map<unsigned short int,tpair>::iterator it=caselleNave.end();
    it--;
    return (((it->second.first)*10)+it->second.second);
}



bool Nave::colpita(unsigned short X, unsigned short Y)
{
    for(std::map<unsigned short int,tpair>::iterator it=caselleNave.begin();it!=caselleNave.end();it++){
        if(it->second.first==X && it->second.second==Y){
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
