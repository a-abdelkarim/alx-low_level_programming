#include <stdio.h>

int isprime(long n);

/**
 * main - prints the largest prime factor of 612852475143
 * Return: Always 0 (Success)
 */

int main(void)
{
	long n = 612852475143;
	long g;
	long i;

	i = 2;
	g = n / i;
	while (i <= g)
	{
		g = n / i;
		if (n % g == 0 && isprime(g) == 1)
		{
			printf("%li\n", g);
		}
		i++;
	}
	return (0);
}

/**
 * isprime - checks if the number is a prime number
 * @n: the number to check
 * Return: 1 if the number is a prime number, otherwise 0
 */

int isprime(long n)
{
	int i;

	i = 2;
	while (i < n / 2 + 1)
	{
		if (n % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
