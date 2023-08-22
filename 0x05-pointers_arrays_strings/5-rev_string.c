/**
 *  * rev_string - print our string in reverse
 *   * @s: pointer to our string
 */
void rev_string(char *s)
{	
	int i, size, j;
	char temp;

	size = 0;

	for (i = 0; s[i] != '\0'; i++)
		size++;

	for (j = 0; j < size; j++)		
	{		
		temp = s[j];
		s[j] = s[size - 1];
		s[size - 1] = temp;
		size--;
	}
}
