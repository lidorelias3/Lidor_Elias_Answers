#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5
#define FALSE 0
#define TRUE !FALSE

char** return_result(char* str);
char* get_number_options(char number, char* options);
char** get_options(char remembered_code[]);
char** all_combinations(char** arr, int length);

int main()
{
	char** options = return_result("1357");

	system("PAUSE");
}


char** return_result(char* str)
{
	/*Combine all the functions and return the result*/
	char** options = get_options(str);
	char** combination_array = all_combinations(options, strlen(str));
	return combination_array;
}


char** get_options(char remembered_code[])
{
	/*Get a password and return the options for the password*/
	int i = 0;
	int j = 0;
	char curr_option[SIZE] = "";

	/*Allocate memory for string array*/
	char **all_options = (char**)malloc(strlen(remembered_code) * sizeof(char*));
	memset(all_options, 0, strlen(remembered_code) * sizeof(char));
	for (i = 0; i < strlen(remembered_code); ++i)
	{
		all_options[i] = (char*)malloc((1 + SIZE) * sizeof(char));
		memset(all_options[i], 0, (1 + SIZE) * sizeof(char));
	}

	/*For each number in password*/
	for (i = 0; i < strlen(remembered_code); ++i)
	{
		/*Get all the option including the same number*/
		strncat(all_options[i], &remembered_code[i], 1);

		get_number_options(remembered_code[i], curr_option);
		for (j = 0; j < strlen(curr_option); ++j)
		{
			if (curr_option[j] != '-')
			{
				strncat(all_options[i], &curr_option[j], 1);
			}
		}
	}
	return all_options;
}



char* get_number_options(char number, char* options)
{
	/*Find the options for a givven number and return a string with the options*/
	char numbers_lock[6][5] = {
		{ '-', '-', '-', '-', '-' },
		{ '-', '1', '2', '3', '-' },
		{ '-', '4', '5', '6', '-' },
		{ '-', '7', '8', '9', '-' },
		{ '-', '-', '0', '-', '-' },
		{ '-', '-', '-', '-', '-' }
	};
	for (int i = 0; i < 6 && strlen(options) == 0; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (numbers_lock[i][j] == number)
			{
				/*Add to options*/
				strncat(options, &numbers_lock[i - 1][j], 1);
				strncat(options, &numbers_lock[i + 1][j], 1);
				strncat(options, &numbers_lock[i][j - 1], 1);
				strncat(options, &numbers_lock[i][j + 1], 1);
				break;
			}
		}
	}

return options;
}


char** all_combinations(char** arr, int length)
{
	int cont = TRUE;
	int i = 0;
	int n = 0;
	int last = 0;
	int* index_arr = (int*)malloc(length * sizeof(int));

	/*Creating the return array*/
	char **combinations = (char**)malloc(sizeof(char*));

	/*Zero all index array*/
	for (i = 0; i < length; ++i)
	{
		index_arr[i] = 0;
	}

	while (cont)
	{
		/*Add the current combination to combinations array*/ 
		combinations = (char**)realloc(combinations, (last + 1) * sizeof(char*));
		combinations[last] = (char*)malloc(length * sizeof(char));
		memset(combinations[last], 0, length);
		for (i = 0; i < length; ++i)
		{
			strncat(combinations[last], &arr[i][index_arr[i]], 1);
		}
		printf("%s\n", combinations[last]);
		last++;

		/*Find the next element*/
		int n = length - 1;
		while (n >= 0 && index_arr[n] >= strlen(arr[n]) - 1)
		{
			n--;
		}
		/*All combination finished*/
		if (n < 0)
		{
			cont = FALSE;
		}
		/*Move to next number in current array*/
		index_arr[n]++;
		/*Reset all rest arrays*/
		for (i = 1 + n; i < length; ++i)
		{
			index_arr[i] = 0;
		}
	}
	return combinations;
}