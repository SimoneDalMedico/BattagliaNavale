#ifndef DEEP_PTR_H
#define DEEP_PTR_H


template <class T>
class deep_ptr;  // Dichiarazione incompleta

template <class T>
bool operator==(const deep_ptr<T>& left, const deep_ptr<T>& right);  // Dichiarazione incompleta

template <class T>
bool operator!=(const deep_ptr<T>& left, const deep_ptr<T>& right);  // Dichiarazione incompleta

template <class T, class... Args>
deep_ptr<T> make_shared(Args&&... args);

template <class T>
class deep_ptr {
    friend bool operator==<T>(const deep_ptr& left, const deep_ptr& right);
    friend bool operator!=<T>(const deep_ptr& left, const deep_ptr& right);

   private:
    T* _ptr;
    unsigned short int* _counter;

   public:
    deep_ptr(T* ptr = nullptr);
    deep_ptr(const deep_ptr<T>& deep_ptr);

    deep_ptr<T>& operator=(const deep_ptr<T>& deep_ptr);
    void swap(deep_ptr<T>& deep_ptr);

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

    ~deep_ptr();
};

#endif // DEEP_PTR_H
