#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

	
	struct cursor
	{

		struct node* currentNodeLocation;
		int currentNodeNumber;


	} ;
	struct node{

		void *data;
		struct node* previous;
		struct node* next;
	};

	struct doubleLinkedList {
		struct node* headOfQueue;
		struct cursor* myCurrentNodeLocation;


	};


	typedef struct doubleLinkedList *DlList_T;
	#define _DLL_IMPL_
	#include "dlList.h"
	DlList_T dll_create( void )
	{
		DlList_T newList;
		newList= (DlList_T) malloc(sizeof(struct doubleLinkedList));
		newList->headOfQueue=NULL;
		struct cursor* myCur=  (struct cursor*) malloc(sizeof(struct cursor));
		newList->myCurrentNodeLocation=myCur;
		(newList->myCurrentNodeLocation)->currentNodeLocation=NULL;
		(newList->myCurrentNodeLocation)->currentNodeNumber=0;


		return newList;

	}
	//takes a node and prints the data in it
	//@param mynode, the node to be printined

	void getNodeData(struct node* myNode)
	{


			printf("%d\n",(int) myNode->data );

	}

	void dll_append( DlList_T lst, void *data )
	{
		
		
		if(lst->headOfQueue==NULL)
		{
			struct node* newNode= (struct node*) malloc(sizeof(struct node));
			lst->headOfQueue=newNode;
			newNode->data=data;
			newNode->previous=NULL;
			newNode->next=NULL;




		}
		else
		{	
			struct node* currentNode=lst->headOfQueue;
			while(currentNode->next!=NULL)
			{

				currentNode=currentNode->next;

			}
			struct node* newNode= (struct node*) malloc(sizeof(struct node));
			newNode->data=data;
			newNode->next=NULL;
			newNode->previous=currentNode;
			currentNode->next=newNode;




		}
		


	}



	void printList(DlList_T list)
	{
		
		struct node* currentNode = list->headOfQueue;
		if(currentNode==NULL)
		{

			printf("Nothing in list\n");

		}
		else
		{
			struct node* backwardStart=NULL;
			

			printf("FORWARD:\n");
			while(currentNode!=NULL)
			{

				if(currentNode->next==NULL)
				{
				
					backwardStart=currentNode;

				}

				printf("%s\n", (char *) (currentNode->data) );
				currentNode=currentNode->next;




			}
			printf("BACKWARDS\n");
			while(backwardStart!=NULL)
			{

				printf("%s\n",  (char *) (backwardStart->data) );
				backwardStart=backwardStart->previous;



			}



		}

		}
		int dll_size( DlList_T lst )
		{
			struct node* currentNode;
			int size=0;
			if(lst->headOfQueue==NULL)
			{
				return size;

			}
			else
			{
			
				currentNode=lst->headOfQueue;

				while(currentNode!=NULL)
				{


					size++;
					currentNode=currentNode->next;

				}


				return size;

			}



		}
		void dll_clear( DlList_T lst )
		{
			struct node* currentNode=lst->headOfQueue;

			while(currentNode!=NULL)
			{
				if(currentNode->next==NULL)
				{
					printf("FREED %d\n", (int )currentNode->data );
					free(currentNode);
					break;


				}

				struct node* nextNode=currentNode->next;
				printf("FREED %d\n", (int )currentNode->data );
				free(currentNode);
				currentNode=nextNode;
			}
			(lst->myCurrentNodeLocation)->currentNodeLocation=NULL;
			(lst->myCurrentNodeLocation)->currentNodeNumber=0;
			lst->headOfQueue=NULL;





		}

		void dll_destroy( DlList_T lst )
		{
			dll_clear(lst);
			free(lst->myCurrentNodeLocation);
			free(lst);




		}
		bool dll_empty( DlList_T lst )
		{

			if(lst->headOfQueue==NULL)
			{
				return 1;

			}
			else
			{

				return 0;
			}

		}
		
		//when the cursor is below the intended moving spot in the list.
		bool goingUp(DlList_T lst,int indx,int decisionNumber)
		{

			if((lst->myCurrentNodeLocation)->currentNodeLocation==NULL)
			{
				struct node* currentNodePointer=lst->headOfQueue;

				for(int i=1; i<decisionNumber; i++)
				{

					currentNodePointer=currentNodePointer->next;

				}
				lst->myCurrentNodeLocation->currentNodeLocation=currentNodePointer;
				lst->myCurrentNodeLocation->currentNodeNumber=indx;
				return 1;
			}
			else
			{

				struct node* currentNodePointer=lst->headOfQueue;

				for(int i=0; i<decisionNumber; i++)
				{

					currentNodePointer=currentNodePointer->next;

				}
				lst->myCurrentNodeLocation->currentNodeLocation=currentNodePointer;
				lst->myCurrentNodeLocation->currentNodeNumber=indx;
				return 1;


			}

		}
		//when the cursor is above the move location, then this will take it there.
		bool goingDown(DlList_T lst, int indx,int decisionNumber)
		{	
			struct node* currentNodePointer=(lst->myCurrentNodeLocation)->currentNodeLocation;

			for(int i=0; i<-(decisionNumber); i++)
			{

				currentNodePointer=currentNodePointer->previous;

			}
			lst->myCurrentNodeLocation->currentNodeLocation=currentNodePointer;
			lst->myCurrentNodeLocation->currentNodeNumber=indx;
			return 1;



		}


		bool dll_move_to( DlList_T lst, int indx )
		{
			if(indx<1 || indx>dll_size(lst))
			{


				return 0;


			}
			else
			{
				int currentNodePosition=(lst->myCurrentNodeLocation)->currentNodeNumber;
				int decisionNumber=indx-currentNodePosition;
				if(decisionNumber==0)
				{

					return 0;


				}
				else if(decisionNumber>0)
				{

					goingUp(lst,indx,decisionNumber);

				}
				else
				{

					goingDown(lst,indx,decisionNumber);

				}



				return 0;




			}

		


		
		}
	
		//takes a list and prints out the state of the cursor associated with it. 
		//@param mylist, the list that holds a cursor
		void showCursor(DlList_T myList)
		{


			printf("DATA IN CURSOR %d\n",(int) ((myList->myCurrentNodeLocation)->currentNodeLocation)->data);
			printf("POINT SPACE %d\n",(int) (myList->myCurrentNodeLocation)->currentNodeNumber);


		}
		
		//takes a link list and returns the first link(head) of the list
		//@param lst the linked list
		//@param return the head of the linked list.
		struct node* getHead(DlList_T lst)
		{

			return lst->headOfQueue;


		}
		
		//take a link list and returns the last link of the list
		//@param lst, the link list
		//@return pointer to node which is the last link in the list
		struct node* getTail(DlList_T lst)
		{

			struct node* currentNode = lst->headOfQueue;
			while(currentNode!=NULL)
			{

				if(currentNode->next==NULL)
				{

					break;

				}
				currentNode=currentNode->next;

			}
			return currentNode;
		}
		


		int dll_has_next( DlList_T lst )
		{

			if(((lst->myCurrentNodeLocation)->currentNodeLocation)->next==NULL)
			{


				return 0;

			}
				return 1;


		}
		void * dll_next( DlList_T lst )
		{

			struct node* currentNode=(lst->myCurrentNodeLocation)->currentNodeLocation;
			lst->myCurrentNodeLocation->currentNodeLocation=((lst->myCurrentNodeLocation)->currentNodeLocation)->next;
			return currentNode;

		}
		void * dll_prev( DlList_T lst )
		{

			struct node* currentNode=(lst->myCurrentNodeLocation)->currentNodeLocation;
			lst->myCurrentNodeLocation->currentNodeLocation=((lst->myCurrentNodeLocation)->currentNodeLocation)->previous;
			return currentNode;

		}
		void dll_insert_at( DlList_T lst, int indx, void *data )
		{


			if(indx>=0 && indx<=dll_size(lst))
			{
				
				struct node* newNode;
				if(indx==0)
				{

					newNode= (struct node*) malloc(sizeof(struct node));
					newNode->data=data;
					newNode->next=getHead(lst);
					newNode->previous=NULL;
					(lst->headOfQueue)->previous=newNode;
					lst->headOfQueue=newNode;
					(lst->myCurrentNodeLocation)->currentNodeLocation=newNode;
					(lst->myCurrentNodeLocation)->currentNodeNumber=1;

				}
				else if(indx==dll_size(lst))
				{
					newNode= (struct node*) malloc(sizeof(struct node));
					struct node* tail=getTail(lst);
					struct node* previousOftail=tail->previous;
					newNode->data=data;
					newNode->next=tail;
					tail->previous=newNode;
					previousOftail->next=newNode;
					newNode->previous=previousOftail;
					(lst->myCurrentNodeLocation)->currentNodeLocation=newNode;
					(lst->myCurrentNodeLocation)->currentNodeNumber=dll_size(lst);


				}
				else
				{
					dll_move_to(lst,indx);
					showCursor(lst);
					struct node* place = (lst->myCurrentNodeLocation)->currentNodeLocation;
					struct node* previousPlace=place->previous;
					
					
					newNode=(struct node*) malloc(sizeof(struct node));
					newNode->data=data;
					newNode->previous=previousPlace;
					newNode->next=place;
					place->previous=newNode;
					previousPlace->next=newNode;
					(lst->myCurrentNodeLocation)->currentNodeLocation=newNode;
					(lst->myCurrentNodeLocation)->currentNodeNumber=indx;

				}




			}




		}
		void * dll_get( DlList_T lst, int indx )
		{

			struct node* currentNode=lst->headOfQueue;
			for(int i=1; i<indx; i++)
			{

				currentNode=currentNode->next;


			}
			return currentNode->data;




		}
		void * dll_pop(DlList_T lst, int indx)
		{
		
			dll_move_to(lst,indx);
			struct node* previous = ((lst->myCurrentNodeLocation)->currentNodeLocation)->previous;
			struct node* next=((lst->myCurrentNodeLocation)->currentNodeLocation)->next;
			void * popData=NULL;
			//getNodeData(previous);
			//getNodeData(next);
			
			
			if(previous==NULL)
			{
				lst->headOfQueue=next;
				(lst->headOfQueue)->previous=NULL;
				void * popData=((lst->myCurrentNodeLocation)->currentNodeLocation)->data;
				free((lst->myCurrentNodeLocation)->currentNodeLocation);
			}
			
			else if(next==NULL)
			{

				void * popData=((lst->myCurrentNodeLocation)->currentNodeLocation)->data;
				previous->next=NULL;
				free((lst->myCurrentNodeLocation)->currentNodeLocation);


			}
			else
			{
				void * popData=((lst->myCurrentNodeLocation)->currentNodeLocation)->data;
				previous->next=next;
				next->previous=previous;
				free((lst->myCurrentNodeLocation)->currentNodeLocation);
			}
			return popData;

	

		}
		int dll_index( DlList_T lst, void *data )
		{
			struct node* currentNode = lst->headOfQueue;

			if(currentNode==NULL)
			{

				return -1;

			}
			int counter=1;
			while(currentNode!=NULL)
			{

				if(currentNode->data==data)
				{

					return counter;



				}
				else if(currentNode->next==NULL)
				{

					return -1;
				}
				currentNode=currentNode->next;
				counter++;



			}





		}
		void * dll_set( DlList_T lst, int indx, void *data )
		{

			struct node* currentNode = lst->headOfQueue;
			int count=1;
			while(currentNode!=NULL)
			{

				if(count==indx)
				{

					currentNode->data=data;
					break;



				}
				currentNode=currentNode->next;
				count++;



			}

			return currentNode;




		}