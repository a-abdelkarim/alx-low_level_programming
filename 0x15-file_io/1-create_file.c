#include "main.h"

/**
 * create_file - creates a file and write text content to it.
 * @filename: name of the file.
 * @text_content: text content to write it to the file
 *
 * Return: 1 if success, or -1 if there is an issue.
 */
int create_file(const char *filename, char *text_content)
{
	int o, write_result, length = 0;

	if (filename == NULL)
		return (-1);

	o = open(filename, O_WRONLY | O_CREATE | O_TRUNC, 0600);
	if (o == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;

		write_result = write(o, text_content, length);
		if (write_result == -1)
		{
			close(o);
			return (-1);
		}
	}

	close(o);
	return (1);
}
