#include <stdio.h>

int main()
{
	/*Check for the first 10 fibonacci numbers*/
	for (int i = 0; i <= 10; ++i)
	{
		printf("%d\n", calc_fibonacci(i));
	}
	system("PAUSE");
}

int calc_fibonacci(int n)
{
	/*Function will return the N number in fibonacci sequence using recursive*/
	int next = 0;
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	next = calc_fibonacci(n - 1) + calc_fibonacci(n - 2);
	return next;
}