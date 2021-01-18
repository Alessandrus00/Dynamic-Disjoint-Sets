#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class RootedTree;

template <class T>
class TreeNode : public Node<T>
{
    int rank;
    TreeNode<T> *parent, *leftChild, *rightSibling;
    RootedTree<T> *myTree;

public:
    TreeNode(T x);
    void setRank(int x){rank=x;}
    int getRank(){return rank;}
    TreeNode<T> *getParent(){return parent;}
    void setParent(TreeNode<T> *x){parent=x;}
    void setMyTree(RootedTree<T> *x){myTree=x;}
    RootedTree<T> *getMyTree(){return myTree;}

    //utili ai fini della visualizzazione
    void setLeftChild(TreeNode<T> *x){leftChild=x;}
    TreeNode<T> *getLeftChild(){return leftChild;}

    void setRightSibling(TreeNode<T> *x){rightSibling=x;}
    TreeNode<T> *getRightSibling(){return rightSibling;}
};

template <class T>
class RootedTree
{
    int keyCounter;
    TreeNode<T> *root, *current,*rightOuterMost;
    int iteration;
    int pos;
    ostream& _view(ostream&os, TreeNode<T>*r);

public:
    RootedTree();
    RootedTree<T> *ins(TreeNode<T> *x);
    //RootedTree<T>*canc(T x);
    int getKeyCounter(){return keyCounter;}
    TreeNode<T> *getRoot(){return root;}
    int getPos() { return pos; }
    void setPos(int x) { pos = x; }
    void updateKeyCounter(int x){keyCounter+=x;}
    void setRightOuterMost(TreeNode<T>*x){rightOuterMost=x;}
    TreeNode<T>* getRightOuterMost(){return rightOuterMost;}
    template <class U> friend ostream& operator<<(ostream &os, RootedTree<U> &r);
};

template <class T>
ostream& operator<<(ostream &os, RootedTree<T> &r);

#endif