#include "IntervalTree.h"
#include "Treenode.h"
#include <iostream>

template<class T>
IntervalTree<T>::IntervalTree()
{
    nil = new Treenode<T>();
    nil->setleft(nil);
    nil->setright(nil);
    nil->setparent(nil);
    nil->setcolor("Black");
//    nil->setkey(NULL);
    //nil->setintervalhigh(NULL);
    //nil->setmaxvalue(NULL);
    
    root = new Treenode<T>();
    root=nil;   // nil should assign root initially otherwise it will result in infinite loop in the code


    //root->setleft(nil);
    //root->setright(nil);
    //root->setparent(nil);
    //root->setcolor("Black");
    //root->setkey(NULL);
    //root->setintervalhigh(NULL);
    //root->setmaxvalue(NULL);
}

template<class T>
IntervalTree<T>::IntervalTree(Treenode<T> * root, Treenode<T> * nil)
{
    this->root=root;
    this->nil=nil;
}

template<class T>
T IntervalTree<T>::maxi(T a, T b)
{
    T max=a;
    if (b>max){
        max=b;
    }
    return max;
}


//FixUpMaxValue function is fixing up maxvalue attribute during the rotation process
template<class T>
void IntervalTree<T>::FixUpMaxValue(Treenode<T> * x)
{
    while (x != this->nil){
	 x->setmaxvalue(maxi(x->getintervalhigh(), maxi(x->getleft()->getmaxvalue(), x->getright()->getmaxvalue())));
         x=x->getparent();
     }

}

template<class T>
void IntervalTree<T>::LEFTROTATE(Treenode<T>* x) {

	Treenode<T>* y;
	y=x->getright();
        
        
        x->setright(y->getleft());
        
	
        
	if (y->getleft() != this->nil)
	{
		
                y->getleft()->setparent(x); // y.left.parent=x
	}
        
        
        y->setparent(x->getparent());
        
	if (x->getparent() == this->nil)
	{	
		this->root=y;
	}
	else if (x==x->getparent()->getleft())
	{
		x->getparent()->setleft(y);
	}
	else
	{	
		x->getparent()->setright(y);
	}
	
	y->setleft(x);
	x->setparent(y);
        
        x->setmaxvalue(maxi(x->getleft()->getmaxvalue(), maxi(x->getright()->getmaxvalue(), x->getintervalhigh())));
        y->setmaxvalue(maxi(x->getmaxvalue(), maxi(y->getright()->getmaxvalue(), y->getintervalhigh())));
}

template<class T>
void IntervalTree<T>::RIGHTROTATE(Treenode<T>* y) {

	Treenode<T>* x;
	x=y->getleft();
        y->setleft(x->getright());

	if (x->getright() != this->nil){
		x->getright()->setparent(y);
        }
	x->setparent(y->getparent());
        
	if (y->getparent() == this->nil){
		this->root=x;
        }
	else if (y==y->getparent()->getright()){
		y->getparent()->setright(x); //y.parent.right=x
        }
	else{
		y->getparent()->setleft(x);
        }
	x->setright(y);
	y->setparent(x);
        
        y->setmaxvalue(maxi(y->getleft()->getmaxvalue(), maxi(y->getright()->getmaxvalue(), y->getintervalhigh())));
        x->setmaxvalue(maxi(x->getleft()->getmaxvalue(), maxi(y->getmaxvalue(), x->getintervalhigh())));
        
}


template<class T>
Treenode<T> * IntervalTree<T>::TreeMinimum(Treenode<T> * x)
{
    while(x->getleft() != this->nil){
        x=x->getleft();
    }
    
    return x;
}


/*
template<class T>
Treenode<T> * IntervalTree<T>::TreeSuccessor(Treenode<T> * x)
{   
    Treenode<T> * y;
    
    
    if ((x->getright()) != this->nil){
        
        return TreeMinimum(x->getright());
    }
    
    y=x->getparent();
    while ((y != this->nil) && (x==y->getright())){
            x=y;
            y=y->getparent();
        }
        
    return y;
    
}
*/

