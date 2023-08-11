#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - A program that checks if a random number is
 * positive or negative
 *
 * Return: Always 0 (Succeed)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n > 0)
		printf("%d is positive\n", n);
	else if (n == 0)
		printf("%d is zero\n", n);
	else
		printf("%d is negative\n", n);
	return (0);
}
