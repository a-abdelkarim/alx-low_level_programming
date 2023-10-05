#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 1024

/**
 * main - copies the content of one file to another file
 * @argc: the number of cmd arguments
 * @argv: list of cmd arguments
 *
 * Return: 0 on success, or the  corresponding exit code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, num_bytes;
	char buffer[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
		return (98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot write to file %s\n", argv[2]);
		close(fd_from);
		return (99);
	}

	while ((num_bytes = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		if (write(fd_to, buffer, num_bytes) != num_bytes)
		{
			dprintf(STDERR_FILENO, "ERROR: Cannot write to file %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			return (98);
		}

		if (num_bytes == -1)
		{
			dprintf(STDERR_FILENO, "ERROR: Cannot read from file %s\n", argv[1]);
			close(fd_from);
			close(fd_to);
			return (98);
		}

		if (close(fd_from) == -1 || close(fd_to) == -1)
		{
			dprintf(STDERR_FILENO, "ERROR: Cannont close fd %d\n", (close(fd_from) == -1) ? fd_from : fd_to);
			return (100);
		}
	}

	return (0);
}
