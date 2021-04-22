#ifndef CONTENITORE_H
#define CONTENITORE_H
#include "deep_ptr.h"
#include "cella.h"

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
    void clear();
    bool empty();
    T* begin(); //indica il primo elemento del contenitore
    T* end();
    void erase (T*&);
//    void push_front(const T&);
};

#endif // CONTENITORE_H
