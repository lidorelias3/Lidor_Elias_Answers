#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 100

typedef struct square
{
	int size;
}square;

square* rec2sqr(int rec_x, int rec_y);
int arr_size = 0;

int main()
{
	square* sqr_arr = rec2sqr(5, 3);
	for (int i = 0; i < arr_size; i++)
	{
		printf("%d, ", sqr_arr[i].size);
	}
	printf("\n");
	
	free(sqr_arr);
	system("PAUSE");
	return 0;
}


square* rec2sqr(int rec_x, int rec_y)
{
	/*Function will return the squares we need to cover a rectangle*/
	int i = 0;
	int rec_area = rec_x * rec_y;
	int all_squares_area = 0;
	/*Allocate memory*/
	square* sqr_arr = (square*)malloc(sizeof(square));

	/*While we still have what to cover*/
	while (rec_area - all_squares_area != 0)
	{
		/*If the X bigger then the Y*/
		if (rec_x > rec_y)
		{
			sqr_arr[i].size = rec_y;
			all_squares_area += sqr_arr[i].size * sqr_arr[i].size;
			rec_x -= rec_y;
		}
		/*If the Y bigger then the X*/
		else if (rec_x < rec_y)
		{
			sqr_arr[i].size = rec_x;
			all_squares_area += sqr_arr[i].size * sqr_arr[i].size;
			rec_y -= rec_x;
		}
		else
		{
			sqr_arr[i].size = rec_y;
			all_squares_area += sqr_arr[i].size * sqr_arr[i].size;
		}
		i++;
		arr_size++;
		/*Allocate more memory*/
		sqr_arr = (square*)realloc(sqr_arr, (i + 1) * sizeof(square));
	}
	return sqr_arr;
}