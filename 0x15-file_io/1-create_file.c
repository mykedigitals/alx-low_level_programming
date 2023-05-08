#include "main.h"

/**
 * create_file - it creates a readable and writeable file
 * @filename: the name of file that is created
 * @text_content: the text that we want to write inside
 * @file
 *
 * Return: if success it returns 1, -1 when it fails
 */


int create_file(const char *filename, char *text_content)
{
	int lent, filed, wrrite;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		filed = open(filename, O_WRONLY | O_CREAT, 0600);
		if (filed == -1)
			return (-1);
		return (1);
	}
	filed = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (filed == -1)
		return (-1);

	for (lent = 0; text_content[lent]; lent++)
	{}
	wrrite = write(filed, text_content, lent);

	if (wrrite == -1)
	{
		close(filed);
		return (-1);
	}
	close(filed);
}
