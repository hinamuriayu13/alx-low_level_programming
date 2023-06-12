#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type);
void print_entry(unsigned long int e_entry);

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void print_magic(unsigned char *e_ident)
{
    printf(" Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
    printf(" Class:                             ");
    switch (e_ident[EI_CLASS])
    {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_CLASS]); break;
    }
}

/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
    printf(" Data:                              ");
    switch (e_ident[EI_DATA])
    {
        case ELFDATANONE: printf("none\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_DATA]); break;
    }
}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
    printf(" Version:                           %d", e_ident[EI_VERSION]);
    switch (e_ident[EI_VERSION])
    {
        case EV_CURRENT: printf(" (current)\n"); break;
        default: printf("\n"); break;
    }
}

/**
 * print_abi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_abi(unsigned char *e_ident)
{
    printf(" OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
        default: printf("<unknown: %x>\n", e_ident[EI_OSABI]); break;
    }
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 */
void print_type(unsigned int e_type)
{
    printf(" Type:                              ");
    switch (e_type)
    {
        case ET_NONE: printf("NONE (No file type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %x>\n", e_type); break;
    }
}

/**
 * print_entry - Prints the entry point address of an ELF header.
 * @e_entry: The entry point address.
 */
void print_entry(unsigned long int e_entry)
{
    printf(" Entry point address:               0x%lx\n", e_entry);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <ELF-file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    Elf32_Ehdr ehdr;

    ssize_t n = read(fd, &ehdr, sizeof(ehdr));
    if (n != sizeof(ehdr))
    {
        perror("read");
        close(fd);
        return 1;
    }

    close(fd);

    printf("ELF Header:\n");

    print_magic(ehdr.e_ident);
    print_class(ehdr.e_ident);
    print_data(ehdr.e_ident);
    print_version(ehdr.e_ident);
    print_abi(ehdr.e_ident);
    print_type(ehdr.e_type);
    print_entry(ehdr.e_entry);

    return 0;
}
