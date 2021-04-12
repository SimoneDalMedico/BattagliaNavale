#include "deep_ptr.h"

template<class T>
deep_ptr<T>::deep_ptr(const T& _info, deep_ptr* _next): info(_info), next(_next){}
