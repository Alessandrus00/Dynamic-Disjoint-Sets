#include "DisjointSetsForest.h"
#define N 100
template <class T>
DisjointSetsForest<T>::DisjointSetsForest()
{
    collection = new RootedTree<T> *[N];
    for (int i = 0; i < N; i++)
        collection[i] = new RootedTree<T>();
    setCounter = current = 0;
}


template <class T>
void DisjointSetsForest<T>::makeSet(TreeNode<T> *x)
{
    if (setCounter == N)
        return;
    RootedTree<T> *y = new RootedTree<T>();
    y->ins(x);
    y->setPos(setCounter);
    collection[setCounter] = y;
    setCounter++;
}

template <class T>
void DisjointSetsForest<T>::unionSet(TreeNode<T> *x, TreeNode<T> *y)
{
    //trovo i rappresentanti degli alberi in cui si trovano x e y rispettivamente
    TreeNode<T> *rootX = findSet(x);
    TreeNode<T> *rootY = findSet(y);
    //effettuo un collegamento tra le radici
    link(rootX, rootY);
}

template <class T>
TreeNode<T> *DisjointSetsForest<T>::findSet(TreeNode<T> *x)
{
    if (!x)
        return NULL;
    if(x!=x->getParent()){
        x->setParent(findSet(x->getParent()));
    }
    return x->getParent();
}

template <class T>
void DisjointSetsForest<T>::link(TreeNode<T> *a, TreeNode<T> *b)
{
    //voglio attaccare a->b
    if (a->getRank() > b->getRank())
    {
        TreeNode<T> *tmp = a;
        a = b;
        b = tmp;
    }

    if (b->getRank() == a->getRank())
        b->setRank(b->getRank() + 1);
    //conservo le info sull'albero di a prima di sovrascrivere il suo puntatore
    RootedTree<T> *tree = b->getMyTree();
    int pos_a_Tree = a->getMyTree()->getPos();
    int keyCounter_a_Tree = a->getMyTree()->getKeyCounter();
    //collego la radice a alla radice b
    a->setParent(b);
    a->setMyTree(NULL);
    //aggiorno i puntatori utili alla visualizzazione dell'albero
    if (!b->getLeftChild())
    {
        b->setLeftChild(a);
        tree->setRightOuterMost(a);
    }
    else
    {
        TreeNode<T> *c = tree->getRightOuterMost();
        c->setRightSibling(a);
        tree->setRightOuterMost(a);
    }
    //aggiorno il conteggio delle chiavi di b
    tree->updateKeyCounter(keyCounter_a_Tree);
    //riposiziono l'ultimo albero della collezione al posto di quello che si è agganciato; così evito buchi nell'array collezione
    if (pos_a_Tree < setCounter - 1)
    {
        collection[pos_a_Tree] = collection[setCounter - 1];
        collection[pos_a_Tree]->setPos(pos_a_Tree);
    }
    //diminuisco il numero di elementi della collezione
    setCounter--;
}

template <class T>
ostream &DisjointSetsForest<T>::_view(ostream &os)
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
void DisjointSetsForest<T>::view()
{
    _view(cout);
}

template <class T>
ostream &operator<<(ostream &os, DisjointSetsForest<T> &f)
{
    return f._view(os);
}
