#include "Node.h"

//Node
template<class T>
Node<T>::Node(T x)
{
    key = x;
}

template<class T>
void Node<T>::setKey(T x)
{
    key = x;
}
template<class T>
T Node<T>::getKey() { return key; }
