#include <stdio.h>

/**
 * main - A program that prints alphabet letters
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *str;
	int i;

	str = "abcdefghijklmnopqrstuvwxyz\n";
	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
	}
	return (0);
}
