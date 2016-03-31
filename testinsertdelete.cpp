#include<iostream>
#include "Treenode.h"
#include"IntervalTree.h"

using namespace std;
// for testing insertion and deletion

int main()
{

	
	Treenode<int> *node = new Treenode<int>[30]();  //a 30-element Treenode array can be created and assigned to Treenode object node
        
	IntervalTree<int> intervaltree;

//	int A[20] = {26, 17, 41, 14, 21, 30, 47, 10, 15, 19, 23, 28, 38, 7, 12, 16, 20, 35, 39, 3}; // algorithm book P310 the RB tree	  
//	int B[20] = {30, 19, 48, 16, 29, 33, 60, 19, 17, 50, 24, 61, 62, 63, 65, 66, 69, 80, 82, 90};
        // for testing insertion and deletion
        int A[6] = {41,38,31,12,19,8};
        int B[6] = {50,42,39,18,24,10};
        
        
//        int A[4] = {21, 19, 23, 20};
//	int B[4] = {80, 81, 82, 83};

        for (int i=0; i<6; i++)
        {
            node[i].setnode(i, A[i], B[i]);
            
            intervaltree.INSERT(&node[i]);
        }

	

  	std::cout << "insertion result" << std::endl;
	intervaltree.print_preorder(intervaltree.getRoot());      
 //       intervaltree.DELETE(&node[0]); //delete case 3 and case 4  infinite!!!
//        intervaltree.DELETE(&node[5]); //deletefixup no needed since y.color==red  infinite!!!

	node[6].setnode(6,43,54);
	std::cout << "overlap search result" << std::endl;
	intervaltree.IntervalSearch(&node[6]);
	
	intervaltree.DELETE(&node[2]);
	intervaltree.DELETE(&node[4]);
	std::cout << "deletion result" << std::endl;
        intervaltree.print_preorder(intervaltree.getRoot());
        
        
        return 0;

}


