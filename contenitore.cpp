#include "contenitore.h"

template <class T>
contenitore<T>::Node::Node(const T& info, Node* prev, Node* next) : _info(info), _prev(prev), _next(next) {}

template <class T>
contenitore<T>::Node::~Node() {
    delete _next;
}

template <class T>
contenitore<T>::contenitore() : _first(nullptr), _last(nullptr), _size(0) {}

template <class T>
typename contenitore<T>::Node* contenitore<T>::ricCopy(Node* from, Node* prev, Node*& last) {
    if (from == nullptr) {
        last = prev;
        return nullptr;
    }

    Node* temp = new Node(from->_info);
    temp->_prev = prev;
    temp->_next = ricCopy(from->_next, temp, last);
    return temp;
}

template <class T>
typename contenitore<T>::Node* contenitore<T>::ricGet(Node* from, unsigned short int index, unsigned short int size) {
    if (index < 0 || index > size)
        return nullptr;
    if (index == 0)
        return from;
    return ricGet(from->_next, --index, size);
}

template <class T>
typename contenitore<T>::Node* contenitore<T>::ricFind(Node* from, const T& find) {
    if (from == nullptr)
        return nullptr;
    if (from->_info == find)
        return from;
    return ricFind(from->_next, find);
}

template <class T>
void contenitore<T>::ricFindAll(Node* from, const T& find, contenitore<T*>* lista) {
    Node* temp = ricFind(from, find);
    if (temp != nullptr) {
        lista->pushBack(&temp->_info);
        ricFindAll(temp->_next, find, lista);
    }
}

template <class T>
contenitore<T>::contenitore(const contenitore<T>& list) {
    _first = ricCopy(list._first, _first, _last);
    _size = list._size;
}

template <class T>
contenitore<T>& contenitore<T>::operator=(const contenitore<T>& list) {
    if (this != &list) {
        delete _first;
        _first = ricCopy(list._first, _first, _last);
        _size = list._size;
    }
    return *this;
}

template <class T>
contenitore<T>::~contenitore() {
    delete _first;
}

template <class T>
void contenitore<T>::pushBack(const T& info) {
    if (_size != 0) {
        _last->_next = new Node(info, _last, nullptr);
        _last = _last->_next;
    } else
        _first = _last = new Node(info, nullptr, nullptr);
    _size++;
}

template <class T>
void contenitore<T>::pushTop(const T& info) {
    if (_size != 0) {
        _first->_prev = new Node(info, nullptr, _first);
        _first = _first->_prev;
    } else
        _first = _last = new Node(info, nullptr, nullptr);
    _size++;
}

template <class T>
void contenitore<T>::insert(const T& info, unsigned short int index) {
    if (index == 0)
        pushTop(info);
    else if (index == _size)
        pushBack(info);
    else if (index > 0 && index < _size) {
        Node* temp = ricGet(_first, --index, _size);
        temp->_next = new Node(info, temp, temp->_next);
        temp->_next->_prev = temp;
        _size++;
    } else {
        throw std::out_of_range("Index must be >= 0 and <= of list size");
    }
}

template <class T>
void contenitore<T>::popBack() {
    Node* ultimo = _last;
    _last = _last->_prev;
    _last->_next = nullptr;
    delete ultimo;
    _size--;
}

template <class T>
void contenitore<T>::popTop() {
    Node* primo = _first;
    if (_size == 1) {
        _first = _last = nullptr;
    } else {
        _first = _first->_next;
        _first->_prev = nullptr;
        primo->_next = nullptr;
    }
    delete primo;
    _size--;
}

template <class T>
T& contenitore<T>::operator[](unsigned short int index) {
    return ricGet(_first, index, _size)->_info;
}

template <class T>
const T& contenitore<T>::operator[](unsigned short int index) const {
    return ricGet(_first, index, _size)->_info;
}

template <class T>
void contenitore<T>::erase(unsigned short int index) {
    if (index == 0)
        popTop();
    else if (index == _size)
        popBack();
    else if (index > 0 && index < _size) {
        Node* temp = ricGet(_first, index, _size);
        temp->_prev->_next = temp->_next;
        temp->_next->_prev = temp->_prev;
        temp->_next = temp->_prev = nullptr;
        delete temp;
        _size--;
    }
}

