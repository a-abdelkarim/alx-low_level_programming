#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

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
	int fd_from, fd_to, num_bytes, times = 1, buffer_size = 1024;
	char buffer[1024];
	ssize_t read_bytes = 0, write_bytes = 0;
	mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

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

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, permissions);
	if (fd_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}

	while (1)
	{
		read_bytes = read(fd_from, buffer, buffer_size);
		if (read_bytes < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close_file(fd_from);
			exit(98);
		}
		write_bytes = write(fd_to, buffer, buffer_size);
		if (write_bytes < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_to);
			exit(98);
		}
		if (read_bytes < buffer_size)
			break;
		lseek(fd_to, 0, SEEK_END);
		lseek(fd_from, buffer_size * times, SEEK_SET);
		times++;
	}
	close_file(fd_from);
	close_file(fd_to);
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
