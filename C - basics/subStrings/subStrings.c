#include <stdio.h>
#include <string.h>

#define BUFFER 128
#define FALSE 0
#define TRUE 1

int check_sub_string(char* str1, char* str2);


int main()
{
	check_sub_string("aaaabbbalidorabba", "lidor");
	system("PAUSE");
}

/* Function will check if sub string in string */
int check_sub_string(char* str1, char* str2)
{
	int str2_counter = 0;
	int found = FALSE;

	/* For each char in str1 */
	for (int i = 0; i < strlen(str1) && found == FALSE; ++i)
	{
		if (str2_counter < strlen(str2))
		{
			/* If same char add to counter*/
			if (str1[i] == str2[str2_counter])
			{
				str2_counter++;
			}
			else
			{
				str2_counter = 0;
			}
		}
		else
		{
			found = TRUE;
		}
	}
	return found;
}