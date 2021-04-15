#include "nave.h"

void Nave::reset()
{
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
    deep_ptr<cella>* it=caselleNave.begin();
    deep_ptr<cella>* it2=caselleNave.end();
    it2--;
        if(caselleNave.size()==1){
            if((x==(it2->info.ShowX())-1 && y==it2->info.ShowY()) || (x==(it2->info.ShowX())+1 && y==it2->info.ShowY()) || (x==it2->info.ShowX() && y==(it2->info.ShowY())-1) || (x==it2->info.ShowX() && y==(it2->info.ShowY())+1)){
                return true;
            }
        }else{
            if(it->info.ShowX()==it2->info.ShowX() && x==it2->info.ShowX() && (y==(it2->info.ShowY())+1 || y==(it2->info.ShowY())-1)){
                return true;
            }
            if(it->info.ShowY()==it2->info.ShowY() && y==it2->info.ShowY() && (x==(it2->info.ShowX())+1 || x==(it2->info.ShowX())-1)){
                return true;
            }
        }
    }
    return false;
}

void Nave::Posizionamentocomputer()
{

    deep_ptr<cella>* it=caselleNave.begin();
    deep_ptr<cella>* it2=caselleNave.end();
    it2--;
    if(it->info.ShowX()==it2->info.ShowX() && counter()==1){
if(it->info.ShowX()==0 && it->info.ShowY()==9){
            unsigned short int x0=(it->info.ShowX());
            unsigned short int x1=(it->info.ShowX())+1;
            unsigned short int y0=(it->info.ShowY());
            unsigned short int y1=(it->info.ShowY())-1;
            unsigned short int x[2]={x0,x1};
            unsigned short int randomX=rand() % 2;
            if(x[randomX]==x0){
                cella nuova(x0,y1);
                deep_ptr<cella> posizione(nuova);
//                std::map<int,tpair>::value_type a(caselleNave.size()+1 ,posizione);
                caselleNave.insert(posizione);
            }else{
                cella nuova(x1,y0);
                deep_ptr<cella> posizione(nuova);
                caselleNave.insert(posizione);
            }
}else{
if(it->info.ShowX()==9 && it->info.ShowY()==0){
    unsigned short int x0=(it->info.ShowX());
    unsigned short int x1=(it->info.ShowX())-1;
    unsigned short int y0=(it->info.ShowY());
    unsigned short int y1=(it->info.ShowY())+1;
    unsigned short int x[2]={x0,x1};
    unsigned short int randomX=rand() % 2;
    if(x[randomX]==x0){
        cella nuova(x0,y1);
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }else{
        cella nuova(x1,y0);
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}else{
if(it->info.ShowX()==0 && it->info.ShowY()<9 && it->info.ShowY()>0){
            unsigned short int x0=(it->info.ShowX());
            unsigned short int x1=(it->info.ShowX())+1;

            unsigned short int x[2]={x0,x1};
            unsigned short int randomX=rand() % 2;
            if(x[randomX]==x0){
                unsigned short int y0=(it->info.ShowY())-1;
                unsigned short int y1=(it->info.ShowY())+1;
                unsigned short int y[2]={y0,y1};
                unsigned short int randomY=rand() % 2;
                cella nuova(x0,y[randomY]);
                deep_ptr<cella> posizione(nuova);
                caselleNave.insert(posizione);
            }else{
                cella nuova(x1,it->info.ShowY());
                deep_ptr<cella> posizione(nuova);
                caselleNave.insert(posizione);
            }

}else{
if(it->info.ShowX()<9 && it->info.ShowY()==0 && it->info.ShowX()>0){
    unsigned short int y0=(it->info.ShowY());
    unsigned short int y1=(it->info.ShowY())+1;
    unsigned short int y[2]={y0,y1};
    unsigned short int randomY=rand() % 2;
    if(y[randomY]==y0){
        unsigned short int x0=(it->info.ShowX())-1;
        unsigned short int x1=(it->info.ShowX())+1;
        unsigned short int x[2]={x0,x1};
        unsigned short int randomX=rand() % 2;
        cella nuova(x[randomX],y0);
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }else{
        cella nuova(it->info.ShowX(),y1);
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}else{
if(it->info.ShowX()==0 && it->info.ShowY()==0){
    unsigned short int x0=(it->info.ShowX());
    unsigned short int x1=(it->info.ShowX())+1;
    unsigned short int x[2]={x0,x1};
    unsigned short int randomX=rand() % 2;
    if(x[randomX]==x0){
        unsigned short int y1=(it->info.ShowY())+1;
        cella nuova(x0,y1);
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }else{
        cella nuova(x1,it->info.ShowY());
        deep_ptr<cella> posizione(nuova);
        caselleNave.insert(posizione);
    }
}else{
   if(it->info.ShowX()==9 && it->info.ShowY()==9){
       unsigned short int x0=(it->info.ShowX());
       unsigned short int x1=(it->info.ShowX())-1;
       unsigned short int x[2]={x0,x1};
       unsigned short int randomX=rand() % 2;
       if(x[randomX]==x0){
           unsigned short int y1=(it->info.ShowY())-1;
           cella nuova(x0,y1);
           deep_ptr<cella> posizione(nuova);
           caselleNave.insert(posizione);
       }else{
           cella nuova(x1,it->info.ShowY());
           deep_ptr<cella> posizione(nuova);
           caselleNave.insert(posizione);
       }
   } else{
       if(it->info.ShowX()==9 && it->info.ShowY()<9 && it->info.ShowY()>0){
           unsigned short int x0=it->info.ShowX();
           unsigned short int x1=it->info.ShowX()-1;
           unsigned short int x[2]={x0,x1};
           unsigned short int randomX=rand()%2;
           if(x[randomX]==x0){
               unsigned short int y1=it->info.ShowY()-1;
               unsigned short int y2=it->info.ShowY()+1;
               unsigned short int y[2]={y1,y2};
               unsigned short int randomY=rand()%2;
               cella nuova(x0,y[randomY]);
               deep_ptr<cella> posizione(nuova);
               caselleNave.insert(posizione);
           }else{
               cella nuova(x1,it->info.ShowY());
               deep_ptr<cella> posizione(nuova);
               caselleNave.insert(posizione);
           }
       }else{
           if(it->info.ShowX()<9 && it->info.ShowY()==9){
               unsigned short int y0=it->info.ShowY();
               unsigned short int y1=it->info.ShowY()-1;
               unsigned short int y[2]={y0,y1};
               unsigned short int randomY=rand()%2;
               if(y[randomY]==y0){
                   unsigned short int x1=it->info.ShowX()-1;
                   unsigned short int x2=it->info.ShowX()+1;
                   unsigned short int x[2]={x1,x2};
                   unsigned short int randomX=rand()%2;
                   cella nuova(x[randomX],y0);
                   deep_ptr<cella> posizione(nuova);
                   caselleNave.insert(posizione);
               }else{
                   cella nuova(it->info.ShowX(),y0);
                   deep_ptr<cella> posizione(nuova);
                   caselleNave.insert(posizione);
               }
           }else{
               unsigned short int x0=(it->info.ShowX())-1;
               unsigned short int x2=(it->info.ShowX())+1;
               unsigned short int y0=(it->info.ShowY())-1;
               unsigned short int y2=(it->info.ShowY())+1;
               unsigned short int x[3]={x0,it->info.ShowX(),x2};
               unsigned short int y[3]={y0,it->info.ShowY(),y2};

               unsigned short int randomX=rand() % 3;
               unsigned short int randomY=rand() % 3;
               while(!((x[randomX]==x0 && y[randomY]==y[1]) || (x[randomX]==x[1] && y[randomY]==y0) || (x[randomX]==x[1] && y[randomY]==y2) || (x[randomX]==x2 && y[randomY]==y[1]))){
                        randomX=rand() % 3;
                        randomY=rand() % 3;
               }
               cella nuova(x[randomX],y[randomY]);
               deep_ptr<cella> posizione(nuova);
               caselleNave.insert(posizione);
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
            if(it->info.ShowX()==it2->info.ShowX()){
                if((it->info.ShowX()==0 && it->info.ShowY()==0) || (it2->info.ShowX()==0 && it2->info.ShowY()==0)){
                    if(it->info.ShowY()<it2->info.ShowY()){
                        unsigned short int y1=it2->info.ShowY()+1;
                        cella nuova(it2->info.ShowX(),y1);
                        deep_ptr<cella> posizione(nuova);
                        caselleNave.insert(posizione);
                    }else{
                        unsigned short int y1=it->info.ShowY()+1;
                        cella nuova(it->info.ShowX(),y1);
                        deep_ptr<cella> posizione(nuova);
                        caselleNave.insert(posizione);
                    }
                }else{
                    if((it->info.ShowX()==0 && it->info.ShowY()==9) || (it2->info.ShowX()==0 && it2->info.ShowY()==9)){
                        if(it->info.ShowY()<it2->info.ShowY()){
                            unsigned short int y1=it->info.ShowY()-1;
                            cella nuova(it->info.ShowX(),y1);
                            deep_ptr<cella> posizione(nuova);
                            caselleNave.insert(posizione);
                        }else{
                            unsigned short int y1=it2->info.ShowY()-1;
                            cella nuova(it->info.ShowX(),y1);
                            deep_ptr<cella> posizione(nuova);
                            caselleNave.insert(posizione);
                        }
                    }else{
                        if((it->info.ShowX()==9 && it->info.ShowY()==0) || (it2->info.ShowX()==9 && it2->info.ShowY()==0)){
                            if(it->info.ShowY()<it2->info.ShowY()){
                                unsigned short int y1=it2->info.ShowY()+1;
                                cella nuova(it2->info.ShowX(),y1);
                                deep_ptr<cella> posizione(nuova);
                                caselleNave.insert(posizione);
                            }else{
                                unsigned short int y1=it->info.ShowY()+1;
                                cella nuova(it->info.ShowX(),y1);
                                deep_ptr<cella> posizione(nuova);
                                caselleNave.insert(posizione);
                            }
                        }else{
                            if((it->info.ShowX()==9 && it->info.ShowY()==9) || (it2->info.ShowX()==9 && it2->info.ShowY()==9)){
                                if(it->info.ShowY()<it2->info.ShowY()){
                                    unsigned short int y1=it->info.ShowY()-1;
                                    cella nuova(it->info.ShowX(),y1);
                                    deep_ptr<cella> posizione(nuova);
                                    caselleNave.insert(posizione);
                                }else{
                                    unsigned short int y1=it2->info.ShowY()-1;
                                    cella nuova(it2->info.ShowX(),y1);
                                    deep_ptr<cella> posizione(nuova);
                                    caselleNave.insert(posizione);
                                }
                            }else{
                                if((it->info.ShowX()>0 && it->info.ShowX()<9 && it->info.ShowY()==0)||(it2->info.ShowX()>0 && it2->info.ShowX()<9 && it2->info.ShowY()==0)){
                                    if(it->info.ShowY()<it2->info.ShowY()){
                                        unsigned short int y1=it2->info.ShowY()+1;
                                        cella nuova(it2->info.ShowX(),y1);
                                        deep_ptr<cella> posizione(nuova);
                                        caselleNave.insert(posizione);
                                    }else{
                                        unsigned short int y1=it->info.ShowY()+1;
                                        cella nuova(it->info.ShowX(),y1);
                                        deep_ptr<cella> posizione(nuova);
                                        caselleNave.insert(posizione);
                                    }
                                }else{
                                    if((it->info.ShowX()>0 && it->info.ShowX()<9 && it->info.ShowY()==9) || (it2->info.ShowX()>0 && it2->info.ShowX()<9 && it2->info.ShowY()==9)){
                                        if(it->info.ShowY()<it2->info.ShowY()){
                                            unsigned short int y1=it->info.ShowY()-1;
                                            cella nuova(it->info.ShowX(),y1);
                                            deep_ptr<cella> posizione(nuova);
                                            caselleNave.insert(posizione);
                                        }else{
                                            unsigned short int y1=it2->info.ShowY()-1;
                                            cella nuova(it2->info.ShowX(),y1);
                                            deep_ptr<cella> posizione(nuova);
                                            caselleNave.insert(posizione);
                                        }
                                    }else{
                                    if(it->info.ShowY()<it2->info.ShowY()){
                                        unsigned short int y1=it->info.ShowY()-1;
                                        unsigned short int y2=it2->info.ShowY() +1;
                                        unsigned short int y[2]={y1,y2};

                                        unsigned short int random=rand() % 2;
                                        cella nuova(it->info.ShowX(),y[random]);
                                        deep_ptr<cella> posizione(nuova);
                                        caselleNave.insert(posizione);
                                    }else{
                                        unsigned short int y1=it2->info.ShowY()-1;
                                        unsigned short int y2=it->info.ShowY() +1;

                                        unsigned short int y[2]={y1,y2};

                                        unsigned short int random=rand() % 2;
                                        cella nuova(it->info.ShowX(),y[random]);
                                        deep_ptr<cella> posizione(nuova);
                                        caselleNave.insert(posizione);
                                    }
                                }
                            }
                        }
                    }
                }
            }
                    }else{
                        if(it->info.ShowY()==it2->info.ShowY()){
                            if((it->info.ShowX()==0 && it->info.ShowY()==0) || (it2->info.ShowX()==0 && it2->info.ShowY()==0)){
                                if(it->info.ShowX()<it2->info.ShowX()){
                                    unsigned short int x1=it2->info.ShowX()+1;
                                    cella nuova(x1,it->info.ShowY());
                                    deep_ptr<cella> posizione(nuova);
                                    caselleNave.insert(posizione);
                                }else{
                                    unsigned short int x1=it->info.ShowX()+1;
                                    cella nuova(x1,it->info.ShowY());
                                    deep_ptr<cella> posizione(nuova);
                                    caselleNave.insert(posizione);
                                }
                            }else{
                                if((it->info.ShowX()==0 && it->info.ShowY()==9) || (it2->info.ShowX()==0 && it2->info.ShowY()==9)){
                                    if(it->info.ShowX()<it2->info.ShowX()){
                                        unsigned short int x1=it2->info.ShowX()+1;

                                        cella nuova(x1,it->info.ShowY());
                                        deep_ptr<cella> posizione(nuova);
                                        caselleNave.insert(posizione);

                                    }else{
                                        unsigned short int x1=it->info.ShowX()+1;
                                        cella nuova(x1,it->info.ShowY());
                                        deep_ptr<cella> posizione(nuova);
                                        caselleNave.insert(posizione);

                                    }
                                }else{
                                    if((it->info.ShowX()==9 && it->info.ShowY()==0) || (it2->info.ShowX()==9 && it2->info.ShowY()==0)){
                                        if(it->info.ShowX()<it->info.ShowX()){
                                            unsigned short int x1=it->info.ShowX()-1;
                                            cella nuova(x1,it->info.ShowY());
                                            deep_ptr<cella> posizione(nuova);
                                            caselleNave.insert(posizione);

                                        }else{
                                            unsigned short int x1=it2->info.ShowX()-1;
                                            cella nuova(x1,it2->info.ShowY());
                                            deep_ptr<cella> posizione(nuova);
                                            caselleNave.insert(posizione);

                                        }
                                    }else{
                                        if((it->info.ShowX()==9 && it->info.ShowY()==9) || (it2->info.ShowX()==9 && it2->info.ShowY()==9)){
                                            if(it->info.ShowX()<it2->info.ShowX()){
                                                unsigned short int x1=it->info.ShowX()-1;
                                                cella nuova(x1,it->info.ShowY());
                                                deep_ptr<cella> posizione(nuova);
                                                caselleNave.insert(posizione);

                                            }else{
                                                unsigned short int x1=it2->info.ShowX()-1;
                                                cella nuova(x1,it->info.ShowY());
                                                deep_ptr<cella> posizione(nuova);
                                                caselleNave.insert(posizione);

                                            }
                                        }else{
                                            if((it->info.ShowX()==0 && it->info.ShowY()>0 && it->info.ShowY()<9) || (it2->info.ShowX()==0 && it2->info.ShowY()>0 && it2->info.ShowY()<9)){
                                                if(it->info.ShowX()<it2->info.ShowX()){
                                                    unsigned short int x1=it2->info.ShowX()+1;
                                                    cella nuova(x1,it->info.ShowY());
                                                    deep_ptr<cella> posizione(nuova);
                                                    caselleNave.insert(posizione);

                                                }else{
                                                    unsigned short int x1=it->info.ShowX()+1;
                                                    cella nuova(x1,it->info.ShowY());
                                                    deep_ptr<cella> posizione(nuova);
                                                    caselleNave.insert(posizione);

                                                }
                                            }else{
                                                if((it->info.ShowX()==9 && it->info.ShowY()>0 && it->info.ShowY()<9) || (it2->info.ShowX()==9 && it2->info.ShowY()>0 && it2->info.ShowY()<9)){
                                                    if(it->info.ShowX()<it2->info.ShowX()){
                                                        unsigned short int x1=it->info.ShowX()-1;
                                                        cella nuova(x1,it->info.ShowY());
                                                        deep_ptr<cella> posizione(nuova);
                                                        caselleNave.insert(posizione);

                                                    }else{
                                                        unsigned short int x1=it2->info.ShowX()-1;
                                                        cella nuova(x1,it->info.ShowY());
                                                        deep_ptr<cella> posizione(nuova);
                                                        caselleNave.insert(posizione);

                                                    }
                                                }else{
                                                    if(it->info.ShowX()<it2->info.ShowX()){
                                                        unsigned short int x1=(it->info.ShowX())-1;
                                                        unsigned short int x2=(it2->info.ShowX())+1;
                                                        unsigned short int x[2]={x1,x2};
                                                        unsigned short int random=rand() % 2;
                                                        cella nuova(x[random],it->info.ShowY());
                                                        deep_ptr<cella> posizione(nuova);
                                                        caselleNave.insert(posizione);
                                                    }else{
                                                        unsigned short int x1=(it2->info.ShowX())-1;
                                                        unsigned short int x2=(it->info.ShowX())+1;

                                                        unsigned short int x[2]={x1,x2};
                                                        unsigned short int random=rand() % 2;
                                                        cella nuova(x[random],it->info.ShowY());
                                                        deep_ptr<cella> posizione(nuova);
                                                        caselleNave.insert(posizione);
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
    deep_ptr<cella>* it=caselleNave.end();
    it--; //attenzione!!! qui si va in dietro!
    return (((it->info.ShowX())*10)+it->info.ShowY());
}



bool Nave::colpita(unsigned short X, unsigned short Y)
{
    for(deep_ptr<cella>* it=caselleNave.begin();it!=nullptr;it=it->next){
        if(it->info.ShowX()==X && it->info.ShowY()==Y){
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
