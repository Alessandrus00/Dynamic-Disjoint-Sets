#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class CircularList;

//LIST_NODE
template <class T>
class ListNode : public Node<T>
{
    CircularList<T> *myList;
    ListNode<T> *next;

public:
    ListNode(T x);
    void setMyList(CircularList<T> *x){myList=x;}
    CircularList<T> *getMyList(){return myList;}
    ListNode<T> *getNext(){return next;}
    void setNext(ListNode<T> *x){next=x;}
};

//CIRCULAR_LIST
template <class T>
class CircularList
{
    int keyCounter;
    ListNode<T> *head, *tail, *current;
    int iteration;
    int pos;

public:
    CircularList();
    CircularList<T> *ins(ListNode<T> *x);
    //CircularList<T>*canc(T x);
    int getKeyCounter(){return keyCounter;}
    void updateKeyCounter(int x){keyCounter+=x;}
    ListNode<T> *getHead(){return head;}
    ListNode<T> *getTail(){return tail;}
    void setTail(ListNode<T> *x){tail=x;}
    void setPos(int x){pos=x;}
    int getPos(){return pos;}
    //iterator
    void reset();
    int hasNext();
    T *next();
};

template <class T>
ostream &operator<<(ostream &os, CircularList<T> &l);

#endif