#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

int my_getline(char** buffer, size_t* bufsize, FILE* stream);

int main()
{
	/* Check if function works */
	char *line_buf = NULL;
	int line_count = 0;
	int file_size = 0;

	FILE *fp = fopen("lidor.txt", "r");
	if (!fp)
	{
		return EXIT_FAILURE;
	}
	/*Get file size*/
	fseek(fp, 0L, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	/*Allocate memory for that file*/
	line_buf = (char *)malloc(file_size*sizeof(char));
	printf("%d\n", my_getline(&line_buf, &file_size, fp));
	printf("%s\n", line_buf);
	
	/*Close file and free memory*/
	fclose(fp);
	free (line_buf);
	system("PAUSE");
	return 0;
}

int my_getline(char** buffer, size_t* bufsize, FILE* stream)
{
	/* Function will get line from stream and return the length of the line*/
	fgets(*buffer, bufsize, stream);

	/* Find the index of new line and replace with null byte*/
	*(buffer + (int)(strchr(*buffer, '\n') - *buffer)) = '\0';

	return strlen(*buffer);
}