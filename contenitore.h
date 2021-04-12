#ifndef CONTENITORE_H
#define CONTENITORE_H
#include "deep_ptr.h"

template<class T>
class contenitore
{
private:
    T* first;
    T* last;
public:
    contenitore();
    void insert(const T&);
    T* find(const T&);
    unsigned short int size();
//    void push_front(const T&);
};

#endif // CONTENITORE_H
