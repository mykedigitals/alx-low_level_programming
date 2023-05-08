#include "main.h"

/**
 * read_textfile - reading a text file and print it as stdout FXNM
 * @filename: this holds the name of the file to be read
 * @letters: total no of letters read and printed
 *
 * Return: display letters,0 if letters cannot open,
 * 0 if @filename is NULL,
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int filed, reead;
	int wrrite;
	char *leet;

	if (filename == NULL)
		return (0);
	leet = malloc(letters);
	if (leet == NULL)
		return (0);

	filed = open(filename, O_RDONLY);
	if (filed == -1)
	{
		free(leet);
		return (0);
	}
	reead = read(filed, leet, letters);
	if (reead == -1)
	{
		free(leet);
		close(filed);
		return (0);
	}
	wrrite = write(STDOUT_FILENO, leet, reead);

	if (wrrite == -1)
	{
		free(leet);
		close(filed);
		return (0);
	}
	close(filed);
	free(leet);
	return (wrrite);
}
