#include "main.h"

/**
 * more_numbers - print 10 lines of numbers 0 to 9
 * Return: void
 */

void more_numbers(void)
{
	int i;

	i = 0;
	do {
		int j;

		j = 0;
		do {
			if (j / 10 != 0)
			{
				_putchar(j / 10 + '0');
			}
			_putchar(j % 10 + '0');
			j++;

		} while (j < 15);

		_putchar('\n');
		i++;

	} while (i < 10);
}
