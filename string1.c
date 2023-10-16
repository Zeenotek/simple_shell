#include "shell.h"

/**
 * _strtrim - A function that Trim leading and trailing whitespace
 * @str: The string to trim.
 * Return: A pointer to the trimmed string.
 */
char *_strtrim(char *str)
{
	char *end;

	
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
	{
		str++;
	}

	if (*str == '\0')
	{
		return (str);
	}

	end = str + _strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
	{
		end--;
	}
	*(end + 1) = '\0';

	return (str);
}
