#include "main.h"

/**
 * append_text_to_file - this function appends text to the end of a file
 * @filename: the variable name is name of the file to append the text to
 * @text_content: this is the text we are appending to include
 * NULL termination
 *
 * Return: 1 on success, -1 on failure, -1 if @filename is NULL
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int tofd, towr;
	int txtlen;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		return (1);
	}

	tofd = open(filename, O_WRONLY | O_APPEND);
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
