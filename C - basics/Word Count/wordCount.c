#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

#define True 1
#define False 0

void append(char*, char c);
void check_how_may_diff_words(char*);
int check_if_word_in_array(const char[][20], int, const char*);

int main()
{
	char text[10000];
	FILE *f;
	int ch;
	int len = 0;

	//Open file
	f = fopen("lidor.txt", "r");
	if (f == NULL)
	{
		printf("could not find file\n");
	}
	else
	{
		//Get each char into a string variable
		do {
			ch = fgetc(f);
			text[len] = ch;
			len++;
		} while (ch != EOF && ch != '\0');
		text[len - 1] = ' ';
		text[len] = '\0';
		check_how_may_diff_words(text);
	}
	system("PAUSE");
}

//Add char at the end of string
void append(char* s, char c) 
{
	int len = strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}

//Check if word already in the array
int check_if_word_in_array(const char words_array[][20], int len, const char* word)
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


void check_how_may_diff_words(char* text)
{
	char words[5000][20] = { 0 };
	char curr_word[20] = "";
	int i = 0;
	int words_counter = 0;
	int len = strlen(text);
	
	//For each char
	for (i = 0; i < len; ++i)
	{
		if (text[i] != '\0')
		{
			//If it a letter we will append to curr_word
			if (isalpha(text[i]))
			{
				append(curr_word, text[i]);
			}
			//Else we finish with that word
			else
			{
				//If the word not in the array add it to array and add to count
				if (isalpha(curr_word[0]) && check_if_word_in_array(words, words_counter, curr_word) == False)
				{
					strcpy_s(words[words_counter], 20, curr_word);
					words_counter++;
				}
				curr_word[0] = '\0';
			}
		}
		else
		{
			break;
		}
		
	}

	printf("The number of diffrent words in the string is: %d\n", words_counter);
}
