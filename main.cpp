#include <iostream>
#include "DisjointSetsCircularList.cpp"
#include "CircularList.cpp"
//#include "DisjointSetsForest.cpp"
//#include "RootedTree.cpp"
#include "Node.cpp"

using namespace std;

int main()
{
    DisjointSetsCircularList<int> c;

    ListNode<int>* t1= new ListNode<int>(1);
    ListNode<int>* t2= new ListNode<int>(2);
    ListNode<int>* t3= new ListNode<int>(3);
    ListNode<int>* t4= new ListNode<int>(4);
    ListNode<int>* t5= new ListNode<int>(5);



    ListNode<int>* t6= new ListNode<int>(6);
    ListNode<int>* t7= new ListNode<int>(7);
    ListNode<int>* t8= new ListNode<int>(8);
    ListNode<int>* t9= new ListNode<int>(9);


    c.makeSet(t1);
    c.makeSet(t2);
    c.makeSet(t3);
    c.makeSet(t4);
    c.makeSet(t5);
    c.makeSet(t6);
    c.makeSet(t7);
    c.makeSet(t8);
    c.makeSet(t9);

    cout<<c<<endl;

    c.unionSet(t1,t7);
    cout<<c<<endl;

    c.unionSet(t2,t3);
    cout<<c<<endl;

    c.unionSet(t3,t1);
    cout<<c<<endl;
    
    return 0;
}