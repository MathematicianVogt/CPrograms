#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "dlList.h"
#include <string.h>

#define MAX_LINE 50



	void printList(DlList_T list);

	bool file_exists(const char * filename)
	{
	    
	    FILE *fp = fopen(filename,"r");
		if( fp ) {
			return 1;
			fclose(fp);
		} 
		else {
			return 0;
		}
	}

	
	void startLookingforInput(DlList_T lst)
	{
		int hasChanged=0;
		int looping=1;
		char buff[MAX_LINE];
		while(looping)
 		{
 			fgets(buff,MAX_LINE, stdin);
 			strtok(buff,"\n");
			if(strcmp(buff,"Q")==0)
			{

				dll_destroy(lst);
				break;



			}
			else if(strcmp(buff,"a")==0)
			{

				int currentlooping=1;
				while(currentlooping)
				{
					fgets(buff,MAX_LINE, stdin);
					strtok(buff,"\n");
					printf("THIS %s\n",buff );
					if(strcmp(buff,".")==0)
					{
						printf("DONE\n");
						break;

					}
					else
					{
					
						void* input=malloc(sizeof(char)*(strlen(buff)));
						memcpy(input,buff,strlen(buff));
						dll_append(lst, input);
						printList(lst);

					}



				}



			}
			
			else if(strcmp(buff, "\n")==0 || strcmp(buff,"+")==0)
			{

				break;

			}

		}

		printf("DONE\n");



	}
	DlList_T readAndCreateStruct(const char * filename)
	{
		
		DlList_T myList=dll_create();
		FILE* pFile = fopen(filename, "r");
		if (!pFile) {
			perror("The following error occurred:");
		} 
		else {
			char* buf = (char*) malloc(sizeof(char) * MAX_LINE);
			size_t n=MAX_LINE;
			


			while(getline(&buf, &n, pFile)!=-1)
			{	
				strtok(buf,"\n");
				void* input=malloc(sizeof(char)*(strlen(buf)));
				memcpy(input,buf,strlen(buf));
				dll_append(myList, input);
			}
		
			printList(myList);
			free(buf);
			fclose(pFile);
		}
		dll_move_to(myList,dll_size(myList));
		startLookingforInput(myList);




	}
	void hasExplictparam(const char * filename)
	{
		
		readAndCreateStruct(filename);


	}	
	void noExplictparam()
	{


	}

	int main(int argc, char *argv[])
	{
		
		//printf("%s\n", argv[1] );
		if(argc<2)
		{


			noExplictparam();


		}
		else
		{

			if(file_exists(argv[1]))
			{
				hasExplictparam(argv[1]);

			}
			else
			{
				printf("could not read ﬁle ’actual-ﬁle-name\n");

			}

			

		}
		return 0;




	}