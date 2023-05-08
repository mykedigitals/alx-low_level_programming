#include "main.h"

/**
 * main - file of one is copied to another
 * @argc: this count the argument
 * @argv: the direction and magnitude of argument
 * Return: if success return 0
 */

int main(int argc, char *argv[])
{
	int outof, intto, reead, reesult, terrror;
	char buff[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	outof = open(argv[1], O_RDONLY);
	if (outof == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	intto = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while ((reead = read(outof, buff, BUFSIZ)) > 0)
		if (intto == -1 || (write(intto, buff, reead) != reead))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	if (reead == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	reesult = close(outof);
	terrror = close(intto);
	if (reesult == -1 || terrror == -1)
	{
		if (reesult == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", outof);
		else if (terrror == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", intto);
		exit(100);
	}
	return (0);
}
