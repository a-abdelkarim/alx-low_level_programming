#include "main.h"

/**
 * print_alphabet_x10 - a function that prints the alphabet
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	int a = 0;

	while (a < 10)
	{
		int alp = 'a';

		while (alp <= 'z')
		{
			_putchar(alp);
			alp++;
		}
		_putchar('\n');
		a++;
	}
}
