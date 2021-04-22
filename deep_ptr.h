#ifndef DEEP_PTR_H
#define DEEP_PTR_H


template <class T>
class SharedPtr;  // Dichiarazione incompleta

template <class T>
bool operator==(const SharedPtr<T>& left, const SharedPtr<T>& right);  // Dichiarazione incompleta

template <class T>
bool operator!=(const SharedPtr<T>& left, const SharedPtr<T>& right);  // Dichiarazione incompleta

template <class T, class... Args>
SharedPtr<T> make_shared(Args&&... args);

template <class T>
class SharedPtr {
    friend bool operator==<T>(const SharedPtr& left, const SharedPtr& right);
    friend bool operator!=<T>(const SharedPtr& left, const SharedPtr& right);

   private:
    T* _ptr;
    unsigned short int* _counter;

   public:
    SharedPtr(T* ptr = nullptr);
    SharedPtr(const SharedPtr<T>& SharedPtr);

    SharedPtr<T>& operator=(const SharedPtr<T>& SharedPtr);
    void swap(SharedPtr<T>& SharedPtr);

    operator bool() const;

    T* get();
    T& operator*();
    T* operator->();
    T& operator[](unsigned short int index);

    const T* get() const;
    const T& operator*() const;
    const T* operator->() const;
    const T& operator[](unsigned short int index) const;

    void reset(T* ptr = nullptr);

    unsigned short int use_count() const;

    ~SharedPtr();
};

#endif // DEEP_PTR_H
