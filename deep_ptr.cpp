#include "deep_ptr.h"

template <class T>
bool operator==(const deep_ptr<T>& left, const deep_ptr<T>& right) {
    return left._ptr == right._ptr;
}

template <class T>
bool operator!=(const deep_ptr<T>& left, const deep_ptr<T>& right) {
    return left._ptr != right._ptr;
}

template <class T>
deep_ptr<T>::deep_ptr(T* ptr) : _ptr(ptr), _counter(ptr ? new unsigned short int(1) : new unsigned short int(0)) {}

template <class T>
deep_ptr<T>::deep_ptr(const deep_ptr<T>& deep_ptr) : _ptr(deep_ptr._ptr), _counter(deep_ptr._counter) {
    if (_ptr != nullptr) {
        (*_counter)++;
    } else {
        _counter = new unsigned short int(0);
    }
}

template <class T>
deep_ptr<T>& deep_ptr<T>::operator=(const deep_ptr<T>& deep_ptr) {
    if (this != &deep_ptr) {
        if (*_counter > 0) {
            (*_counter)--;
        }

        if (*_counter <= 0) {
            delete _ptr;
            delete _counter;
            _ptr = nullptr;
            _counter = nullptr;
        }

        _ptr = deep_ptr._ptr;
        _counter = deep_ptr._counter;

        if (_ptr != nullptr) {
            (*_counter)++;
        } else {
            _counter = new unsigned short int(0);
        }
    }
    return *this;
}

template <class T>
void deep_ptr<T>::swap(deep_ptr<T>& deep_ptr) {
    T* temp = _ptr;
    unsigned short int* tempCount = _counter;

    _ptr = deep_ptr._ptr;
    deep_ptr._ptr = temp;

    _counter = deep_ptr._counter;
    deep_ptr._counter = tempCount;
}

template <class T>
deep_ptr<T>::operator bool() const {
    return _ptr != nullptr;
}

template <class T>
T* deep_ptr<T>::get() {
    return _ptr;
}

template <class T>
T& deep_ptr<T>::operator*() {
    return *_ptr;
}

template <class T>
T* deep_ptr<T>::operator->() {
    return _ptr;
}

template <class T>
T& deep_ptr<T>::operator[](unsigned short int index) {
    return _ptr[index];
}

template <class T>
const T* deep_ptr<T>::get() const {
    return _ptr;
}

template <class T>
const T& deep_ptr<T>::operator*() const {
    return *_ptr;
}

template <class T>
const T* deep_ptr<T>::operator->() const {
    return _ptr;
}

template <class T>
const T& deep_ptr<T>::operator[](unsigned short int index) const {
    return _ptr[index];
}

template <class T>
void deep_ptr<T>::reset(T* ptr) {
    if (*_counter > 0) {
        (*_counter)--;
    }
    if (*_counter <= 0) {
        delete _ptr;
        delete _counter;
        _ptr = nullptr;
        _counter = nullptr;
    }
    _ptr = ptr;
    _counter = ptr ? new unsigned short int(1) : new unsigned short int(0);
}

template <class T>
unsigned short int deep_ptr<T>::use_count() const {
    return (_counter ? *_counter : 0);
}

template <class T>
deep_ptr<T>::~deep_ptr() {
    if (*_counter > 0) {
        (*_counter)--;
    }
    if (*_counter <= 0) {
        delete _ptr;
        delete _counter;
        _ptr = nullptr;
        _counter = nullptr;
    }
}

template <class T, class... Args>
deep_ptr<T> make_shared(Args&&... args) {
    return deep_ptr<T>(new T(args...));
}
