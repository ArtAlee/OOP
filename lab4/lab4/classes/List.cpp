
#include "List.h"
#ifndef LIST
#define LIST

#include <algorithm>

template <typename T>
Node<T>::Node(){
    next_ = nullptr;
    prev_ = nullptr;
}

template <typename T>
Node<T>::Node(const T data):data_(data){
    next_ = nullptr;
    prev_ = nullptr;
}


template <typename T>
Iterator<T>::Iterator(){
    ptr_ = nullptr;
}

template <typename T>
Iterator<T>::Iterator(Node<T>*ptr):ptr_(ptr){}

template <typename T>
Iterator<T>::Iterator(const Iterator<T>& it){
    ptr_ = it.ptr_;
}

template <typename T>
Node<T>* Iterator<T>::getPtr(){
    return ptr_;
}

template <typename T>
T& Iterator<T>::operator*(){
    return ptr_->data_;
}
template <typename T>
Iterator<T>& Iterator<T>::operator++(){
    ptr_ = ptr_->next_;
    return *this;
}


template <typename T>
Iterator<T>& Iterator<T>::operator --(){
    ptr_ = ptr_->prev_;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int){
    Iterator<T> copy = Iterrator<T>(ptr_);
    ptr_ = ptr_->next_;
    return copy;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int){
    Iterator<T> copy = Iterrator<T>(ptr_);
    ptr_ = ptr_->prev_;
    return copy;
}

template <typename T>
const bool Iterator<T>::operator==(const Iterator<T>& iter){
    return iter.ptr_ == ptr_;
}

template <typename T>
const bool Iterator<T>::operator!=(const Iterator<T>& iter){
    return iter.ptr_ != ptr_;
}

template <typename T>
Iterator<T>& Iterator<T>::operator =(const Iterator<T>& iter){
    ptr_ = iter.ptr_;
    return *this;
}

//list


template <typename T>
List<T>::List(){
    size_ = 0;
    head_ = reinterpret_cast<Node<T>*>(new int8_t[sizeof(Node<T>)]);
    head_->prev_ = head_;
    head_->next_ = head_;
}

template <typename T>
Iterator<T> List<T>::begin()const{
    return Iterator(head_->next_);
}

template <typename T>
Iterator<T> List<T>::end()const{
    return Iterator(head_);
}



template <typename T>
void List<T>::insert(Iterator<T> pos, const T& elem){
    Node<T>* a = new Node<T>(elem);
    Node<T>* prevos = pos.getPtr()->prev_;
    prevos->next_ = a;
    pos.getPtr()->prev_ = a;
    a->next_ = pos.getPtr();
    a->prev_ = prevos;
    ++size_;
}

template <typename T>
List<T>::List(const List<T>& source): List(){
    Iterator<T> from = source.begin();
    Iterator<T> to = begin();
    for(; from != source.end(); ++from) {
        insert(to, *from);
    }
}


template <typename T>
void List<T>::print(){
    for(auto it = begin(); it != end(); ++it){
        std::cout<< *it << '\n';
    }
    std::cout << '\n';
}


template<typename T>
void List<T>::push_front(const T& elem) {
    auto it = begin();
    insert(it, elem);
}

template<typename T>
void List<T>::push_back(const T& elem){
    auto it = end();
    insert(it, elem);
}


template <typename T>
List<T>::~List(){
    if(head_){
        Node<T>* tmp = head_->next_;
        while(tmp != head_) {
            tmp = tmp->next_;
            delete tmp->prev_;
            tmp->prev_ = nullptr;
        }
        delete head_;
    }
}



template <typename T>
T& List<T>::front()const{
    if(size_ == 0) {
        throw std::runtime_error("list is empty");
    }
    return *(begin());
}


template <typename T>
T& List<T>::back()const{
    if(size_ == 0) {
        throw std::runtime_error("list is empty");
    }
    return *(--end());
}


template <typename T>
void List<T>::erase(Iterator<T> pos){
    Node<T>* elem = pos.getPtr();
    elem->prev_->next_ = elem->next_;
    elem->next_->prev_ = elem->prev_;
    delete elem;
    --size_;
}


template <typename T>
void List<T>::pop_back(){
    erase(--end());
}

template <typename T>
void List<T>::pop_front(){
    erase(begin());
}

template<typename T>
bool List<T>::empty(){
    return size_ == 0;
}


template <typename T>
void List<T>::clear(){
    Node<T>* tmp = head_->next_;
    while(tmp != head_) {
        tmp = tmp->next_;
        delete tmp->prev_;
        tmp->prev_ = nullptr;
    }
    size_ = 0;
    head_->prev_ = head_;
    head_->next_ = head_;
}

template <typename T>
size_t List<T>::size(){
    return size_;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& source){
    clear();
    Iterator<T> from = source.begin();
    Iterator<T> to = begin();
    for(; from != source.end(); ++from) {
        insert(to, *from);
    }
    return *this;
}


template <typename T>
List<T>& List<T>::operator=(List<T>&& source){
    clear();
    size_ = source.size_;
    head_ = source.head_;
    source.head_ = nullptr;
    source.size_ = 0;
    return *this;
}

template <typename T>
List<T>::List(List<T>&& source){
    size_ = source.size_;
    head_ = source.head_;
    source.head_ = nullptr;
    source.size_ = 0;
}


template <typename R, typename T> struct W
{
  using F = std::function<R(T)>;
};
/*
template <typename T> void invoke(typename W<T>::F f, T val)
{
  f(val);
}
*/


//std function
/*
template <typename T, typename R>
List<R> select(List<T> list, ){
    List<R> res;
    for(auto it = list.begin(); it != list.end(); ++it){
        res.push_back(func(*it));
    }
    return res;
}
*/
#endif

