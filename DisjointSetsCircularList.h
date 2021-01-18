#ifndef DISJOINTSETSCIRCULARLIST_H
#define DISJOINTSETSCIRCULARLIST_H

#include "CircularList.h"

template <class T>
class DisjointSetsCircularList
{
    CircularList<T> **collection;
    int setCounter;
    int current;
    ostream& _view(ostream& os);

public:
    DisjointSetsCircularList();
    void makeSet(ListNode<T>* x);
    void unionSet(ListNode<T>* x, ListNode<T>* y);
    ListNode<T>* findSet(ListNode<T>* x);
    void view();
    template<class U> friend ostream &operator<<(ostream &os, DisjointSetsCircularList<U> &l);

    //iterator
    void reset();
    int hasNext();
    CircularList<T> *next();
};

template <class T>
ostream &operator<<(ostream &os, DisjointSetsCircularList<T> &l);

#endif