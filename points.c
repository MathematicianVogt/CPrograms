// Author Ryan Vogt
//An implmentation of the points header file
//to compile: to compile:	gcc -Wall -std=c99 -o point points.c

#include <stdio.h>
#include <string.h>
#include "points.h"
#include <stdlib.h>
#include <ctype.h>




int ccw(struct Point p, struct Point q, struct Point r)
{

//#####################

return 0;


}

void displayPoint(struct Point p){



printf("%c: (%d,%d)",p.label,p.x,p.y);

}


void displayPoints(struct Point points[], int numPoints){

	for(int i=0; i<numPoints; i++)
	{
		struct Point currentPointToShow=points[i];
		printf("%c: (%d,%d)\n",currentPointToShow.label,currentPointToShow.x,currentPointToShow.y);


	}



}


int equal(struct Point p1, struct Point p2)
{

	if(p1.x==p2.x && p1.y==p2.y)
	{

		return 1;

	}

	return 0;

}
int indexOf(struct Point p, struct Point points[], int numPoints)
{
	int indexOfMatch=0;
	for(int i=0;i<numPoints; i++)
	{
		struct Point currentStruct=points[i];

		if(currentStruct.x==p.x && currentStruct.y==p.y)
		{

			return indexOfMatch;

		}

		indexOfMatch++;

	}
	return -1;
}


struct Point leftmostPoint(struct Point points[], int numPoints)
{

	struct Point currentSmallestStruct=points[0];
	for(int i=1; i<numPoints; i++)
	{


		struct Point current=points[i];
		if(current.x<currentSmallestStruct.x)
		{

			currentSmallestStruct=current;



		}
	}


	return currentSmallestStruct;
}

struct Point rightmostPoint(struct Point points[], int numPoints)
{


	struct Point currentLargestStruct=points[0];
	for(int i=1; i<numPoints; i++)
	{


		struct Point current=points[i];
		if(current.x>currentLargestStruct.x)
		{

			currentLargestStruct=current;



		}
	}


	return currentLargestStruct;

}

// Determine the point furthest "left" of the line a->z
// Assumes numPoints is valid.
// @param a Starting point of a line
// @param z Ending point of a line
// @param points A native array of Point's (immutable)
// @param numPoints The number of valid Point's in points
// @return The resulting Point
struct Point furthestLeftPoint(struct Point a, struct Point z, struct Point points[], int numPoints)
{

	struct Point currentSmallestxStruct;
	struct Point currentStruc;
	if(a.x<z.x)
	{
		currentSmallestxStruct=a;


	}
	else
	{

		currentSmallestxStruct=a;


	}

	for(int i =0; i<numPoints; i++)
	{

		currentStruc=points[i];

		if(currentStruc.x<currentSmallestxStruct.x)
		{

			currentSmallestxStruct=currentStruc;

		}



	}

	return currentSmallestxStruct;

}


// Determine the set of points to the "left" of the line formed
// from 'a' to 'z' (a->z).
// Assumes numPoints is valid.
// @param a Starting point of a line
// @param z Ending point of a line
// @param points A native array of Point's (immutable)
// @param numPoints The number of valid Point's in points
// @param lps A native array of Point's (set of Points to the left of a->z)
// @return The number of points in the left point set
int leftPointSet(struct Point a, struct Point z, struct Point points[], int numPoints, struct Point lps[])
{
	int numberOfPointsToTheLeft=0
	int currentLpsele=0
	struct Point pivotX;
	if(a.x<z.x)
	{

		pivotX=a;


	}
	else
	{


		pivotX=z;

	}
	for(int i=0; i<numPoints; i++)
	{

		struct Point currentOne=points[i]
		if(currentOne.x<pivotX.x)
		{

			lps[currentLpsele]=currentOne;
			currentLpsele++;
			numberOfPointsToTheLeft++;



		}




	}
	return numberOfPointsToTheLeft;


}

// Determine the index of the point with the smallest y-coordinate.
// If the lowest y coordinate exists in more than one point in the
// set, the lowest x coordinate out of the candidates should be selected.
// Assumes numPoints is valid.
// @param points A native array of Point's (immutable)
// @param numPoints The number of valid Point's in points
// @return the lowest Point
struct Point lowestPoint(struct Point points[], int numPoints);


int readPoints(struct Point points[])
{
	char buff[MAX_LINE];
	printf("Number of points(3-100):");
	int numberOfPoints= getchar() - '0';
	

	if((numberOfPoints<MIN_POINTS) || (numberOfPoints>MIN_POINTS))
	{
		printf("Number of points must be between 3 and 100.\n");
		return 0;

	}
	printf("Enter label (character):");


return 0;




}

void swap(int a, int b, struct Point points[], int numPoints)
{

	
	if((a<0) || (b<0) || (a>numPoints-1) || (b>numPoints) || (a==b))
	{




	}

	else{
		struct Point P1=points[a];
		struct Point P2=points[b];
		points[a]=P2;
		points[b]=P1;		
	}

}





int main( void ) {

	printf("%d",MIN_POINTS);
	
		return( 0 );
}