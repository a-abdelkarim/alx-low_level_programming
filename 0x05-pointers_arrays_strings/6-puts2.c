#include "main.h"
/**
 *  * puts2 - print our even char in our string
 *   * @str: pointer to our string
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i % 2 == 0)
			_putchar(str[i]);
	}
	_putchar(10);
}
