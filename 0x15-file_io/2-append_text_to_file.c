#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: variable pointer
 * @text_content: content file
 * Description: Create a function that appends text at the end of a file.
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int i = 0, file, write_result;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	while (text_content[i] != '\0')
	{
		i++;
	}

	file = open(filename, O_WRONLY | O_APPEND);

	if (file == -1)
		return (-1);

	write_result = write(file, text_content, i);

	if (write_result == -1)
	{
		close(file);
		return (-1);
	}

	close(file);

	return (1);
}

