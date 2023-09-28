#include "main.h"

/**
 * get_bit - get the value of a bit at a given index.
 *
 * @n: the number to extract the bit from.
 * @index: the index of the bit to get, starting from 0.
 *
 * Return: the value of the bit at index or -1 if there is an issu.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizerof(unsigned long int) * 8))
		return (-1);
	return ((n >> index) & 1);
}
