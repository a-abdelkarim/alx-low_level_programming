#include "main.h"
/**
 *  * _strcpy - copy all from src to dest
 *   *
 *    * @dest: what we will copy to
 *     *
 *      * @src: what we will copy from
 *       *
 *        * Return: dest the copied array from src
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
