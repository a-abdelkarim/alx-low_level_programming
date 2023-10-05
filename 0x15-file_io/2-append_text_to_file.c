#include "main.h"

/**
 * _strlen - finds the length of a string
 * @str: a pointer to the string
 *
 * Return: the length of the string
 */
size_t _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}

/**
 * append_text_to_file - appends text to the end of a file.
 * @filename: the name of the file.
 * @text_content: the text that will be appended to the file.
 *
 * Return: 1 if exery thing is okay, or -1 if there are any issues.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t length;

	if (filename == NULL)
		return (-1);
	
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		length = write(fd, text_content, _strlen(text_content));
	}
	close(fd);

	if (length == -1)
		return (-1);
	return (1);
}
