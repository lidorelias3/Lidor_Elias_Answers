#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int my_getline(char** buffer, size_t* bufsize, FILE* stream);

int main()
{
	/* Check if function works */
	FILE *fp;
	errno_t err;
	char *line_buf = NULL;
	int line_count = 0;
	int file_size = 0;

	
	if ((err = fopen_s(&fp, "lidor.txt", "r")) != 0)
	{
		return EXIT_FAILURE;
	}
	/*Get file size*/
	fseek(fp, 0L, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	/*Allocate memory for that file*/
	line_buf = (char *)malloc(file_size*sizeof(char));
	memset(line_buf, 0, file_size);
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
	int i = 0;
	char c = "";
	
	for (i = 0; i < bufsize && c != '\n'; ++i)
	{
		c = getc(stream);
		*(*buffer + i) = c;
	}

	/* Find the index of new line and replace with null byte*/
	*(buffer + (int)(strchr(*buffer, '\n') - *buffer)) = '\0';

	return strlen(*buffer);
}