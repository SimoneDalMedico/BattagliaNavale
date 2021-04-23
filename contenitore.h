#ifndef CONTENITORE_H
#define CONTENITORE_H
#include <stdexcept>


template <class T>
class contenitore {
   private:
    class Node {
       public:
        T _info;
        Node *_prev, *_next;

        Node(const T& info, Node* prev = nullptr, Node* next = nullptr);
        ~Node();
    };

    Node *_first, *_last;
    unsigned short int _size;

    static Node* ricCopy(Node* from, Node* prev, Node*& last);
    static Node* ricGet(Node* from, unsigned short int index, unsigned short int size);
    static Node* ricFind(Node* from, const T& find);
    static void ricFindAll(Node* from, const T& find, contenitore<T*>* list);

   public:
    contenitore();
    contenitore(const contenitore<T>& list);
    contenitore<T>& operator=(const contenitore<T>& list);

    void pushBack(const T& info);
    void insert(const T& info, unsigned short int index);
    void pushTop(const T& info);

    void popTop();
    void erase(unsigned short int index);
    void erase(const T& info);
    void popBack();

    T* find(const T& info);
    const T* find(const T& info) const;

    contenitore<T*>& findAll(const T& info);
    const contenitore<T*>& findAll(const T& info) const;

    T& operator[](unsigned short int index);
    const T& operator[](unsigned short int index) const;

    unsigned short int indexOf(const T& info) const;

    unsigned short int size() const;

    ~contenitore();

    class constIterator;

    class iterator {
        friend class contenitore<T>;
        friend class constIterator;

       private:
        Node* _ptr;
        bool _pastTheEnd;

        iterator(Node* n, bool pastTheEnd = false);

       public:
        iterator();

        T& operator*() const;

        T* operator->() const;

        iterator& operator++();

        iterator& operator--();

        bool operator==(const iterator& x) const;

        bool operator!=(const iterator& x) const;
    };

    class constIterator {
        friend class contenitore<T>;

       private:
        iterator _it;

        constIterator(Node* n, bool pastTheEnd = false);

       public:
        constIterator();
        constIterator(const iterator& it);  // convert iterator in constIterator

        const T& operator*() const;

        const T* operator->() const;

        constIterator& operator++();

        constIterator& operator--();

        bool operator==(const constIterator& x) const;

        bool operator!=(const constIterator& x) const;
    };

    // Se MyList<...> c; => begin, end, cbegin, cend disponibili
    // Se const MyList<...> c => solo cend, cbegin.

    iterator begin();
    iterator end();

    constIterator cbegin() const;
    constIterator cend() const;
};

#endif // CONTENITORE_H
