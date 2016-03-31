#include "Edge.h"
#include "Point.h"

Edge::Edge()
{
	this->ID =0;
}

Edge:: Edge(int ID, Point a, Point b)
{
	this->a=a;
	this->b=b;
	this->ID=ID;
}


