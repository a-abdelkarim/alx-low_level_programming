#include "main.h"

/**
 * print_line - draws a straight line
 * @n: number of _
 * Return: void
 */

void print_line(int n)
{
	int i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			_putchar('_');
			i++;
		}
	}
	_putchar('\n');
}
