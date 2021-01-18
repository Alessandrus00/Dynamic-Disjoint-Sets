#ifndef NODE_H
#define NODE_H
template <class T>
class Node
{
protected:
    T key;

public:
    Node(T x);
    void setKey(T x);
    T getKey();
};

#endif