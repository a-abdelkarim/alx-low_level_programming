#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned integer.
 *
 * @b: pointer to a string containing the binary number
 *
 * Return: the converted number, or 0 if there is an error
 */
unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int result = 0;

	if (b == NULL)
	{
		return (0);
	}
	while (b[i] != '\0')
	{
		char c = b[i];

		if (c == '0' || c == '1')
		{
			result = result * 2 + (c - '0');
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (result);
}
