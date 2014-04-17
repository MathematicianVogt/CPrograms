#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "dlList.h"
#include <string.h>

#define MAX_LINE 50



	void printList(DlList_T list);
	void showCursor(DlList_T myList);
	struct node* getNext(DlList_T lst);
	int getCursorNumber(DlList_T lst);
	struct node* getPrevious(DlList_T lst);
	struct node* getHead(DlList_T lst);
	void printListForward(DlList_T lst);
	struct node* nextNode(struct node* thisNode);
	void* getData(struct node* thisNode);

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

	
	void startLookingforInput(DlList_T lst,const char * filename)
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
			else if(strcmp(buff,".")==0)
			{
				showCursor(lst);

			}

			else if(strcmp(buff,"a")==0)
			{

				int currentlooping=1;
				while(currentlooping)
				{
					fgets(buff,MAX_LINE, stdin);
					strtok(buff,"\n");
					if(strcmp(buff,".")==0)
					{
						
						break;

					}
					else
					{
					
						void* input=malloc(sizeof(char)*(strlen(buff)));
						memcpy(input,buff,strlen(buff));
						dll_append(lst, input);
						dll_move_to(lst,dll_size(lst));
						hasChanged=1;
						//printf("SIZE %d\n",dll_size(lst) );
						//showCursor(lst);
						//printList(lst);

					}



				}



			}
			
			else if(strcmp(buff, "\n")==0 || strcmp(buff,"+")==0)
			{
				if(getNext(lst)!=NULL)
				{

					dll_move_to(lst,getCursorNumber(lst) +1);



				}
				else
				{
					printf("?\n" );

				}
				

			}
			else if(strcmp(buff,"-")==0)
			{

				if(getPrevious(lst)!=NULL)
				{

					dll_move_to(lst,getCursorNumber(lst) -1);



				}



			}
			else if(strcmp(buff,"$")==0)
			{

				if(getHead(lst)==NULL)
				{

					printf("?\n");

				}
				else
				{

				dll_move_to(lst,dll_size(lst));
				showCursor(lst);
				}

			}
			//NEEDS WORKS
			else if(isdigit(buff))
			{	printf("GOT HERE\n");
				int newIndex=atoi(buff);
				if(newIndex>=1 && newIndex<=dll_size(lst))
				{

					dll_move_to(lst,newIndex);

				}



			}
			else if(strcmp(buff,".=")==0)
			{


				printf("%d\n",getCursorNumber(lst));

			}
			else if(strcmp(buff,"$=")==0)
			{

				printf("%d\n",dll_size(lst));


			}
			else if(strcmp(buff,"p")==0)
			{
				printListForward(lst);
				dll_move_to(lst,dll_size(lst));


			}
			else if(strcmp(buff,"q")==0)
			{

				if(hasChanged)
				{

					printf("? buffer dirty\n");

				}
				else
				{

					dll_destroy(lst);
					printf("\n");
					printf("Bye\n");
					break;



				}



			}
			else if(strcmp(buff,"w")==0)
			{


				FILE* pFile = fopen(filename, "w");
				if (!pFile) {
					perror("The following error occurred:");
				} else {
					struct node* headNode=getHead(lst);

					while(headNode!=NULL)
					{
						
						fprintf(pFile, strcat((char *) (getData(headNode)),"\n"));
						headNode=nextNode(headNode);
					
					
					}
					printf("%s:file\n",filename );
					hasChanged=0;
					fclose(pFile);


			}


			}
			else if(strcmp(buff,"wq")==0)
			{
				FILE* pFile = fopen(filename, "w");
				if (!pFile) {
					perror("The following error occurred:");
				} 
				else {
					struct node* headNode=getHead(lst);

					while(headNode!=NULL)
					{
						
						printf("%s\n", (char *) (getData(headNode)) );
						fprintf(pFile, strcat((char *) (getData(headNode)),"\n"));
						headNode=nextNode(headNode);
					
					
					}
					printf("%s:file\n",filename );
					hasChanged=0;
					fclose(pFile);
					dll_destroy(lst);
					printf("\n");
					printf("Bye\n");
					break;





				}
			}
			else if(strcmp(buff,"i")==0)
			{	
				printf("HIT\n");
		
				int looping=1;
				while(looping)
				{
					fgets(buff,MAX_LINE, stdin);
					printf("HERE\n");
					printf(" HERE DUDE %s\n",buff );
					printf("%d\n",strcmp(buff,".") );
					
					if(strcmp(buff,".")==10)
					{
						printf("DONE\n");
						break;

					}
					else
					{
						printf("THE DATA %s\n", buff );
						dll_insert_at(lst,getCursorNumber(lst),(void *) buff);
						dll_move_to(lst,getCursorNumber(lst));


					}
	

				}
				
				
	



			}
			else if(strcmp(buff,"d")==0)
			{
				printf("HITIN\n");
				dll_pop(lst,getCursorNumber(lst));



			}
			else 
			{
				printf(" LOOK %s\n",buff );
			}
}
}
	
	void readAndCreateStruct(const char * filename)
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
				printf("%s\n",buf );
				memcpy(input,buf,strlen(buf));
				dll_append(myList, input);
			}
		
			//printList(myList);
			free(buf);
			fclose(pFile);
		}
		dll_move_to(myList,dll_size(myList));
		startLookingforInput(myList,filename);




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