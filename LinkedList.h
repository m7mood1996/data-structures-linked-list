//
// Created by mahmood on 1/11/21.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <cstddef>
#include <iostream>

template<typename T>
class Node
{
public:
    explicit Node(T& obj, Node* next=NULL);
    T& get_data();
    Node<T>* &next();
    void set_next(Node<T>*);
private:
    Node(){};
    T m_object;
    Node * m_next;
};


template<typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void push_back(T& ob);
    void push_front(T& ob);
    void pop_back();
    void pop_front();

    void print();

    class iterator;
    iterator begin() { return iterator(0, m_head); }
    iterator end() { return iterator(m_size, m_tail); }
private:
    Node<T>* m_head;
    Node<T>* m_tail;
    size_t m_size;

};


template<typename T>
class LinkedList<T>::iterator{
public:
    iterator(size_t pos, Node<T> *n):m_pos(pos),m_node(n){

    }
    inline iterator &operator++(int){
        ++m_pos;
        m_node = m_node->next();
        return *this;
    }
    inline T& operator*(){
        return (m_node->get_data());
    }
    inline bool operator!=(const iterator& other) const{
        return m_pos != other.m_pos;
    }
    inline bool operator==(const iterator& other) const{
        return m_pos == other.m_pos;
    }

private:
    size_t m_pos;
    Node<T> *m_node;
};




template<typename T>
LinkedList<T>::LinkedList():m_head(NULL),m_tail(NULL),m_size(0) {

}

template<typename T>
void LinkedList<T>::push_back(T &ob) {
    if (m_size == 0)
    {
        m_head = new Node<T>(ob);
        m_tail = m_head;
        ++m_size;
        return;
    }
    Node<T>* t = new Node<T>(ob);
    m_tail->next() = t;
    m_tail = m_tail->next();
    ++m_size;
}

template<typename T>
void LinkedList<T>::push_front(T &ob) {
    if (m_size == 0)
    {
        m_head = new Node<T>(ob);
        m_tail = m_head;
        ++m_size;
        return;
    }
    Node<T> *n = new Node<T>(ob);
    n->set_next(m_head);
    m_head = n;
    ++m_size;
}

template<typename T>
void LinkedList<T>::pop_back() {
    if ( m_head == NULL)
        return;
    Node<T> *curr = m_head;

    if (curr == m_tail)
    {
        delete curr;
        return;
    }


    while (curr->next() != m_tail)
    {
        curr = curr->next();
    }

    delete m_tail;
    m_tail = curr;
    m_tail->next() = NULL;
    --m_size;

}

template<typename T>
void LinkedList<T>::pop_front() {
    if ( m_head == NULL)
        return;
    if ( m_head == m_tail)
    {
        delete m_head;
        return;
    }

    Node<T> *curr = m_head;
    m_head = m_head->next();
    delete curr;
    --m_size;

}

template<typename T>
void LinkedList<T>::print() {
    if ( m_head == NULL)
        return;

    Node<T>* curr = m_head;
    while (curr != NULL)
    {
        std::cout << curr->get_data() << " --> " ;

        curr = curr->next();
    }
    std::cout << std::endl;

}

template<typename T>
LinkedList<T>::~LinkedList() {
    if (m_size == 0)
        return;
    if (m_size == 1)
    {
        delete m_head;
        return;
    }

    Node<T>* curr = m_head->next();
    Node<T>* prev = m_head;
    while (curr != m_tail)
    {
        delete prev;
        prev = curr;
        curr = curr->next();
    }
    delete curr;

}

template<typename T>
Node<T>::Node(T &obj, Node* next):m_object(obj), m_next(next) {

}

template<typename T>
T &Node<T>::get_data()  {
    return m_object;
}

template<typename T>
Node<T> * &Node<T>::next() {
    return m_next;
}

template<typename T>
void Node<T>::set_next(Node<T> * node) {
    m_next = node;

}


#endif //LINKEDLIST_LINKEDLIST_H
