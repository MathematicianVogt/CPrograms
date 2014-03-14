#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BUFF 100

//defintion of a TreeNode structure
//has three fields
//data the data in this specific tree node
//left a pointer to a left node to the treenode also a treenode
//right a poiinter to a right node to the treenode also a treenode
typedef struct TreeNode {
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
    } TreeNode;

//enum to regard a type of tree transversal for BST
 typedef enum {
        PREORDER,
        INORDER,
        POSTORDER
    } TraversalType;

//a function that takes a root, a list of leaves, and the number of leaves
//-root the root of the BST, assumed to be first element of list
//-elements holds all elements that will be placed in the tree
//-count, the number of elements in the list elements
void build_tree(TreeNode** root, const int elements[], const int count)
{

	for(int i=0; i<count; i++)
	{
		insert(root,elements[i]);

	}



}
//takes a root which is the tree, and goes through the tree until the proper insert can take place
//root, the refrence to the overall root
// x the variable that is to be added to the tree
void insert(TreeNode** root, const int x)
{

   while(*root!=NULL)
   {
		if(x<=(*root)->data)
		{
			root=(*root)->left;
		}
		else{
			root=(*root)->right;
		}

   }

   *root=malloc(sizeof(TreeNode));
   (*root)->data=x;
   (*root)->left=NULL;
   (*root)->right=NULL;
}

//travers through a tree using the root as a starting point based on a type of transversal
//root, the BST
//type the type of transversal to take place, based on ENUM value. 
void traverse(const TreeNode* root, const TraversalType type)
{





}

//main method to make a bst from input
int main(int argc, char *argv[])
 {
 	if(argc<2)
 	{


 		printf("Usage: bst #\n");
 		return 0;


 	}
 	else
 	{
 		if(atoi(argv[1])<=0)
 		{

 			printf("# must be greater than 0\n");
 			return 0;


 		}
 		
 		char buff[MAX_BUFF];
 		int numberOfInputs=atoi(argv[1]);
 		int nodeinputs[numberOfInputs];
 		int counter=0;
 		printf("Enter %d integer values to place in tree:\n", numberOfInputs);

 		while(counter<numberOfInputs)
 		{
 			fgets(buff,MAX_BUFF, stdin);
 			nodeinputs[counter]=atoi(buff);
 			counter++;

		}
		
		printf("Input values:\n");	
		for(int i=0; i<numberOfInputs; i++)
		{

			printf("%d\n",nodeinputs[i]);


		}

		TreeNode* myRoot=NULL;
		build_tree(&myRoot,nodeinputs,numberOfInputs);





 	}





 }