#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>

void close_file(int file);
int isElf(Elf64_Ehdr *header);
void print_magic(Elf64_Ehdr *header);
void print_class(Elf64_Ehdr *header);
void print_data(Elf64_Ehdr *header);
void print_version(int version);
void print_osabi(Elf64_Ehdr *header);
void print_type(Elf64_Ehdr *header);
void print_entry_point_address(Elf64_Ehdr *header);

/**
 * main - displays the information contained in
 * the ELF header at the start of an ELF file
 * @argc: number of arguments supplied
 * @argv: list of arguments supplied
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int fd, read_bytes;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Failed to open file\n");
		exit(98);
	}
	read_bytes = read(fd, &header, sizeof(Elf64_Ehdr));
	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Failed to read header file\n");
		close_file(fd);
		exit(98);
	}
	if (isElf(&header) == 0)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close_file(fd);
		exit(98);
	}
	print_magic(&header);
	print_class(&header);
	print_data(&header);
	print_version(header.e_ident[EI_VERSION]);
	print_osabi(&header);
	print_type(&header);
	print_entry_point_address(&header);

	close_file(fd);
	return (0);
}

/**
 * print_entry_point_address - prints the entry point address
 * @header: pointer to the ELF header
 */
void print_entry_point_address(Elf64_Ehdr *header)
{
	unsigned long int entry = header->e_entry;

	printf("Entry point address: ");

	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (header->e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)entry);
	}

	else
	{
		printf("%#lx\n", entry);
	}
}

/**
 * print_type - prints the type of an ELF header
 * @header: pointer to the ELF header
 */
void print_type(Elf64_Ehdr *header)
{
	unsigned int type = header->e_type;

	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		type >>= 8;
	}
	printf("Type: ");
	switch (type)
	{
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		default:
			printf("Unknown\n");
	}
}

/**
 * print_osabi - prints the OS/ABI of an ELF header
 * @header: pointer to the ELF header
 */
void print_osabi(Elf64_Ehdr *header)
{
	printf("OS/ABI: ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("Unknown\n");
	}
}

/**
 * print_version - prints the version of ELF header
 * @version: version of the ELF header
 */
void print_version(int version)
{
	printf("Version: %d", version);
	if (version == EV_CURRENT)
	{
		printf(" (current)\n");
	}
	else
	{
		printf("\n");
	}
}

/**
 * print_data - prints data of ELF header
 * @header: pointer to the ELF header
 */
void print_data(Elf64_Ehdr *header)
{
	printf("Data: ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		case ELFDATANONE:
			printf("none\n");
			break;
		default:
			printf("Unknown\n");
	}
}

/**
 * print_class - prints the class of ELF header
 * @header: pointer to the ELF header
 */
void print_class(Elf64_Ehdr *header)
{
	printf("Class: ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		case ELFCLASSNONE:
			printf("none\n");
			break;
		default:
			printf("Unknown\n");
	}
}

/**
 * print_magic - prints magic numbers of an ELF header
 * @header: pointer to the ELF header
 */
void print_magic(Elf64_Ehdr *header)
{
	int i;

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header->e_ident[i]);
		if (i == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

/**
 * close_file - closes an ELF file
 * @file: file descriptor of an ELF file
 */
void close_file(int file)
{
	int result = close(file);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %d\n", file);
		exit(98);
	}
}

/**
 * isElf - checks if a file is an ELF file
 * @header: pointer to the ELF header
 *
 * Return: 1 if the file is an ELF file, otherwise 0
 */
int isElf(Elf64_Ehdr *header)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (header->e_ident[i] != 127 &&
				header->e_ident[i] != 'E' &&
				header->e_ident[i] != 'L' &&
				header->e_ident[i] != 'F')
		{
			return (0);
		}
	}
	return (1);
}
