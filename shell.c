#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always returns 0.
 */
int main(void)
{

	size_t input_size = 0;
	ssize_t read_size;
	int result;
	char *user_path, *user_input = NULL;
	bool check = true;

	while (check)
	{
	display_prompt();
	read_size = my_getline(&user_input, &input_size, stdin);
	if (read_size == -1)
	{
	free(user_input);
	return 0;
	}
	if (user_input[read_size - 1] == '\n')
	user_input[read_size - 1] = '\0';

	if (_strncmp(user_input, "exit", 4) == 0)
	{
	free(user_input);
	user_input = NULL;
	input_size = 0;
	exit(EXIT_SUCCESS);
	}

	if (_strcmp(_strtrim(user_input), "env") == 0)
	{
	_environment();
	continue;
	}
	if (_strncmp(user_input, "cd", 2) == 0)
	{
	user_path = _strtrim(user_input + 2);
	_directory(user_path);
	free(user_input);
	user_input = NULL;
	input_size = 0;
	continue;
	}
	if (read_size > 1)
	{
		result = execute_(user_input);
	if (result == -1)
	break;
	}
	}
	free(user_input);
	return 0;
}
