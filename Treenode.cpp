#include "Treenode.h"

template<class T>
Treenode<T>:: Treenode ()
{
	this->right=NULL;
	this->left=NULL;
	this->parent=NULL;
	this->color="Black";
}

template<class T>
Treenode<T>::Treenode (Treenode<T> *rt, Treenode<T> *lt, Treenode<T> *parent, T key, T intervalhigh, T maxvalue, std::string color)
{
	
	this->right=rt;
	this->left=lt;
	this->parent=parent;
	this->key=key;
        this->intervalhigh=intervalhigh;
        this->maxvalue=maxvalue;
	this->color=color;
}

template<class T>
void Treenode<T>::setright(Treenode<T> *rt)
{
	this->right=rt;
}

template<class T>
Treenode<T>* Treenode<T>:: getright ()
{
	return right;
}

template<class T>
void Treenode<T>:: setleft(Treenode<T> *lt)
{
	this->left=lt;
}

template<class T>
Treenode<T>* Treenode<T>:: getleft ()
{
	return left;
}

template<class T>
void Treenode<T>:: setparent(Treenode<T> *parent)
{
    this->parent=parent;
}

template<class T>
Treenode<T>* Treenode<T>:: getparent()
{
    return parent;
}

template<class T>
void Treenode<T>::setkey(T key)
{
    this->key=key;
}

template<class T>
T Treenode<T>::getkey()
{
    return key;
}

template<class T>
void Treenode<T>::setintervalhigh(T intervalhigh)
{
    this->intervalhigh=intervalhigh;
}

template<class T>
T Treenode<T>::getintervalhigh()
{
    return intervalhigh;
}

template<class T>
void Treenode<T>::setmaxvalue(T maxvalue)
{
    this->maxvalue=maxvalue;
}

template<class T>
T Treenode<T>::getmaxvalue()
{
    return maxvalue;
}

template<class T>
void Treenode<T>::setcolor(std::string color)
{
    this->color=color;
}

template<class T>
std::string Treenode<T>::getcolor()
{ 
    return color;
}


template<class T>
void Treenode<T>::setnode(int x, T a, T b)
{
    key=a;
    intervalhigh=b;
    maxvalue=b;
    ID=x;
}

