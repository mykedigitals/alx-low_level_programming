#include "main.h"

/**
 * append_text_to_file - to append text in the ending of
 * a certain file
 *
 * @filename: the file name to append text into the end
 * @text_content: this is the content the @filename contains
 * which has NULL termination
 *
 * Return: on Success, it returns 1, while -1 if @filename is NULL
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int filed, wrrite, lent;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		return (1);
	}

	filed = open(filename, O_WRONLY | O_APPEND);

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
	return (1);
}
