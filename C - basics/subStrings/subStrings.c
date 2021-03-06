#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE !FALSE

int call_check_sub_string(char* str1, char* str2);
int check_sub_string(char* str1, char* str2);


int main()
{
	printf("%d\n", call_check_sub_string((char*)"lidoraaaaaaaaaaaaaaa", (char*)"lidoraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	system("PAUSE");
}


int call_check_sub_string(char* str1, char* str2)
{
	/*Function check for both strings*/
	return check_sub_string(str1, str2) || check_sub_string(str2, str1);
}

/* Function will check if sub string in string */
int check_sub_string(char* str1, char* str2)
{
	int i = 0;
	int str2_counter = 0;
	int found = FALSE;

	/* For each char in str1 */
	for (i = 0; i < strlen(str1) && found == FALSE; ++i)
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