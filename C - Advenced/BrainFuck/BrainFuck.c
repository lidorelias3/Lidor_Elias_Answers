#include <stdio.h>

#define SIZE 1000

void execute(char* file_name);

int main()
{
	execute("BrainFuck.txt");
	system("PAUSE");
	return 0;
}

void execute(char* file_name)
{
	/*Execute brainfuc code*/
	char brainFuck_arr[SIZE] = { 0 };
	char ch;
	int offset = 0;
	int read_count = 0;
	FILE *f;
	errno_t err;

	if ((err = fopen_s(&f, file_name, "r")) != 0)
	{
		return -1;
	}
	if (f == NULL)
	{
		printf("could not find file\n");
		return;
	}
	else
	{
		/*Reaad file tiil the end and for each char make his operation*/
		do {
			ch = fgetc(f);
			if (ch != '\0')
			{
				switch (ch)
				{
				case '>':
					offset++;
					if (offset > 1000)
					{
						printf("RANGE ERROR");
						return;
					}
					break;
				case '<':
					offset--;
					if (offset < 0)
					{
						printf("RANGE ERROR");
						return;
					}
					break;
				case '+':
					brainFuck_arr[offset]++;
					break;
				case '-':
					brainFuck_arr[offset]--;
					break;
				case ',':
					break;
				case '.':
					printf("%c", brainFuck_arr[offset]);
					break;
				case '[':
					if (brainFuck_arr[offset] == 0)
					{
						/*Move to next ']'*/
						while (ch != ']')
						{
							fseek(f, ++read_count, SEEK_SET);
							ch = fgetc(f);
						}
					}
					break;
				case ']':
					if (brainFuck_arr[offset] != 0)
					{
						/*Move to prev '['*/
						while (read_count > 0 && ch != '[')
						{
							fseek(f, --read_count, SEEK_SET);
							ch = fgetc(f);
						}
					}
					break;


				default:
					break;
				}
			}
			read_count++;
		} while (ch != EOF && ch != '\0');
	}

	printf("\n");
}