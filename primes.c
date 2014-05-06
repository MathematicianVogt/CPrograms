#include <stdio.h>
#include <string.h>
#include "points.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <pthread.h>


struct infoHolder
{
	int start;
	int end;
	int threadId;



};
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
void *primeGenerator(void *infoHold)
{	
	struct infoHolder *myinfo=  (struct infoHolder *) infoHold;
	int myStart=myinfo->start;
	int myEnd=myinfo->end;
	int myThreadID = myinfo->threadId;

	printf("Thread #%d results:  ",myThreadID);
	for(int i=myStart; i<myEnd; i++)
	{


		if(isPrime(i))
		{

			printf("%d ", i);


		}

	}





}

int *generateIntervalArray(int start, int end, int numberOfThreads)
{
	
	int *array=malloc(sizeof(int)*numberOfThreads);
	int myIntervals[numberOfThreads];
	int change=(end-start)/numberOfThreads;
	printf("CHANGE%d\n",change );
	for(int i=0; i<numberOfThreads+1;i++)
	{
		array[i]=start+(i*change);



	}
	return array;

}
void execute(int start, int end, int numberOfThreads)
{	int rc;
	void *retval;
	pthread_t threads[numberOfThreads];
	struct infoHolder *myinfo[numberOfThreads];
	int *myInterval=generateIntervalArray(start,end,numberOfThreads);

	


	for(int t = 0; t < numberOfThreads; t++ ) 
	{
		struct infoHolder *currentBody=malloc(sizeof(struct infoHolder));
		
		printf("FIRST%d\n", myInterval[t]);
		printf("second%d\n", myInterval[t+1]);
		currentBody->start=myInterval[t];
		currentBody->end=myInterval[t+1];
		currentBody->threadId=t;
		myinfo[t]=currentBody;
		rc = pthread_create( &threads[t], NULL, primeGenerator,(void*) currentBody);

		if (rc){
		   printf( "ERROR; pthread_create() returned %d\n", rc );
		   exit(-1);
		}
	

	}

	for( int t = 0; t < numberOfThreads; t++ ) {
		pthread_join( threads[t], &retval );
	}
	free(myInterval);
	for(int i=0; i<numberOfThreads; i++)
	{

		free(myinfo[i]);

	}


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
execute(start,end,numberOfThreads);


return 0;
}