#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int count_numbers_as_Words(int number);

int main()
{
	int i = 0;
	int sum = 0;
	for (i = 0; i <= 100; ++i)
	{
		sum += count_numbers_as_Words(i);
	}
	printf("%d\n", sum);
	system("PAUSE");
	return 0;
}


int count_numbers_as_Words(int number)
{
	/*Function will convert the number to a word and return word length*/
	int i = 0;

	int count_letters = 0;
	char *number_as_words = (char*)malloc(sizeof(char));
	
	char *units[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char *teens[] = { "ten","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char *tens_and_hundred[] = { "hundred", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	
	/*If in our range*/
	if (number > 0 && number <= 100)
	{
		/*Allocate memory and find the number string in the arrays*/
		if (number < 10)
		{
			number_as_words = (char*)realloc(number_as_words, (strlen(units[number]) + 1)*(sizeof(char)));
			strcpy_s(number_as_words, strlen(units[number]) + 1, units[number]);
		}
		else if (number >= 10 && number < 20)
		{
			number_as_words = (char*)realloc(number_as_words, (strlen(teens[number % 10]) + 1)*(sizeof(char)));
			strcpy_s(number_as_words, strlen(teens[number % 10]) + 1, teens[number % 10]);
		}
		else if (number == 100)
		{
			number_as_words = (char*)realloc(number_as_words, (strlen(units[1]) + strlen(tens_and_hundred[0]) + 1)*(sizeof(char)));
			strcpy_s(number_as_words, strlen(units[1]) + strlen(tens_and_hundred[0]) + 1, units[1]);
			//strcat(number_as_words, " ");
			strcat_s(number_as_words, strlen(units[1]) + strlen(tens_and_hundred[0]) + 1, tens_and_hundred[0]);
		}
		else
		{
			number_as_words = (char*)realloc(number_as_words, (strlen(tens_and_hundred[(number / 10) - 1]) + strlen(units[number%10]) + 1)*(sizeof(char)));
			strcpy_s(number_as_words, strlen(tens_and_hundred[(number / 10) - 1]) + strlen(units[number % 10]) + 1, tens_and_hundred[(number / 10) - 1]);
			//strcat(number_as_words, "-");
			if (number % 10 != 0)
			{
				strcat_s(number_as_words, strlen(tens_and_hundred[(number / 10) - 1]) + strlen(units[number % 10]) + 1, units[number % 10]);
			}
		}
		printf("%s - %d\n", number_as_words, strlen(number_as_words));
	}
	else
	{
		printf("Your number is not in our range (1 - 100)\n");
		return 0;
	}

	return strlen(number_as_words);

}