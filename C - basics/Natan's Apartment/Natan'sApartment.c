#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 32
#define FALSE 0
#define TRUE !FALSE

char** return_result(char* str);
char* get_number_options(char number, char* options);
char** get_options(char remembered_code[]);
char** all_combinations(char** arr, int length);

int main()
{
	char** options = return_result("1357");
	for (size_t i = 0; i < 150; i++)
	{
		printf("%s\n", options[i]);
	}
	system("PAUSE");
}


char** return_result(char* str)
{
	/*Combine all the functions and return the result*/
	char** options = get_options(str);
	char** combination_array = all_combinations(options, strlen(str));
	return combination_array;
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


char** get_options(char remembered_code[])
{
	/*Get a password and return the options for the password*/
	int i = 0;
	int j = 0;
	char curr_option[SIZE] = "";
	/*Allocate memory for string array*/
	char **all_options = (char**)malloc(strlen(remembered_code)*sizeof(char*));
	for (i = 0; i < strlen(remembered_code); i++)
	{
		all_options[i] = (char*)malloc(SIZE * sizeof(char));
		memset(all_options[i], 0, SIZE);
	}
	/*For each number in password*/
	for (i = 0; i < strlen(remembered_code); ++i)
	{
		/*Get all the option including the same number*/
		strncat(all_options[i], &remembered_code[i], 1);
		memset(curr_option, 0, SIZE);
		get_number_options(remembered_code[i], curr_option);
		for(j = 0; j < strlen(curr_option); ++j)
		{
			if (curr_option[j] != '-')
			{
				strncat(all_options[i], &curr_option[j], 1);
			}
		}
	}
	return all_options;
}


char** all_combinations(char** arr, int length)
{
	int cont = TRUE;
	int i = 0;
	int n = 0;
	int last = 0;
	int* count_arr = (int*)malloc(length * sizeof(int));

	/*Creating the return array*/
	char **combinations = (char**)malloc(SIZE * SIZE * length * sizeof(char*));
	for (i = 0; i <= SIZE * SIZE * length; i++)
	{
		combinations[i] = (char*)malloc(length * sizeof(char));
		memset(combinations[i], 0, length);
	}

	/*Zero all count array*/
	for (int i = 0; i < length; i++)
	{
		count_arr[i] = 0;
	}

	while (cont)
	{
		/*Add the current combination to combinations array*/ 
		for (i = 0; i < length; i++)
		{
			strncat(combinations[last], &arr[i][count_arr[i]], 1);
		}
		last++;

		/*Find the next element*/
		int n = length - 1;
		while (n >= 0 && (count_arr[n] + 1 >= strlen(arr[n])))
		{
			n--;
		}
		/*All combination finished*/
		if (n < 0)
		{
			cont = FALSE;
		}
		/*Move to next number in current array*/
		count_arr[n]++;
		/*Reset all rest arrays*/
		for (i = n + 1; i < length; i++)
		{
			count_arr[i] = 0;
		}
	}
	return combinations;
}