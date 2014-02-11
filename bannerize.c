

//@author Ryan Vogt
//A simple program that will bannerize
//A phase bordered with a specific character
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int makeBanner(char borderChar, char *myString[], int numberOfargc)
{
	
	int numberOfchar=3;
	for(int j=1; j<numberOfargc; j++)
	{

		numberOfchar=numberOfchar+strlen(myString[j])+1;

	}
	

	for(int k=0; k<numberOfchar; k++)
	{

		printf("%c", borderChar);


	}
	printf("%s","\n" );

	printf("%c",borderChar );
	printf("%c", ' ' );
	for(int i=1; i<numberOfargc; i++)
	{

		printf("%s",myString[i]);
		printf("%c", ' ');
	}
	printf("%c",borderChar );
	printf("%c", ' ' );
	printf("%s","\n" );

	for(int k=0; k<numberOfchar; k++)
	{

		printf("%c", borderChar);


	}
	printf("%s","\n" );


	return EXIT_SUCCESS;

}


int main(int argc, char *argv[])
 {
 	
 	
 	if(argc<2)
 	{
 	printf("%s", "usage: bannerize text to bannerize...\n");
 	}
 	else
 	{
 		printf("%s","Enter the character for the border: ");
 		char myBorderChar=getchar();
 		makeBanner(myBorderChar,argv,argc);

 	}
 	
 	return EXIT_FAILURE;

 }