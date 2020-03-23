#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

#define SIZE 128

int my_getline(char** buffer, size_t* bufsize, FILE* stream);

int main()
{
	/* Check if function works */
	char *line_buf = NULL;
	int line_count = 0;
	size_t line_size = SIZE;
	FILE *fp = fopen("a.txt", "r");
	if (!fp)
	{
		return EXIT_FAILURE;
	}
	line_buf = (char *)malloc(line_size * sizeof(char));
	printf("%d\n", my_getline(&line_buf, &line_size, fp));
	printf("%s\n", line_buf);
	system("PAUSE");
}

int my_getline(char** buffer, size_t* bufsize, FILE* stream)
{
	/* Function will get line from stream and return the length of the line*/
	char line[SIZE];
	int new_line_index;

	fgets(line, SIZE, stream);

	/* Find the index of new line and replace with null byte*/
	new_line_index = (int)(strchr(line, '\n') - line);
	line[new_line_index] = '\0';
	/* Copy the line to the given buffer */
	strcpy(*buffer, line);
	return strlen(line);
}