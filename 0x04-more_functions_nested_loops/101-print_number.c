#include "main.h"

/**
 * print_number - prints a number
 * @n: number to print
 * Return: void
 */

void print_number(int n)
{
	unsigned int temp;

	if (n < 0)
	{
		temp = -n;
		_putchar('-');
	}
	else
	{
		temp = n;
	}

	if (temp / 10)
	{
		print_number(temp / 10);
	}
	_putchar(temp % 10 + '0');
}
