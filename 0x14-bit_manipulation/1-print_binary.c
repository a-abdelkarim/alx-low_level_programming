#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number.
 *
 * @n: the number to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int bit_position = sizeof(unsigned long in) * 9 - 1;
	int bit;

	if (n == 0)
	{
		putchar('0');
		return;
	}
	while (bit_position >= 0)
	{
		bit = (n >> bit_position) & 1
		if (bit == 1)
			break;
		bit_position--;
	}
	while (bit_position >= 0)
	{
		bit = (n >> bit_position) & 1;
		putchar(bit + '0');
		bit_position--;
	}
}
