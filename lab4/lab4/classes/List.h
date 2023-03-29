
#ifndef List_h
#define List_h
#include <iostream>


template <typename T> class List;


template <typename T>
class Node{
public:
    T data_;
    Node<T>* next_;
    Node<T>* prev_;
    
    Node();
    Node(const T data);
};

template<typename T>
class Iterator{
    //friend class List<T>;
private:
    Node<T>* ptr_;
    
public:
    Iterator();
    Iterator(Node<T>* ptr);
    Iterator(const Iterator<T>& it);
    Node<T>* getPtr();
    T& operator* ();
    Iterator<T>& operator ++();
    Iterator<T>& operator --();
    Iterator<T> operator ++(int);
    Iterator<T> operator --(int);
    const bool operator ==(const Iterator<T>& iter);
    const bool operator !=(const Iterator<T>& iter);
    Iterator<T>& operator =(const Iterator<T>& iter);
    
    
};



template <typename T>
class List{
private:
    Node<T>* head_;
    size_t size_;
    
public:
    typedef Iterator<T> iterator;
    typedef Iterator<const T> constIterator;
    
    List();
    List(const List& source);
    List (List<T>&& source);
    ~List();
    
    T& front()const;
    T& back()const;
    void insert(Iterator<T> pos, const T& elem);
    void erase(Iterator<T> pos);
    void push_back(const T& elem);
    void push_front(const T& elem);
    void pop_back();
    void pop_front();
    Iterator<T> begin()const;
    Iterator<T> end()const;
    List<T>& operator=(const List<T>& source);
    List<T>& operator=(List<T>&& source);
    void clear();
    bool empty();
    size_t size();
    void print();
    
    

    
    
    
    
};


#endif






