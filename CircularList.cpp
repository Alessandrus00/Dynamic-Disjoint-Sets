#include "CircularList.h"

//LIST_NODE
template <class T>
ListNode<T>::ListNode(T x) : Node<T>(x)
{
    myList = NULL;
    next=NULL;
}

//CIRCULAR_LIST
template <class T>
CircularList<T>::CircularList()
{
    keyCounter = iteration = pos=0;
    head = tail = current = NULL;
}

template <class T>
CircularList<T> *CircularList<T>::ins(ListNode<T>* x)
{
    x->setMyList(this);
    if (!head)
    {
        head=tail=x;
        x->setNext(x);
        tail->setNext(head);
    }
    keyCounter++;
    return this;
}


template <class T>
void CircularList<T>::reset()
{
    current = head;
    iteration = 0;
}

template <class T>
int CircularList<T>::hasNext()
{
    return iteration < keyCounter;
}

template <class T>
T *CircularList<T>::next()
{
    if (!hasNext())
        return NULL;
    T *t = new T(current->getKey());
    current = current->getNext();
    iteration++;
    return t;
}

template <class T>
ostream &operator<<(ostream &os, CircularList<T> &l)
{
    l.reset();
    while (l.hasNext())
    {
        os << *l.next() << " ";
    }
    return os;
}
