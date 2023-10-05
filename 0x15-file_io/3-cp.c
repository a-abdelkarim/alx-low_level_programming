#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 1024

void close_file(int file);

/**
 * main - copies the content of one file to another file
 * @argc: the number of cmd arguments
 * @argv: list of cmd arguments
 *
 * Return: 0 on success, or the  corresponding exit code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, num_bytes, times = 1;
	size_t read_bytes = 0, write_bytes = 0;
	char buffer[BUFSIZE];
	mode_t permissions = S_IRUSR | S_IWUSR | I_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}

	while ((num_bytes = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		if (write(fd_to, buffer, num_bytes) != num_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(98);
		}

		if (num_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close(fd_from);
			close(fd_to);
			exit(98);
		}

		if (close(fd_from) == -1 || close(fd_to) == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (close(fd_from) == -1) ? fd_from : fd_to);
			exit(100);
		}
	}

	return (0);
}

/**
 * close_file - closes a file
 * @file: pointer to the file
 */
void close_file(int file)
{
	int result = close(file);

	if (result < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file);
		exit(100);
	}
}
