#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<error.h>
#include<string.h>

#define file_size 3 // Should be 30 but for simplicity 3 is used

int main() {
	FILE *fptr;
	char filename[] = "word_list.txt";
	fptr = fopen(filename, "r");
	char array[file_size*8][6];
	char temp[5];
	int count = 0;
	int word_counter = 0;
	memset(temp, '\0', 5);
	fptr = fopen(filename, "r");
        if (fptr == NULL) {
                perror("Error in opening file");
                exit(1);
        }
	char c;
        c = fgetc(fptr);
	while(c!=EOF)
	{
		if(c == ' ' || c == '\n')
		{
			strcpy(array[word_counter++],temp);
			memset(temp, '\0', 5);
			count = 0;
			c = fgetc(fptr);
			continue;
		}
		temp[count++] = c;
		c = fgetc(fptr);
	}
	strcpy(array[word_counter++], temp);
	printf("Enter word to be searched\n");
        char name[5];
        scanf("%s",name);

	#pragma omp parallel for shared(array, name)
	for(int i=0; i<word_counter; i++)
	{
		if(strcmp(array[i], name) == 0)
		{
			#pragma omp critical
			{
				printf("Character is present\n");
				exit(0);
			}
		}
	}
	printf("Not Found\n");
	fclose(fptr);
	return 0;
}
