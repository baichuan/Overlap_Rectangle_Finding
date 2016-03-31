#include "Point.h"
#ifndef _EDGE_H
#define _EDGE_H

class Edge {

public:

	Edge();	
	Edge(int ID, Point a, Point b);
	Point a;
	Point b;
	int ID;
};

#endif
