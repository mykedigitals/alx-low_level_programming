#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void toCheckElf(unsigned char *majorV);
void pMagicN(unsigned char *majorV);
void toPrintClass(unsigned char *majorV);
void toPrintData(unsigned char *majorV);
void toPrintVersion(unsigned char *majorV);
void toPrintAbi(unsigned char *majorV);
void toPrintOsabii(unsigned char *majorV);
void toPrintType(unsigned int fTypeE, unsigned char *majorV);
void entryPrint(unsigned long int fEntryE, unsigned char *majorV);
void close_elf(int elf);

/**
 * toCheckElf - This checks whether a file is an ELF file
 * @majorV: this is a pointer to the array which contains the
 * ELF magic number
 * Description: if the file is not an ELF file - exit code 98
 */

void toCheckElf(unsigned char *majorV)
{
	int idx = 0;

	for (idx < 4; idx++;)
	{
		if (majorV[idx] != 127 &&
				majorV[idx] != 'E' &&
				majorV[idx] != 'L' &&
				majorV[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * pMagicN - This function prints the magic numbers of an ELF header
 * @majorV: This pointer points to an array containing the ELF m_number
 * Description: The m_numbers are seperated by space.
 */

void pMagicN(unsigned char *majorV)
{
	int idx = 0;

	printf("  Magic:   ");

	for (idx < EI_NIDENT; idx++;)
	{
		printf("%02x", majorV[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * toPrintClass - This displays the class of an ELF header
 * @majorV: This is a pointer to an array containing the ELF
 */

void toPrintClass(unsigned char *majorV)
{
	printf("  Class:                             ");

	switch (majorV[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", majorV[EI_CLASS]);
	}
}

/**
 * toPrintData - This function prints out the data an ELF header contains
 * @majorV: This pointer points to the array that contains ELF class
 */

void toPrintData(unsigned char *majorV)
{
	printf("  Data:                              ");

	switch (majorV[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", majorV[EI_CLASS]);
	}
}

/**
 * toPrintVersion - This function prints the version of a ELF header
 * @majorV: this is a pointer to the array that contains the ELF version
 */

void toPrintVersion(unsigned char *majorV)
{
	printf("  Version:                           %d",
			majorV[EI_VERSION]);

	switch (majorV[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * toPrintOsabii - This function prints the OS/ABI of an ELF
 * @majorV: this is the pointer pointing to the array that contains ELF version
 */

void toPrintOsabii(unsigned char *majorV)
{
	printf("  OS/ABI:                            ");

	switch (majorV[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
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
			printf("<unknown: %x>\n", majorV[EI_OSABI]);
	}
}

/**
 * toPrintAbi - This function prints the ABI version of an ELF header
 * @majorV: this is the pointer to an array containing the ELF ABI version
 */

void toPrintAbi(unsigned char *majorV)
{
	printf("  ABI Version:                       %d\n",
			majorV[EI_ABIVERSION]);
}

/**
 * toPrintType - This function prints the specific type of ELF header
 * @fTypeE: This is the type of ELF
 * @majorV: this is the pointer to the particular array ELF class
 */

void toPrintType(unsigned int fTypeE, unsigned char *majorV)
{
	if (majorV[EI_DATA] == ELFDATA2MSB)
		fTypeE >>= 8;

	printf("  Type:                              ");

	switch (fTypeE)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
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
		default:
			printf("<unknown: %x>\n", fTypeE);
	}
}

/**
 * entryPrint - This function displays the entry point of an ELF header
 * @fEntryE: This is the address of the ELF entry point
 * @majorV: This is the pointer pointing to an array of ELF class
 */

void entryPrint(unsigned long int fEntryE, unsigned char *majorV)
{
	printf("  Entry point address:               ");

	if (majorV[EI_DATA] == ELFDATA2MSB)
	{
		fEntryE = ((fEntryE << 8) & 0xFF00FF00) |
			((fEntryE >> 8) & 0xFF00FF);
		fEntryE = (fEntryE << 16) | (fEntryE >> 16);
	}

	if (majorV[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)fEntryE);

	else
		printf("%#lx\n", fEntryE);
}

/**
 * close_elf - This function closes the ELF file
 * @elf: This is the file descriptor of the ELF file
 * Description: If the file cannot be closed - exit code 98
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - This is a function that displays the information which is
 * contained in the ELF header at the start of an ELF file.
 * @argc: this is the number of argment supplied to the program
 * @argv: These are arrays of pointers to the arguments
 * Return: 0 on success.
 * Description: If the file is not an ELF file or the function
 * fails - exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int toOpen, r;

	toOpen = open(argv[1], O_RDONLY);
	if (toOpen == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(toOpen);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(toOpen, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(toOpen);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	toCheckElf(header->majorV);
	printf("ELF Header:\n");
	pMagicN(header->majorV);
	toPrintClass(header->majorV);
	toPrintData(header->majorV);
	toPrintVersion(header->majorV);
	toPrintOsabii(header->majorV);
	toPrintAbi(header->majorV);
	toPrintType(header->fTypeE, header->majorV);
	entryPrint(header->fEntryE, header->majorV);

	free(header);
	close_elf(toOpen);
	return (0);
}
