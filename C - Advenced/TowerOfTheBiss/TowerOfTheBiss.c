#include <stdio.h>

void tower_of_the_biss(int disk_number, char source, char help, char target);


int main()
{
	tower_of_the_biss(3, 'A', 'B', 'C');
	system("PAUSE");
	return 0;
}

void tower_of_the_biss(int number_of_disks, char source, char help, char target)
{
	/*Recursive function to solve tower of hanoi*/
	if (number_of_disks == 1)
	{
		printf("move disk %d from %c to %c\n", number_of_disks, source, target);
	}
	else
	{
		tower_of_the_biss(number_of_disks - 1, source, target, help);
		printf("move disk %d from %c to %c\n", number_of_disks, source, target);
		tower_of_the_biss(number_of_disks - 1, help, source, target);
	}
}