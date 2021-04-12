#include "contenitore.h"


template<class T>
contenitore<T>::contenitore():first(nullptr), last(nullptr){}

template<class T>
void contenitore<T>::insert(const T& t)
{
    if(last){
               last->next=new deep_ptr<T>(t, last);
               last=last->next;
           }
           else
               last=first=new deep_ptr<T>(t);
}

template<class T>
T *contenitore<T>::find(const T& t)
{
    for(deep_ptr<T>* tmp=first; tmp!=nullptr; tmp=tmp->next){
        if(tmp->info==t->info){
            return true;
        }
    }
    return false;
}

template<class T>
unsigned short contenitore<T>::size()
{
    unsigned short int cont=0;
    for(deep_ptr<T>* tmp=first; tmp!=nullptr; tmp=tmp->next){
        cont++;
    }
    return cont;
}


