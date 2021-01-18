#ifndef DISJOINTSETSFOREST_H
#define DISJOINTSETSFOREST_H

#include "RootedTree.h"
#include <iostream>
using namespace std;
template <class T>
class DisjointSetsForest
{
    RootedTree<T> **collection;
    int setCounter;
    int current;
    ostream &_view(ostream &os);

public:
    DisjointSetsForest();
    RootedTree<T> *_findTree(TreeNode<T> *x);
    void makeSet(TreeNode<T> *x);
    void unionSet(TreeNode<T> *x, TreeNode<T> *y);
    TreeNode<T> *findSet(TreeNode<T> *x);
    void link(TreeNode<T> *x, TreeNode<T> *y);
    void view();
    template <class U>
    friend ostream &operator<<(ostream &os, DisjointSetsForest<U> &f);
};

template <class T>
ostream &operator<<(ostream &os, DisjointSetsForest<T> &f);

#endif