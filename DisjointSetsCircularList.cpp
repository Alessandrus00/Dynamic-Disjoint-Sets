#include "DisjointSetsCircularList.h"
#define N 100
template <class T>
DisjointSetsCircularList<T>::DisjointSetsCircularList()
{
    collection = new CircularList<T> *[N];
    for (int i = 0; i < N; i++)
        collection[i] = new CircularList<T>();
    setCounter = current = 0;
}

template <class T>
void DisjointSetsCircularList<T>::makeSet(ListNode<T> *x)
{
    if (setCounter == N)
        return;
    CircularList<T> *y = new CircularList<T>();
    y->ins(x);
    y->setPos(setCounter);
    collection[setCounter] = y;
    setCounter++;
    return;
}

template <class T>
void DisjointSetsCircularList<T>::unionSet(ListNode<T> *x, ListNode<T> *y)
{
    CircularList<T> *listX = x->getMyList(), *listY = y->getMyList();
    if (listX->getKeyCounter() > listY->getKeyCounter())
    { //in listX c'è la lista più corta
        listX = listY;
        listY = x->getMyList();
    }
    //aggancio la lista più corta a quella più lunga
    listY->getTail()->setNext(listX->getHead());
    listX->getTail()->setNext(listY->getHead());
    listY->setTail(listX->getTail());
    listY->updateKeyCounter(listX->getKeyCounter());
    ListNode<T> *tmp = listX->getHead();

    //aggiorno i puntatori a lista degli elementi che stanno migrando verso la nuova lista
    for (int i = 0; i < listX->getKeyCounter(); i++)
    {
        tmp->setMyList(listY);
        tmp = tmp->getNext();
    }

    //sovrascrivo il puntatore alla lista che si è agganciata con quello dell'ultimo elemento della collezione; così evito i buchi nell'array
    int posX = listX->getPos();
    if (posX < setCounter - 1)
    {
        collection[posX] = collection[setCounter - 1];
        collection[posX]->setPos(posX);
    }
    //diminuisco il numero di elementi della collezione
    setCounter--;
}

template <class T>
ListNode<T> *DisjointSetsCircularList<T>::findSet(ListNode<T> *x)
{
    return x->getMyList()->getHead();
}

template <class T>
ostream &DisjointSetsCircularList<T>::_view(ostream &os)
{
    os << "{ ";
    for (int i = 0; i < setCounter; i++)
    {
        os << "{ ";
        os << *collection[i];
        os << "} ";
    }
    os << "}";
}

template <class T>
void DisjointSetsCircularList<T>::view()
{
    _view(cout);
}

template <class T>
ostream &operator<<(ostream &os, DisjointSetsCircularList<T> &l)
{
    return l._view(os);
}