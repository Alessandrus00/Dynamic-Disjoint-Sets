#include "RootedTree.h"

//TREE NODE
template<class T>
TreeNode<T>::TreeNode(T x): Node<T>(x){
    rank=0;
    parent=leftChild= rightSibling=NULL;
    myTree=NULL;
}


//ROOTED TREE

template <class T>
RootedTree<T>::RootedTree()
{
    keyCounter =iteration=0;
    root = NULL;
    rightOuterMost=NULL;
}

template <class T>
RootedTree<T> *RootedTree<T>::ins(TreeNode<T>* x)
{
    keyCounter++;
    if(!root){ //gestisco solo il primo inserimento poiché i successivi avverranno tramite union
        root=x;
        x->setParent(x);
        x->setRank(0);
        x->setMyTree(this);
    }
    return this;
}


template<class T>
ostream& RootedTree<T>::_view(ostream&os, TreeNode<T>*r){
    if(!r) return os;
    os<<r->getKey()<<" ";
    r=r->getLeftChild();
    while(r){
        _view(os,r);
        r=r->getRightSibling();
    }
}

template <class T>
ostream& operator<<(ostream &os, RootedTree<T> &r)
{
   return r._view(os,r.getRoot());
}
