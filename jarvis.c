// Author Ryan Vogt
//An implmentation of the jarvis algorithm to find the convex hull from a set of points P
//to compile: to compile:	gcc -Wall -std=c99 -o point points.c
#include <stdio.h>
#include <string.h>
#include "points.h"
#include <stdlib.h>
#include <ctype.h>



//
void displayConvexPoints(struct Point points[], int numPoints){

	printf("Convex Hull:\n");
	for(int i=0; i<numPoints; i++)
	{
		struct Point currentPointToShow=points[i];
		printf("%c: (%d,%d)\n",currentPointToShow.label,currentPointToShow.x,currentPointToShow.y);


	}



}
//A method that does the jarvis algorithm. Takes a set of points  and number of points
//in this set that are valid, find the points in this set and add them to convexHull
//@param points, the set of points, a subset of these points will be the convex hull
//@param numPoints, the number of points in points that are valid
//@param convexHull, this will be manipualted from empty to containing the complex hull
int jarvis(struct Point points[], struct Point convexHull[],int numPoints)
{
	struct Point pointOnHull=leftmostPoint(points,numPoints);
	int i=0;
	struct Point endPoint;
	endPoint.x=points[0].x;
	endPoint.y=points[0].y;
	convexHull[i]=pointOnHull;

	while(!equal(endPoint,convexHull[0]))
	{
	printf("HERTE");
	convexHull[i]=pointOnHull;
	displayPoint(convexHull[i]);
	endPoint=points[0];
	for(int j=1; j<numPoints; j++)
	{

		if(equal(endPoint,pointOnHull) || (ccw(convexHull[i], endPoint,points[j])>0))
		{
			displayPoint(points[i]);
			endPoint=points[j];

		}
		i++;
		pointOnHull=endPoint;

	}
	}
	


	return 0;









}

int main(void)
{
struct Point jarvisPoints[MAX_POINTS];
int numberOfjarvicPoints=readPoints(jarvisPoints);
displayPoints(jarvisPoints,numberOfjarvicPoints);
struct Point convexHullSet[numberOfjarvicPoints];
int numberOfConvexPoints=jarvis(jarvisPoints,convexHullSet,numberOfjarvicPoints);
//displayConvexPoints(convexHullSet,numberOfConvexPoints);




}