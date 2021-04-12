#ifndef DEEP_PTR_H
#define DEEP_PTR_H

template <class T>
class deep_ptr
{
protected:
    T info;
    deep_ptr* next;
public:
    deep_ptr(const T&, deep_ptr*);
};

#endif // DEEP_PTR_H
