#ifndef _TREENODE_H
#define _TREENODE_H



#include <iostream>
#include <string>

template<class T>

class Treenode{
     
public:
	Treenode();
	Treenode (Treenode *rt, Treenode *lt, Treenode *parent, T key, T intervalhigh, T maxvalue, std::string color);
        
	void setright(Treenode *rt);
	Treenode* getright ();
	
	void setleft(Treenode *lt);
	Treenode* getleft ();
        
        void setparent(Treenode *parent);
        Treenode* getparent();
        
        void setkey(T key);
        T getkey();
        
        void setcolor(std::string color);
        std::string getcolor();
        
        void setintervalhigh(T intervalhigh);
        T getintervalhigh();
        
        void setmaxvalue(T maxvalue);
        T getmaxvalue();
        
        void setnode(int, T, T);
		
	int ID;  // maintain the ID of each node in the tree    
 
private:
	Treenode *right;
	Treenode *left;
	Treenode *parent;
	T key; //low endpoint of interval 
        T intervalhigh; //high endpoint of interval
        T maxvalue;  // one of attributes in interval tree node
	std::string color; 
        
};

#include "Treenode.cpp"
#endif
