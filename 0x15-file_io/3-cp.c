#include "main.h"

/**
 * main - this function copies the element of a file to another
 * @argc: this is for counting the argument
 * @argv: this is for the vector of the argument
 *
 * Return: 0 to return success
 */

int main(int argc, char *argv[])
{
	int getFrom, getTo, tord, toclf, toclt;
	char buff[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	getFrom = open(argv[1], O_RDONLY);
	if (getFrom == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	getTo = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while ((tord = read(getFrom, buff, BUFSIZ)) > 0)
		if (getTo == -1 || (write(getTo, buff, tord) != tord))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	if (tord == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	toclf = close(getFrom);
	toclt = close(getTo);
	if (toclf == -1 || toclt == -1)
	{
		if (toclf == -1)
			dprintf(STDERR_FILENO, "Error: Can't close tofd %d\n", getFrom);
		else if (toclt == -1)
			dprintf(STDERR_FILENO, "Error: Can't close tofd %d\n", getTo);
		exit(100);
	}
	return (0);
}
