#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define True 1
#define False 0

void check_how_many_diff_words(char*);
int check_if_word_in_array(const char **, int, const char*);

int main()
{
	check_how_many_diff_words("aladdin.txt");
	system("PAUSE");
	return 0;
}


//Check if word already in the array
int check_if_word_in_array(const char **words_array, int len, const char* word)
{
	int i = 0;
	for (i = 0; i < len; ++i) 
	{
		if (strcmp(words_array[i], word) == 0)
		{
			return True;
		}
	}
	return False;
}


void check_how_many_diff_words(char* file_name)
{
	FILE* f = fopen(file_name, "r");
	int len = 0;
	char ch;
	int curr_word_length = 0;
	int words_counter = 0;
	int total_length = 0;

	/*Allocating memory*/
	char **words = (char**)malloc(sizeof(char*));
	memset(words, 0, sizeof(char*));
	char* curr_word = (char*)malloc(sizeof(char));
	memset(curr_word, 0, sizeof(char));
	

	if (f == NULL)
	{
		printf("could not find file\n");
		return;
	}
	else
	{
		//Get each char into a string variable
		do {
			ch = fgetc(f);
			len++;
			if (ch != '\0')
			{
				//If it a letter we will append to curr_word
				if (isalpha(ch))
				{
					/*Realloc more memory for current word*/
					curr_word = (char*)realloc(curr_word, curr_word_length * sizeof(char*) + 1);
					curr_word[curr_word_length++] = ch;
					curr_word[curr_word_length] = '\0';
				}
				//Else we finish with that word
				else
				{
					//If the word not in the array add it to array and add to count
					if (isalpha(curr_word[0]) && check_if_word_in_array(words, words_counter, curr_word) == False)
					{
						total_length += curr_word_length;
						/*Allocate more memory*/
						words = (char**)realloc(words,  total_length * sizeof(char*));
						words[words_counter] = (char*)malloc(curr_word_length * sizeof(char) + 1);
						strcpy_s(words[words_counter], curr_word_length + 4, curr_word);
						words_counter++;
					}
					memset(curr_word, 0, curr_word_length);
					curr_word_length = 0;
					curr_word[0] = '\0';
				}
			}
			else
			{
				break;
			}
		} while (ch != EOF && ch != '\0');

	}

	printf("The number of diffrent words in the string is: %d\n", words_counter);

	free(words);
	free(curr_word);
}
