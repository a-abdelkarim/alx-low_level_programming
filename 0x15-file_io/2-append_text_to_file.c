#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file.
 * @filename: the name of the file.
 * @text_content: the text that will be appended to the file.
 *
 * Return: 1 if exery thing is okay, or -1 if there are any issues.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, write_result, length = 0;

	if (filename == NULL)
		return (-1);
	
	o = open(filename, O_WRONLY | O_APPEND);
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
	return(1);
}
