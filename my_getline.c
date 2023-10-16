#include "shell.h"

/**
 * my_getline - A custome custom getline function
 * @line: line buffer
 * @len: length of buffer
 * @stream: stream to read from
 * Return: number of characters read or -1 if fail
 */
ssize_t my_getline(char **line, size_t *len, FILE *stream)
{
	char *getline;
	ssize_t read;

	if (*line == NULL || *len == 0)
	{
		*len = 1024;
		*line = malloc(*len);
		if (*line == NULL)
		{
			return (-1);
		}
	}

	getline = fgets(*line, *len, stream);
	if (getline != NULL)
	{
		read = _strlen(*line);

		if (read > 0 && (*line)[read - 1] == '\n')
		{
			(*line)[read - 1] = '\0';
			read--;
		}
		return (read);
	}
	else
	{
		return (-1);
	}
}
