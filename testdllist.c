#include "dlList.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void showCursor(DlList_T myList);
void printList(DlList_T list);
struct node* getHead(DlList_T lst);
struct node* getTail(DlList_T lst);
void getNodeData(struct node* myNode);

		int main(void)
		{

			DlList_T myList =dll_create();
			int one=1;
			int two=2;
			int three=3;
			int four=4;
			int five=5;
			dll_append(myList,(void *) one);
			dll_append(myList,(void *) two);
			dll_append(myList,(void *) three);
			dll_append(myList,(void *) four);
			dll_append(myList,(void *) five);
			//dll_insert_at(myList,4,(void * ) 76);
			/*dll_pop(myList,1);
			dll_pop(myList,5);
			dll_pop(myList,3);
			*/
			/*
			dll_move_to(myList,1);
			showCursor(myList);
			dll_move_to(myList,3);
			showCursor(myList);
			dll_move_to(myList,257);
			showCursor(myList);
			dll_move_to(myList,1);
			showCursor(myList);
			//getNodeData(getHead(myList));
			//getNodeData(getTail(myList));
*/			//getNodeData(dll_get(myList,2));
			//printf("%d\n",dll_index(myList,(void *) 76) );
			printList(myList);
			//dll_set(myList,4,(void*) 55);
			//printList(myList);
			//printf("SIZE IS %d\n",dll_size(myList));
			
			


			return 0;



		}