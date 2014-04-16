// Demonstrates fprintf

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: main filename\n");
		exit(EXIT_FAILURE);
	}

	FILE* pFile = fopen(argv[1], "w");
	if (!pFile) {
		perror("The following error occurred:");
	} else {
		int age = 32;
		char gender = 'M';
		char name[] = "Fred";

		fprintf(pFile, "Name: %s, Gender: %c, Age: %d\n", name, gender, age);
		fprintf(pFile, "Name: , Gender: , Age:\n");
		fclose(pFile);
	}

	return EXIT_SUCCESS;
}

bool file_exists(const char * filename)
{
    if (FILE * file = fopen(filename, "r")) //I'm sure, you meant for READING =)
    {
        fclose(file);
        return true;
    }
    return false;
}