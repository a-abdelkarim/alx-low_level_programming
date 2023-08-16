#include <string.h>
#include "main.h"

/**
 * main - A program that prints "_putchar"
 *
 * Return: 0
 */

int main(void)
{
	const char *str = "_putchar";
	int length = strlen(str);
	int i;

	for (i = 0; i < length; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
	return (0);
}
