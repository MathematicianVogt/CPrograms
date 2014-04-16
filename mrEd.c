#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "dlList.h"

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
				
				printf("%s",buf);
				dll_append(myList,(void *) buf);
			}
		
			printList(myList);
			free(buf);
			fclose(pFile);
		}




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
		
		printf("%s\n", argv[1] );
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