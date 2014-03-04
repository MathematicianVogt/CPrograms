// Author Ryan Vogt
//An implmentation of the quickhull algorithm to find the convex hull from a set
//of points P
//to compile: to compile: gcc -Wall -std=c99 -o point points.c
#include <stdio.h>
#include <string.h>
#include "points.h"
#include <stdlib.h>
#include <ctype.h>



void displayConvexPoints(struct Point points[], int numPoints){
   
   printf("Convex Hull:\n");
   for(int i=0; i<numPoints; i++)
   {
       struct Point currentPointToShow=points[i];
       printf("%c: (%d,%d)\n",currentPointToShow.label,currentPointToShow.x,currentPointToShow.y);
       
       
   }
   
   
   
}

//take three arrays of certain pieces and combine them together
//@param bigL array of left elements
//@param bigLsize the size of bigL
//@param bigR the array of right elemeents
//@param bigRsize the size of right eleements array
//@param f  the points furthest from the line
//@param P the original array of points,
//@param PSize the size of P
//@return number of slots filled
int overridePThree(struct Point bigL[],int bigLSize,struct Point bigR[], int bigRsize, struct Point f, struct Point P[])
{
   for(int i=0; i<bigLSize;i++)
   {
       
       P[i]=bigL[i];
       
   }
   P[bigLSize]=f;
   
   for(int i= bigLSize+1; i<bigLSize+1+bigRsize; i++)
   {
       
       
       P[i]=bigR[i-(bigLSize+1)];
       
       
   }
   
   return bigLSize+bigRsize+1;
   
}
//take four arrays of certain pieces and combine them together
//@param bigL array of left elements
//@param bigLsize the size of bigL
//@param bigR the array of right elemeents
//@param bigRsize the size of right eleements array
//@param r the most right point
//@param l the most left point
//@param P the original array of points,
//@param PSize the size of P
//@param the new size of P
int overridePFour(struct Point l, struct Point bigL[],int bigLSize, struct Point r, struct Point bigR[], int bigRsize, struct Point P[])
{
   P[0]=l;
   for(int i =1; i<bigLSize; i++)
   {
       
       P[i]=bigL[i-1];
       
       
   }
   for(int i=bigLSize; i<bigLSize+bigRsize; i++)
   {
       
       
       P[i]=bigR[i-bigLSize];
       
       
       
   }
   P[bigLSize+bigRsize]= r;
   
   return bigLSize+bigRsize+2;
  

  int size=overridePFour(test,mypoints,1,test1, mypoints1, 1,testP);
   
}


//A method that helps the recurisve quickHull algorithm.
//@param P, the original set of points
//@param l the left most point in P
//@param r the right most point in P
void quickHullRec(struct Point points[], struct Point l, struct Point r, int numPoints)
{
   //if p is empty

  else
  {

    struct Point f =furthestLeftPoint(l,r,points,numPoints);
    struct Point L[numPoints];
    int Lsize=leftPointSet(l, r, points,numPoints,L);
    struct Point L(num)


  }
   

   
   
}

//A method that does the quickHull algorithm. Takes a set of points and number of points
//in this set that are valid, find the points in this set and add them to convexHull
//@param points, the set of points, a subset of these points will be the convex hull
//@param numPoints, the number of points in points that are valid
//@param convexHull, this will be manipualted from empty to containing the complex hull
int quickHull(struct Point points[], struct Point convexHull[],int numPoints)
{
   
   struct Point mostLeftPoint=leftmostPoint(points,numPoints);
   struct Point mostRightPoint=rightmostPoint(points,numPoints);
   struct Point bigL[numPoints];
   int bigLnumber=leftPointSet(mostLeftPoint,mostRightPoint,points,numPoints,bigL);
   struct Point bigR[numPoints];
   int bigRnumber=leftPointSet(mostRightPoint,mostLeftPoint,points,numPoints,bigR);
   
   quickHullRec(bigL,mostLeftPoint,mostRightPoint);
   quickHullRec(bigR,mostRightPoint,mostLeftPoint);
   overridePFour(mostLeftPoint,bigL,bigLnumber,mostRightPoint,bigR,bigRnumber,convexHull);
  
   
   
   
   return 0;
   
   
   
   
   
   
   
}


int main(void)
{
  struct Point testP[4];
   struct Point mypoints[1];
   struct Point mypoints1[1];
  struct Point test;
  test.x=3;
  test.y=4;
  test.label='a';
  struct Point test1;
  test1.x=1;
  test1.y=1;
  test1.label='b';
  struct Point test2;
  test2.x=2;
  test2.y=3;
  test2.label='c';
  struct Point test3;
  test3.x=6;
  test3.y=4;
  test3.label='c';
  mypoints[0]=test3;
  mypoints1[0]=test1;
  

  int size=overridePFour(test,mypoints,1,test1, mypoints1, 1,testP);
  displayPoints(testP,size);



   struct Point quickHullPoints[MAX_POINTS];
   int numberOfquickHullPoints=readPoints(quickHullPoints);
   if(numberOfquickHullPoints>0)
   {
   displayPoints(quickHullPoints,numberOfquickHullPoints);
   struct Point convexHullSet[numberOfquickHullPoints];
   int numberOfConvexPoints=quickHull(quickHullPoints,convexHullSet,numberOfquickHullPoints);
   displayConvexPoints(convexHullSet,numberOfConvexPoints);
   }
   
   
   
}