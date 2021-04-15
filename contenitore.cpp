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

template<class T>
void contenitore<T>::clear()
{
    //da rivedere (fatto copia e incolla)
    deep_ptr<T> *tmp(nullptr), *p(first);
            while(p!=nullptr){
                tmp=p->next;
                delete p;
                p=tmp;
            }
}

template<class T>
bool contenitore<T>::empty()
{
    //restituisce true se è vuoto
    if(first==nullptr){
        return true;
    }
    return false;
}

template<class T>
T *contenitore<T>::begin()
{
    return first;
}

template<class T>
T *contenitore<T>::end()
{
    return last;
}

template<class T>
void contenitore<T>::erase(T* p)
{
    bool stop=true;
    for(deep_ptr<T>* tmp=first; tmp!=nullptr && stop; tmp=tmp->next){
        if(tmp->next->info==p->info){
            tmp->next=p->next;
            p->next=0;
            delete p;
            stop=false;
        }
    }
}






















