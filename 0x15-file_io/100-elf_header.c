#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>

// Function prototypes
void closeFile(int file);
int isElfFile(Elf64_Ehdr *header);
void printElfMagic(Elf64_Ehdr *header);
void printElfClass(Elf64_Ehdr *header);
void printElfData(Elf64_Ehdr *header);
void printElfVersion(int version);
void printElfOsAbi(Elf64_Ehdr *header);
void printElfType(Elf64_Ehdr *header);
void printEntryPointAddress(Elf64_Ehdr *header);

int main(int argc, char **argv)
{
    int fileDescriptor, bytesRead;
    Elf64_Ehdr elfHeader;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
        exit(98);
    }

    fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor == -1)
    {
        dprintf(STDERR_FILENO, "Failed to open file\n");
        exit(98);
    }

    bytesRead = read(fileDescriptor, &elfHeader, sizeof(Elf64_Ehdr));
    if (bytesRead == -1)
    {
        dprintf(STDERR_FILENO, "Failed to read header file\n");
        closeFile(fileDescriptor);
        exit(98);
    }

    if (!isElfFile(&elfHeader))
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        closeFile(fileDescriptor);
        exit(98);
    }

    printElfMagic(&elfHeader);
    printElfClass(&elfHeader);
    printElfData(&elfHeader);
    printElfVersion(elfHeader.e_ident[EI_VERSION]);
    printElfOsAbi(&elfHeader);
    printElfType(&elfHeader);
    printEntryPointAddress(&elfHeader);

    closeFile(fileDescriptor);
    return 0;
}

void printEntryPointAddress(Elf64_Ehdr *header)
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

void printElfType(Elf64_Ehdr *header)
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

void printElfOsAbi(Elf64_Ehdr *header)
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

void printElfVersion(int version)
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

void printElfData(Elf64_Ehdr *header)
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

void printElfClass(Elf64_Ehdr *header)
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

void printElfMagic(Elf64_Ehdr *header)
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

void closeFile(int file)
{
    int result = close(file);

    if (result == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close file %d\n", file);
        exit(98);
    }
}

int isElfFile(Elf64_Ehdr *header)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (header->e_ident[i] != 127 &&
            header->e_ident[i] != 'E' &&
            header->e_ident[i] != 'L' &&
            header->e_ident[i] != 'F')
        {
            return 0;
        }
    }
    return 1;
}

