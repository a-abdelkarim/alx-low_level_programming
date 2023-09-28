#include "main.h"

/**
 * binary_to_unit - converts a binary number to an unsigned integer.
 *
 * @b: pointer to a string containing the binary number
 *
 * Return: the converted number, or 0 if there is an error
 */

unsigned int binary_to_unit(const char *b)
{
	int i = 0;
	unsgned int result = 0;

	if (b == NULL)
		return (0);
	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		result = (result * 2) + (*b - '0');
		b++
	}
	return (result);
}
