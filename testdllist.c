#include "dlList.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_LINE 5
void showCursor(DlList_T myList);
void printList(DlList_T list);
struct node* getHead(DlList_T lst);
struct node* getTail(DlList_T lst);
void getNodeData(struct node* myNode);

		int main(void)
		{

				char* buff = (char*) malloc(sizeof(char) * MAX_LINE);
				size_t n=MAX_LINE;
				DlList_T myList=dll_create();

				printf("ENTER 3 THINGS TO GENERATE LIST\n");
				fgets(buff,MAX_LINE, stdin);
				strtok(buff,"\n");
				void* input=malloc(sizeof(char)*(strlen(buff)));
				memcpy(input,buff,strlen(buff));
				dll_append(myList, input);

				fgets(buff,MAX_LINE, stdin);
				strtok(buff,"\n");
				void* input1=malloc(sizeof(char)*(strlen(buff)));
				memcpy(input1,buff,strlen(buff));
				dll_append(myList, input1);

				fgets(buff,MAX_LINE, stdin);
				strtok(buff,"\n");
				void* input2=malloc(sizeof(char)*(strlen(buff)));
				memcpy(input2,buff,strlen(buff));
				dll_append(myList, input2);

				printList(myList);

			


			return 0;



		}