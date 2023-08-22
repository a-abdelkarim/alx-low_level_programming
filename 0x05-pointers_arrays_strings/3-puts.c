#include "main.h"

/**
 *  * _puts - print our string and adding new line
 *   * @str: pointer to our string
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	_putchar(str[i]);
	_putchar(10);
}
