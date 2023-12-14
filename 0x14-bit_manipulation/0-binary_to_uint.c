#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned number
 * @b: pointer to a string
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int index = 0;
	unsigned int total = 0;

	if (b == NULL)
	{
		return (0);
	}
	while (b[index] != '\0')
	{
		char c = b[index];

		if (c == '1' || c == '0')
		{
			total = total * 2 + (c - '0');
		}
		else
		{
			return (0);
		}
		index++;
	}
	return (total);
}