// Transplant is for intervaltree delete purpose
template<class T>
void IntervalTree<T>::Transplant(Treenode<T>* u, Treenode<T>* v)
{
    if (u->getparent()== this->nil){
        this->root = v;
    }
    else if (u == u->getparent()->getleft()){
        u->getparent()->setleft(v);
    }
    else {
        u->getparent()->setright(v);
    }
    v->setparent(u->getparent());
}


template<class T>
void IntervalTree<T>::INSERT(Treenode<T>* z) {
	Treenode<T>* x;
	Treenode<T>* y;

	y=this->nil;
	x=this->root;
	while (x != this->nil){
		y=x;
		if (z->getkey() < x->getkey()){
			x=x->getleft();
	       } 
                
                else{
			x=x->getright();
               } 	
                   
        } 
	
	z->setparent(y);
	if (y==this->nil){
		this->root=z;
          }
	else if (z->getkey() < y->getkey()) {
		y->setleft(z);
	}
	else {
		y->setright(z);
	}

	z->setleft(this->nil);
	z->setright(this->nil);
	z->setcolor("Red");
        INSERTFIXUP(z);
}	

template<class T>
Treenode<T> * IntervalTree<T>::INSERTFIXUP(Treenode<T>* z) {

	Treenode<T> * y;
        z->setcolor("Red");
        FixUpMaxValue(z->getparent());  // maintain the maxvalue information 
        
        while (z->getparent()->getcolor() == "Red") {
		if (z->getparent()==z->getparent()->getparent()->getleft()){
			y=z->getparent()->getparent()->getright();
			if (y->getcolor()=="Red") {
				z->getparent()->setcolor("Black");
				y->setcolor("Black");
				z->getparent()->getparent()->setcolor("Red");
				z=z->getparent()->getparent(); 
			}
			else {
				if (z==z->getparent()->getright()){
				z=z->getparent();
				LEFTROTATE(z);
			}
			

			z->getparent()->setcolor("Black");
			z->getparent()->getparent()->setcolor("Red");
			RIGHTROTATE(z->getparent()->getparent());
		}
	}

		else {
			y=z->getparent()->getparent()->getleft();
			if (y->getcolor()=="Red"){
				z->getparent()->setcolor("Black");
				y->setcolor("Black");
				z->getparent()->getparent()->setcolor("Red");
				z=z->getparent()->getparent();
			}
			else {
				if (z==z->getparent()->getleft()){
				z=z->getparent();
				RIGHTROTATE(z);
			}
			
			z->getparent()->setcolor("Black");
			z->getparent()->getparent()->setcolor("Red");
			LEFTROTATE(z->getparent()->getparent());
		}
	}
      }
	
	
	root->setcolor("Black"); 
	return(z);
}


template<class T>
void IntervalTree<T>::DELETE(Treenode<T>* z)
{
    Treenode<T> * y;
    Treenode<T> * x;
    std::string y_original_color;
    y=z;
    y_original_color=y->getcolor();
    
    if (z->getleft() == this->nil){
        x=z->getright();
        Transplant(z,z->getright());
        FixUpMaxValue(x->getparent());
    }
    else if (z->getright() == this->nil){
        x=z->getleft();
        Transplant(z,z->getleft());
        FixUpMaxValue(x->getparent());
    }
    
    else {
        y=TreeMinimum(z->getright());
        y_original_color=y->getcolor();
        x=y->getright();

        if (y->getparent() == z){
            x->setparent(y);
        }
        else {
            Transplant(y,y->getright());
            y->setright(z->getright());
            y->getright()->setparent(y);
        }
	
        Transplant(z,y);
        FixUpMaxValue(x->getparent());
        y->setleft(z->getleft());
        y->getleft()->setparent(y);
        y->setcolor(z->getcolor());
    }
    if (y_original_color == "Black"){
        DELETEFIXUP(x);
    }
}    



