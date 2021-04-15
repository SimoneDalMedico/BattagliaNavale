#ifndef DEEP_PTR_H
#define DEEP_PTR_H

template <class T>
class deep_ptr
{

protected:
    //da vedere se insere info e next in protect
public:
    T info;
    deep_ptr* next;
    deep_ptr(const T&, deep_ptr* =nullptr);
};

#endif // DEEP_PTR_H
