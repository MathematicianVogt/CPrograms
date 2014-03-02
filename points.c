// Author Ryan Vogt
//An implmentation of the points header file
//to compile: to compile:	gcc -Wall -std=c99 -o point points.c

#include <stdio.h>
#include <string.h>
#include "points.h"
#include <stdlib.h>
#include <ctype.h>




// Indicates the winding order of the triangle formed by points
// p, q, and r.  In other words, given the line formed by pq,
// is r to the left (ccw), right(cw) or on (collinear) the line.
// @param p First point (usually the "anchor" point)
// @param q Second point
// @param r Third point
// @returns: ccw > 0, cw < 0, coll = 0
int ccw(struct Point p, struct Point q, struct Point r)
{

//#####################

return 0;


}

void displayPoint(struct Point p){



printf("%c: (%d,%d)",p.label,p.x,p.y);

}


int equal(struct Point p1, struct Point p2)
{

	if((p1.x==p2.x) and (p1.y==p2.y))
	{

		return 1

	}

	return 0

}
int indexOf(struct Point p, struct Point points[], int numPoints)
{

//#####################

return 0

}
int readPoints(struct Point points[])
{
	char buff[MAX_LINE];
	printf("Number of points(3-100):");
	int numberOfPoints= getchar() - '0';
	

	if((numberOfPoints<3) or (numberOfPoints>100))
	{

		return 0;

	}





}


int main( void ) {

	printf("%d",MIN_POINTS);
	
		return( 0 );
}