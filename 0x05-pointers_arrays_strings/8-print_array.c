#include "main.h"
/**
 *  * print_array - print our array element separated by commas
 *   *
 *    * @a: pointer to our string
 *     *
 *      * @n: array size
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%i", a[i]);
		if (i < (n - 1))
		{
			printf(", ");
		}
	}
	printf("\n");
}
