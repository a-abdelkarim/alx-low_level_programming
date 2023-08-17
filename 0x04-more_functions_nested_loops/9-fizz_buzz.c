#include <stdio.h>

/**
 * main - print numbers from 0 to 100 but for multiples
 * of 3 print "Fizz" and multiples of 5 print "Buzz".
 * for multiples of both 3 and 5 print "FizzBuzz"
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i > 1)
		{
			printf(" ");
		}

		/**
		 * check if the number is a multiple of both 3 and
		 * 5 by checking if it's divisible by 15
		 */
		if (i % 15 == 0)
		{
			printf("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz");
		}
		else
		{
			printf("%d", i);
		}
	}
	printf("\n");

	return (0);
}
