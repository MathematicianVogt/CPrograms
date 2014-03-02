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



int leftPointSet(struct Point a, struct Point z, struct Point points[], int numPoints, struct Point lps[])
{
	int numberOfPointsToTheLeft=0;
	int currentLpsele=0;
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

		struct Point currentOne=points[i];
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
struct Point lowestPoint(struct Point points[], int numPoints)
{	

	
	struct Point goodY[numPoints];
	int goodYEle=0;
	struct Point smallestY=points[0];
	for(int i=0; i<numPoints; i++)
	{
		struct Point currentStruc= points[i];

		if(currentStruc.y<smallestY.y)
		{
			goodYEle=0;
			memset(goodY, 0, sizeof(goodY));
			smallestY=currentStruc;

		}

		if(currentStruc.y==smallestY.y)
		{

			goodY[goodYEle]=currentStruc;
			goodY[goodYEle+1]=smallestY;
			goodYEle=goodYEle+2;



		}



	}

	if(goodY==NULL)
	{


		return smallestY;

	}
	else
	{
		struct Point smallestx=goodY[0];
		for(int i =1; i<goodYEle; i++)
		{
			struct Point currentStruc=points[i];
			if(currentStruc.x<smallestx.x)
			{


				smallestx=currentStruc;


			}



		}
		return smallestx;


	}










}


int readPoints(struct Point points[])
{	char currentLabel;
	int currentX;
	int  currentY;
	int pointsEle=0;
	int counter=0;
	int inputCounter=1;
	char buff[MAX_LINE];
	printf("Number of points(3-100):");
	fgets(buff, MAX_LINE, stdin);
	int numberOfPoints= atoi(buff);
	printf("%d",numberOfPoints);
	printf("%d",numberOfPoints<MIN_POINTS );
	printf("%d",numberOfPoints);

	

	if(numberOfPoints<MIN_POINTS || numberOfPoints>MAX_POINTS)
	{
		printf("Number of points must be between 3 and 100.\n");
		return 0;

	}
	
	while(counter<numberOfPoints)
	{

		if(inputCounter==1)
		{

			printf("Enter label (character): ");
			if(fgets(buff, MAX_LINE, stdin))
			{

				currentLabel=buff[0];
				inputCounter++;

			}
			else
			{
				printf("\nError reading point label.\n");
				return 0;

			}
			
		
		}

		else if(inputCounter==2)
		{

			printf("Enter x (int): ");
			if(fgets(buff, MAX_LINE, stdin))
			{
			currentX=atoi(buff);
			inputCounter++;
			}
			else
			{
				printf("\nError reading x coordinate.\n");
				return 0;

			}





		}

		else
		{

			printf("Enter y (int): ");
			if(fgets(buff, MAX_LINE, stdin))
			{
				currentY=atoi(buff);
			points[pointsEle].label=currentLabel;
			points[pointsEle].x=currentX;
			points[pointsEle].y=currentY;
			pointsEle++;
			inputCounter=1;
			counter++;
			}
			else
			{

				printf("\nError reading y coordinate.\n");
				return 0;



			}

		}
		

	}

	printf("\n");
	return numberOfPoints;




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

	struct Point myPoints[5];
	struct Point test;
	test.label='a';
	test.x=6;
	test.y=1;
	struct Point test1;
	test1.label='b';
	test1.x=10;
	test1.y=3;
	struct Point lps[5];
	int mypoints=readPoints(myPoints);
	displayPoints(myPoints,mypoints);
	printf("%d\n",indexOf(test,myPoints,mypoints));
	displayPoint(leftmostPoint(myPoints,mypoints));
	displayPoint(rightmostPoint(myPoints,mypoints));
	displayPoint(furthestLeftPoint(test,test1,myPoints,mypoints));
	int here=leftPointSet(test,test1,myPoints,mypoints,lps);
	displayPoints(lps,here);
	
		return( 0 );
}