template<class T>
void IntervalTree<T>::DELETEFIXUP(Treenode<T> * x)
{
	Treenode<T> * w;

	while ((x != this->root) && (x->getcolor()=="Black")) {

		if (x==x->getparent()->getleft()){
			w=x->getparent()->getright();
			if (w->getcolor()=="Red"){
				w->setcolor("Black");
				x->getparent()->setcolor("Red");
				LEFTROTATE(x->getparent());
				w=x->getparent()->getright();
			}
			if ((w->getleft()->getcolor()=="Black") && (w->getright()->getcolor()=="Black")){
				w->setcolor("Red");
				x=x->getparent();
			}
			else {
				if (w->getright()->getcolor()=="Black"){
				w->getleft()->setcolor("Black");
				w->setcolor("Red");
				RIGHTROTATE(w);
				w=x->getparent()->getright();
			}

				w->setcolor(x->getparent()->getcolor());
				x->getparent()->setcolor("Black");
				w->getright()->setcolor("Black");
				LEFTROTATE(x->getparent());
				x=this->root;
		}
	}

		else{
			w=x->getparent()->getleft();
                        if (w->getcolor()=="Red"){
                                w->setcolor("Black");
                                x->getparent()->setcolor("Red");
                                RIGHTROTATE(x->getparent());
                                w=x->getparent()->getleft();
			}
                        if ((w->getleft()->getcolor()=="Black") && (w->getright()->getcolor()=="Black")){
                                w->setcolor("Red");
                                x=x->getparent();
			}
                        else {
				if (w->getleft()->getcolor()=="Black"){
                                w->getright()->setcolor("Black");
                                w->setcolor("Red");
                                LEFTROTATE(w);
                                w=x->getparent()->getleft();
			}
                        	w->setcolor(x->getparent()->getcolor());
                        	x->getparent()->setcolor("Black");
                        	w->getleft()->setcolor("Black");
                        	RIGHTROTATE(x->getparent());
                        	x=this->root;
		}
	  }
	}
	x->setcolor("Black");
	
}


template<class T>
Treenode<T>* IntervalTree<T>::getRoot()
{
        return root;
}


// print_inorder, print_preorder and print_postorder functions are used as testing validation of insertion and deletion process

template<class T>
void IntervalTree<T>::print_inorder(Treenode<T> * x)
{
	
        if (x != this->nil){
		print_inorder(x->getleft());
//		std::cout.precision(2);
		std::cout <<"["<< x->getkey() <<","<<x->getintervalhigh()<<"]"<< x->getcolor()<< x->getmaxvalue()<<std::endl;
		print_inorder(x->getright());
	}
}


template<class T>
void IntervalTree<T>::print_postorder(Treenode<T> *x)
{
    if (x != this->nil){

//	std::cout.precision(2);
        print_postorder(x->getleft());
        print_postorder(x->getright());
        std::cout <<"[" << x->getkey() << ","<<x->getintervalhigh()<<"]"<<x->getcolor()<<x->getmaxvalue()<<std::endl;
    }
}


template<class T>
void IntervalTree<T>::print_preorder(Treenode<T> *x)
{
	if (x!= this->nil){
//		std::cout.precision(6);
		std::cout <<"[" << x->getkey() << ","<<x->getintervalhigh()<<"]"<<x->getcolor()<<x->getmaxvalue()<<std::endl;
		print_preorder(x->getleft());
                print_preorder(x->getright());
	}
}


//IntervalSearch function is for testing overlap intervals
template<class T>
Treenode<T> * IntervalTree<T>::IntervalSearch(Treenode<T> * y) 
{
    Treenode<T> * x;
    x=this->root;
    
    while ((x != this->nil) && (y->getkey() > x->getintervalhigh() || x->getkey() > y->getintervalhigh())) {   //interval x and y don't overlap 
        if ((x->getleft() != this->nil) && (x->getleft()->getmaxvalue() >= y->getkey())){
            x=x->getleft();
        }
        else {
           x=x->getright();
       }
    }
   
/*
	if (x != this->nil){

//	 std::cout.precision(8);
	 std::cout << "overlap exsits" << std::endl;
	 std::cout << "[" << x->getkey() << "," << x->getintervalhigh()<<"]"<<std::endl;
	}

	else{

	 std::cout << "no overlap" <<std::endl;
	}
*/
	return x;
}
