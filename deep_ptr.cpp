#include "deep_ptr.h"

template <class T>
bool operator==(const SharedPtr<T>& left, const SharedPtr<T>& right) {
    return left._ptr == right._ptr;
}

template <class T>
bool operator!=(const SharedPtr<T>& left, const SharedPtr<T>& right) {
    return left._ptr != right._ptr;
}

template <class T>
SharedPtr<T>::SharedPtr(T* ptr) : _ptr(ptr), _counter(ptr ? new unsigned short int(1) : new unsigned short int(0)) {}

template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& SharedPtr) : _ptr(SharedPtr._ptr), _counter(SharedPtr._counter) {
    if (_ptr != nullptr) {
        (*_counter)++;
    } else {
        _counter = new unsigned short int(0);
    }
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& SharedPtr) {
    if (this != &SharedPtr) {
        if (*_counter > 0) {
            (*_counter)--;
        }

        if (*_counter <= 0) {
            delete _ptr;
            delete _counter;
            _ptr = nullptr;
            _counter = nullptr;
        }

        _ptr = SharedPtr._ptr;
        _counter = SharedPtr._counter;

        if (_ptr != nullptr) {
            (*_counter)++;
        } else {
            _counter = new unsigned short int(0);
        }
    }
    return *this;
}

template <class T>
void SharedPtr<T>::swap(SharedPtr<T>& SharedPtr) {
    T* temp = _ptr;
    unsigned short int* tempCount = _counter;

    _ptr = SharedPtr._ptr;
    SharedPtr._ptr = temp;

    _counter = SharedPtr._counter;
    SharedPtr._counter = tempCount;
}

template <class T>
SharedPtr<T>::operator bool() const {
    return _ptr != nullptr;
}

template <class T>
T* SharedPtr<T>::get() {
    return _ptr;
}

template <class T>
T& SharedPtr<T>::operator*() {
    return *_ptr;
}

template <class T>
T* SharedPtr<T>::operator->() {
    return _ptr;
}

template <class T>
T& SharedPtr<T>::operator[](unsigned short int index) {
    return _ptr[index];
}

template <class T>
const T* SharedPtr<T>::get() const {
    return _ptr;
}

template <class T>
const T& SharedPtr<T>::operator*() const {
    return *_ptr;
}

template <class T>
const T* SharedPtr<T>::operator->() const {
    return _ptr;
}

template <class T>
const T& SharedPtr<T>::operator[](unsigned short int index) const {
    return _ptr[index];
}

template <class T>
void SharedPtr<T>::reset(T* ptr) {
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
unsigned short int SharedPtr<T>::use_count() const {
    return (_counter ? *_counter : 0);
}

template <class T>
SharedPtr<T>::~SharedPtr() {
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
SharedPtr<T> make_shared(Args&&... args) {
    return SharedPtr<T>(new T(args...));
}
