//Ryan Vogt
//mish project to run commands within a program process with the use of fork etc

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#define MAX_LINE  80

	int historyLength=10;
	int currentNumberOfHistoryElements=0;
	int currentCommandNumber=1;
	int notDone=1;
	size_t n=MAX_LINE;
	int verbose=0;


struct pastCommand
{

	char *command;
	char *commandslist[10];
	int commandlistLength;




};

void verboseOn()
{
	verbose=1;


}

void verboseOff()
{	

	verbose=0;
}
void showVerbose(struct pastCommand *entry)
{

	if(entry==NULL)
	{


	}
	else
	{
		int myLength=entry->commandlistLength;
		//char *myCommand=entry->command;
		//printf("LOOKIE %s\n",myCommand);
 
		//printf("Commands #%d: %s\n\n",number, myCommand);
		printf("input command tokens:\n");
		for(int i=0; i<myLength; i++)
		{

			printf("%d:%s\n",i,entry->commandslist[i]);


		}
			printf("\n");
		}


}


int mish_command_name(int argc, char *argv[])
{
	

		


	pid_t id;
	int status;

	id = fork();
	switch( id ) {

	case -1: // the fork() failed
		perror( "fork" );
		exit( EXIT_FAILURE );

	case 0:	// we are the child process


		execvp( argv[0], argv );
		perror("execvp");
		_exit( EXIT_FAILURE );
		break;

	default: // we are the parent
		break;

	}






	// parent will wait for child to exit
	id = wait( &status );
	if (verbose)
		{

			printf("command: ");
			for(int i=0; i<argc; i++)
			{

				printf("%s ",argv[i]);


			}
			printf("\n");
			printf("input command tokens:\n");
			for(int i=0; i<argc; i++)
			{
				printf("%d:%s\n",i,argv[i] );

			}
			printf("waiting for pid %d:",id );
			printf("%s\n",argv[0]);
		}

	if( id < 0 ) {
		perror( "wait" );
	} else {
	
	}


	return 0;

}
void addNewHistory(struct pastCommand *newHistory,struct pastCommand *historyList[])
{
	//char *look = newHistory->command;
	//printf("HEREsad %s\n",look );
	if(currentNumberOfHistoryElements<historyLength)
	{
		for(int i=0; i<historyLength; i++)
		{

			if(historyList[i]==NULL)
			{

				historyList[i]=newHistory;
				currentNumberOfHistoryElements++;
				break;

			}


		}

	}
	else
	{	//printf("GOT HERE %d\n", currentNumberOfHistoryElements );
		
	
		struct pastCommand *temp=historyList[0];
		struct pastCommand *temp1;
		for(int i=0; i<historyLength-1; i++)
		{

			temp1=historyList[i+1];
			historyList[i+1]=temp;
			temp=temp1;
			if(i==historyLength-1)
			{


				free(temp);

			}




		}

		historyList[0]=newHistory;


	}



	


}

void printHelp()
{

	printf("List of Commands:\n Verbose[on|off]: shows info as commands called \n help: what you are looking at right now\n history: the past 10 commands you have entered\n quit: quit the program\n");	



}

void printHistoryElement(struct pastCommand *currentHistory, int number)
{
	

	if(currentHistory==NULL)
	{


	}
	else
	{
	int myLength=currentHistory->commandlistLength;
	char *myCommand=currentHistory->command;
	//printf("LOOKIE %s\n",myCommand);
 
	printf("Commands #%d: %s\n\n",number, myCommand);
	printf("input command tokens:\n");
	for(int i=0; i<myLength; i++)
	{

		printf("arg[%d] :%s\n",i,currentHistory->commandslist[i]);


	}
		printf("\n");
	}


}

