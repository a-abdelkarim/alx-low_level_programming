#include "main.h"

/**
 *  _strlen - function to know what is the string size
 *  @s: pointer to our string
 * Return: size of string or array of char
 */
int _strlen(char *s)
{
	int i, string_size = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		string_size++;
	}
	return (string_size);
}
