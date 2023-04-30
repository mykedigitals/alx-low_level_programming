#include <unistd.h>
#include "main.h"
#include <fcntl.h>

/**
 * create_file - This function creates a file with read/write permissions
 * @filename: this is the name of the file in question
 * @text_content: this is the text that is to be written into the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int txtlen;
	int tofd, towr;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		tofd = open(filename, O_WRONLY | O_CREAT, 0600);
		if (tofd == -1)
			return (-1);
		return (1);
	}

	tofd = open(filename, O_WRONLY | O_TRUNC, 0600);

	if (tofd == -1)
		return (-1);

	for (txtlen = 0; text_content[txtlen]; txtlen++)
	{}

	towr = write(tofd, text_content, txtlen);

	if (towr == -1)
	{
		close(tofd);
		return (-1);
	}

	close(tofd);
	return (1);
}
