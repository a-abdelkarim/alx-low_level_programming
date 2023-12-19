#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * main - program that copies the content of a file to another file.
 * @argc: num argument
 * @argv: string argument
 * Return: 0 on success, various exit codes on failure
 */

int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t num1, num2;
	char buf[1024];

	if (argc != 3 || (file_from = open(argv[1], O_RDONLY)) == -1 ||
		(file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	while ((num1 = read(file_from, buf, 1024)) > 0)
	{
		if (num1 == -1 || (num2 = write(file_to, buf, num1)) < num1)
		{
			dprintf(STDERR_FILENO, "Error: Can't %s %s\n", num1 == -1 ? "read from file" : "write to", argv[num1 == -1 ? 1 : 2]);
			close(file_from);
			close(file_to);
			exit(num1 == -1 ? 98 : 99);
		}
	}

	if (close(file_from) == -1 || close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", close(file_from) == -1 ? file_from : file_to);
		exit(100);
	}

	return 0;
}