void printHistory(struct pastCommand *allHistories[],int length)
{
	for(int i=0; i<length; i++)
	{

		printHistoryElement(allHistories[i],i);


	}



}
void freeHistoryList(struct pastCommand *allHistories[])
{

	for(int i=0; i< historyLength; i++)
	{

		if(allHistories[i]!=NULL)
		{

			free(allHistories[i]);

		}


	}

}
void forkProcess(char* buff, struct pastCommand *allHistory[])
{

	//printf("%s\n", buff );
	char *ptrArray[10];
	int   ptrIndex = 0;
	char *cp = buff;
	ptrArray[ptrIndex++] = cp; 
	while((cp=strchr(cp, ' ')))
   	{
   		*cp='\0';
   		ptrArray[ptrIndex++] = ++cp;
   	} 
   	ptrArray[ptrIndex]=NULL;
	
   	mish_command_name(ptrIndex,ptrArray);
   	struct pastCommand *newGuy=malloc(sizeof(struct pastCommand));
   	newGuy->command=strdup(ptrArray[0]);
   	newGuy->commandlistLength=ptrIndex;

   	for(int i=0; i<ptrIndex; i++)
   	{

   		newGuy->commandslist[i]=strdup(ptrArray[i]);

   	}
   	addNewHistory(newGuy,allHistory);

}

void runProgram()
{	
	struct pastCommand *allCommands[historyLength];
	for(int i=0; i<10; i++)
	{

		allCommands[i]=NULL;

	}
	char* buf = (char*) malloc(sizeof(char) * MAX_LINE);



	while(notDone)
	{
		printf("mish[%d]> ",currentCommandNumber);
		
		int result=getline(&buf, &n, stdin);
		if(result==-1)
		{
			printf("\n");
			exit(EXIT_FAILURE);


		}
		else
		{		
			strtok(buf,"\n");
			//printf("%s\n",buf );	
			if(strcmp(buf,"help")==0)
			{
				printHelp();
				struct pastCommand *current=malloc(sizeof(struct pastCommand));
				current->command=strdup(buf);
				current->commandlistLength=0;
				addNewHistory(current,allCommands);
				currentCommandNumber++;
				if(verbose)
				{

					printf("command: %s\n",buf );
					showVerbose(current);
					printf("command status:%d\n",currentCommandNumber);



				}


			}
			
			else if(strcmp(buf, "")==0)
			{

				printf("EMPTY\n");

			}
			else if(strcmp(buf,"verbose on")==0)
			{

				verboseOn();
				struct pastCommand *current=malloc(sizeof(struct pastCommand));
				current->command=strdup(buf);
				current->commandlistLength=0;
				addNewHistory(current,allCommands);
				currentCommandNumber++;
				if(verbose)
				{

					printf("command: %s\n",buf );
					showVerbose(current);
					printf("command status:%d\n",currentCommandNumber);



				}


			}
			else if(strcmp(buf,"verbose off")==0)
			{


				verboseOff();
				struct pastCommand *current=malloc(sizeof(struct pastCommand));
				current->command=strdup(buf);
				current->commandlistLength=0;
				addNewHistory(current,allCommands);
				currentCommandNumber++;
				if(verbose)
				{

					printf("command: %s\n",buf );
					showVerbose(current);
					printf("command status:%d\n",currentCommandNumber);



				}

			}
			else if(strncmp(buf, "verbose", strlen("verbose")) == 0)
			{

				printf("usage: verbose [on|off]\n");
				currentCommandNumber++;


			}
			
			else if(strcmp(buf,"quit")==0)
			{

				free(buf);
				freeHistoryList(allCommands);
				exit(EXIT_SUCCESS);



			}
			else if(strcmp(buf,"history")==0)
			{

				printHistory(allCommands,currentNumberOfHistoryElements);
				struct pastCommand *current=malloc(sizeof(struct pastCommand));
				current->command=strdup(buf);
				current->commandlistLength=0;
				addNewHistory(current,allCommands);
				currentCommandNumber++;


			}
			else
			{


				forkProcess(buf,allCommands);
				currentCommandNumber++;
				if(verbose)
				{
				printf("command status: %d\n",currentCommandNumber);
				}
			}




		}
		



		


	}




}


int main(int argc, char *argv[])
{

	runProgram();
	return 0;


}