template <class T>
void contenitore<T>::erase(const T& info) {
    Node* del = ricFind(_first, info);
    if (del == _first)
        popTop();
    else if (del == _last)
        popBack();
    else if (del != nullptr) {
        del->_prev->_next = del->_next;
        del->_next->_prev = del->_prev;
        del->_next = del->_prev = nullptr;
        delete del;
        _size--;
    }
}

template <class T>
unsigned short int contenitore<T>::indexOf(const T& info) const {
    unsigned short int index = 0;
    bool trovato = false;
    for (auto i = cbegin(); i != cend() && !trovato; ++i) {
        if (*i == info) {
            trovato = true;
        } else {
            index++;
        }
    }
    return index;  // return _size if not found
}

template <class T>
T* contenitore<T>::find(const T& find) {
    Node* ret = ricFind(_first, find);
    return (ret ? &ret->_info : nullptr);
}

template <class T>
const T* contenitore<T>::find(const T& find) const {
    Node* ret = ricFind(_first, find);
    return (ret ? &ret->_info : nullptr);
}

template <class T>
contenitore<T*>& contenitore<T>::findAll(const T& find) {
    contenitore<T*>* ret = new contenitore<T*>();
    ricFindAll(_first, find, ret);
    return *ret;
}

template <class T>
const contenitore<T*>& contenitore<T>::findAll(const T& find) const {
    contenitore<T*>* ret = new contenitore<T*>();
    ricFindAll(_first, find, ret);
    return *ret;
}

template <class T>
unsigned short int contenitore<T>::size() const {
    return _size;
}

template <class T>
contenitore<T>::iterator::iterator() : _ptr(nullptr), _pastTheEnd(false) {}

template <class T>
contenitore<T>::iterator::iterator(Node* n, bool pastTheEnd) : _ptr(n), _pastTheEnd(pastTheEnd) {}

template <class T>
T& contenitore<T>::iterator::operator*() const {
    return _ptr->_info;
}

template <class T>
T* contenitore<T>::iterator::operator->() const {
    return &(_ptr->_info);
}

template <class T>
typename contenitore<T>::iterator& contenitore<T>::iterator::operator++() {
    if (_ptr != nullptr) {
        if (!_pastTheEnd) {
            if (_ptr->_next == nullptr) {
                _ptr++;
                _pastTheEnd = true;
            } else {
                _ptr = _ptr->_next;
            }
        }
    }
    return *this;
}

template <class T>
typename contenitore<T>::iterator& contenitore<T>::iterator::operator--() {
    if (_ptr != nullptr) {
        if (_pastTheEnd) {
            _ptr--;
            _pastTheEnd = false;
        } else
            _ptr = _ptr->_prev;
    }
    return *this;
}

template <class T>
bool contenitore<T>::iterator::operator==(const iterator& x) const {
    return _ptr == x._ptr;
}

template <class T>
bool contenitore<T>::iterator::operator!=(const iterator& x) const {
    return _ptr != x._ptr;
}

template <class T>
typename contenitore<T>::iterator contenitore<T>::begin() {
    return _first;
}

template <class T>
typename contenitore<T>::iterator contenitore<T>::end() {
    if (_last == nullptr)
        return nullptr;
    return iterator(_last + 1, true);
}

template <class T>
contenitore<T>::constIterator::constIterator() {}

template <class T>
contenitore<T>::constIterator::constIterator(const iterator& it) : _it(it) {}

template <class T>
contenitore<T>::constIterator::constIterator(Node* n, bool pastTheEnd) : _it(n, pastTheEnd) {}

template <class T>
const T& contenitore<T>::constIterator::operator*() const {
    return _it.operator*();
}

template <class T>
const T* contenitore<T>::constIterator::operator->() const {
    return _it.operator->();
}

template <class T>
typename contenitore<T>::constIterator& contenitore<T>::constIterator::operator++() {
    ++_it;
    return *this;
}

template <class T>
typename contenitore<T>::constIterator& contenitore<T>::constIterator::operator--() {
    --_it;
    return *this;
}

template <class T>
bool contenitore<T>::constIterator::operator==(const constIterator& x) const {
    return _it == x._it;
}

template <class T>
bool contenitore<T>::constIterator::operator!=(const constIterator& x) const {
    return _it != x._it;
}

template <class T>
typename contenitore<T>::constIterator contenitore<T>::cbegin() const {
    return _first;
}

template <class T>
typename contenitore<T>::constIterator contenitore<T>::cend() const {
    if (_last == nullptr)
        return nullptr;
    return constIterator(_last + 1, true);
}
