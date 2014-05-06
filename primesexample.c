#include <stdio.h>
#include <string.h>
#include "points.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <pthread.h>



int isPrime(int number)
{

	for(int i=2; i<10; i++)
	{
		if(number==i)
		{



		}
		else if(number%i==0)
		{

			return 0;



		}

	}
	return 1;




}
void sieve(startPrime,end)
{
	int startPrimeLoop=startPrime;
	int dummystart=startPrime;
	int size = end-startPrime;
	int possiblePrimeList[size];
	int notDone=1;
	int startIndex=0;
	int count=0;
	for(int i=0; i<size; i++)
	{

		possiblePrimeList[i]=dummystart;
		dummystart++;


	}
	while(count<size)
	{

		for (int i=startIndex; i<size; i=i+startPrimeLoop)
		{	
			//printf("INDEX%d\n", i );
			//printf("ININDEX%d\n", possiblePrimeList[i] );
			if(possiblePrimeList[i]!=0 && i!=startIndex)
			{

				possiblePrimeList[i]=0;
				


			}




		}
		for(int j=startIndex; j<size; j++)
			{
			
				if(possiblePrimeList[j]>startPrimeLoop)
				{
					

					startPrimeLoop=possiblePrimeList[j];
					startIndex=j;
					break;


				}
				

			}

		

		count++;


	}

	for (int i =0; i<size; i++)
		{

			if(possiblePrimeList[i]!=0)
			{
				printf("%d ", possiblePrimeList[i]);
			}

		}


}

void prime(int start,int end, int numberOfThreads)
{
	int firstPrime;

	for(int i=start; i<end; i++)
	{
		if(isPrime(i))
		{

			firstPrime=i;
			break;


		}
	}
	sieve(firstPrime,end);





}


int main(int argc, char *argv[])
{	int start;
	int end;
	int numberOfThreads;

	if(argc<2)
	{

		printf("Usage: primes start end threads\n");
		exit (EXIT_FAILURE);

	}
	else if(argc==2)
	{

		if((end=atoi(argv[1])))
		{
			start=2;
			numberOfThreads=2;


		}
		else
		{

			printf("Unable to convert %s to number.\n",argv[1] );
			exit (EXIT_FAILURE);

		}


	}
	else if(argc==3)
	{


		if((start=atoi(argv[1])))
		{
			start=2;
			numberOfThreads=2;


		}
		else
		{

			printf("Unable to convert %s to number.\n",argv[1] );
			exit (EXIT_FAILURE);

		}
		if((end=atoi(argv[2])))
		{
			


		}
		else
		{

			printf("Unable to convert %s to number.\n",argv[2] );
			exit (EXIT_FAILURE);

		}
		numberOfThreads=2;		






	}
	else
	{

		if((start=atoi(argv[1])))
		{


		}
		else
		{

			printf("Unable to convert %s to number.\n",argv[1] );
			exit (EXIT_FAILURE);

		}
		if((end=atoi(argv[2])))
		{
			


		}
		else
		{

			printf("Unable to convert %s to number.\n",argv[2] );
			exit (EXIT_FAILURE);

		}
		if((numberOfThreads=atoi(argv[3])))
		{
			


		}
		else
		{

			printf("Unable to convert %s to number.\n",argv[3] );
			exit (EXIT_FAILURE);

		}






	}

	prime(start,end,numberOfThreads);


return 0;
}