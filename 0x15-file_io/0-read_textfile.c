#include "main.h"

/**
 * read_textfile - this function reads the text of a file and
 * prints to POSIX stdout
 * @filename: this is the name given to the file that is to be
 * read out
 * @letters: this is the number of letters that is read and printed
 *
 * Return: this returns the correct number of letters that is read and
 * printed, 0 if file cannot be read or opened, 0 if file location is null
 * 0 if the file fails or isn't writing the expected amount of bytes.
 *
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	int refd, tord, towr;

	if (filename == NULL)
		return (0);
	buff = malloc(letters);
	if (buff == NULL)
		return (0);
	refd = open(filename, O_RDONLY);
	if (refd == -1)
	{
		free(buff);
		return (0);
	}
	tord = read(refd, buff, letters);
	if (tord == -1)
	{
		free(buff);
		close(refd);
		return (0);
	}
	towr = write(STDOUT_FILENO, buff, tord);
	if (towr == -1)
	{
		free(buff);
		close(refd);
		return (0);
	}
	close(refd);
	free(buff);
	return (towr);
}
