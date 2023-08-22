#include "main.h"

/**
 *  * print_rev - print our string in reverse
 *   * @s: pointer to our string
 */
void print_rev(char *s)
{
	int i, size;

	size = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		size++	
	}
	size--;
	for (i = size; i >= 0; i--)
		_putchar(s[i]);
	_putchar(10);
}
