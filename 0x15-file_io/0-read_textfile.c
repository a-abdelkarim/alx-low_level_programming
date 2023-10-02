#include "stdlib"
#include "main.h"

/**
 * read_textfile - reads the text file and show it
 * 
 * @filename: pointer to the file name
 * @letters: the letters number the function will read and print
 *
 * Return: 0 if there is an issue ot the number of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, bread, bwritten;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	bread = read(fd, buffer, letters);
	bwritten = write(STDOUT_FILENO, buffer, r);

	if (fd == -1 || bread == -1 || bwritten == -1 || bwritten != bread)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(fd);

	return (bwritten);
}
