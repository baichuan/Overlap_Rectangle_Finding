/* 
 * File:   IntervalTree.h
 * Author: baichuanzhang
 *
 * Created on March 10, 2014, 7:06 PM
 */
#include "Treenode.h"
#ifndef INTERVALTREE_H
#define	INTERVALTREE_H

template<class T>
class IntervalTree {
    
public:
    IntervalTree();
    IntervalTree(Treenode<T> *root, Treenode<T> * nil);
    void INSERT(Treenode<T> *);
    void DELETE(Treenode<T> *);
    Treenode<T>* getRoot();
    Treenode<T>* IntervalSearch(Treenode<T> *);
    
    void print_inorder (Treenode<T> *root); // for testing insertion and deletion validation
    void print_postorder(Treenode<T> *root); 
    void print_preorder(Treenode<T> *root);   
    Treenode<T> * root;
    Treenode<T> * nil;
    
private:   
    void LEFTROTATE(Treenode<T> *);
    void RIGHTROTATE(Treenode<T> *);
    Treenode<T> * INSERTFIXUP(Treenode<T> *);
    void DELETEFIXUP(Treenode<T> *);
    Treenode<T> * TreeMinimum(Treenode<T> *);
//    Treenode<T> * TreeSuccessor(Treenode<T> *);
    void FixUpMaxValue(Treenode<T> *);
    void Transplant(Treenode<T> *, Treenode<T> *);
    T maxi(T , T);
//    Treenode<T> * root;
//    Treenode<T> * nil;
};

#include "IntervalTree.cpp"

#endif	/* INTERVALTREE_H */

