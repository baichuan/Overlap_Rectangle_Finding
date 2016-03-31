#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm> 
#include <fstream>
#include <cstring>
#include "Edge.h"
#include "Point.h"
#include "Treenode.h"
#include "IntervalTree.h"

using namespace std;

const int MAX_CHARS_PER_LINE = 512;

// this compare function is for sorting based on x coordinate of rectangle

bool compare_x_coordinate(const Edge& e1, const Edge& e2){
		
                if (e1.a.x < e2.a.x) {         // STL sorting function should be strictly less than for returning true. this is the reason triggers problem!!!
                        return true;
                }

                else {
                        return false;
                }
}							

int main(int argc, char *argv[1])
{

	ifstream fin;
  	fin.open(argv[1]); 
	std::vector <Edge> a;
	IntervalTree<float> intervaltree;   
	
	if (!fin.good()){
    		return 1; // exit if file not found
	}
  
// read and parse each line of file
 
  	while (!fin.eof()){
 		 
    		char buf[MAX_CHARS_PER_LINE];
    		fin.getline(buf, MAX_CHARS_PER_LINE);
    		int n; 
    		const char* token[5] = {}; 
    		token[0] = strtok(buf, " "); // parse each line as token
    		if (token[0]){ 
      			for (n = 1; n < 5; n++){
        			token[n] = strtok(0, " ");
				 
			}	
		
			Point P1 (atof(token[1]), atof(token[2]));
			Point P2 (atof(token[1]), atof(token[4]));
			Point P3 (atof(token[3]), atof(token[2]));
			Point P4 (atof(token[3]), atof(token[4])); // the four points of the rectangle
			int ID = atoi(token[0]); // the ID of each edge which is parallel to y axis
			Edge e1(ID, P1, P2);
			Edge e2(ID, P3, P4);
			a.push_back(e1); // when reading each line, store edges' information which is parallel to y axis in the vector a
			a.push_back(e2); 
		
    		}
  	}
	

	std::sort(a.begin(), a.end(), compare_x_coordinate); 

// solve VLSI rectangle overlapping problem
	
	for (int i=0; i< a.size(); i++){

		Treenode<float> *node = new Treenode<float>();
		node->setnode(a[i].ID, a[i].a.y, a[i].b.y);
		if (intervaltree.IntervalSearch(node) != intervaltree.nil) {
			Treenode<float> *overlapnode = intervaltree.IntervalSearch(node);
			if (a[i].ID == overlapnode->ID){
				intervaltree.DELETE(overlapnode); 
			
			}
			else {  
				if (overlapnode->ID < a[i].ID){
					cout << overlapnode->ID << " " << a[i].ID << " "<< "overlap" << endl;
				}
				else {
					cout << a[i].ID <<" " << overlapnode->ID << " " << "overlap" << endl;
				}
				exit(0);  // find any overlap and we are done and terminate the whole program
			}
		}

		else {
			intervaltree.INSERT(node);
		}

	}
	
		cout << "no overlap" << endl;

	return 0;
}
