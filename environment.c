#include "shell.h"


/**
 * change_directory -A function that Change the current working directory.
 * @path: The path to the directory to change to.
 * If the path is "-", the previous working directory is used.
 */

void _directory(char *path)
{
	char *old_directory = getenv("PWD");
	char *new_directory;

	if (path == NULL || strlen(path) == 0)
	{
	path = getenv("HOME");
	}
	else if (strcmp(path, "-") == 0)
	{
	path = getenv("OLDPWD");
	}

	if (chdir(path) != 0)
	{
	perror("chdir");
	return;
	}

	new_directory = getcwd(NULL, 0);

	if (new_directory != NULL)
	{
	setenv("OLDPWD", old_directory, 1);
	setenv("PWD", new_directory, 1);
	free(new_directory);
	}
	else
	{
	perror("getcwd");
	}
}


/**
 * print_environment - A function Print the environment variables.
 * Return:void
 */
void _environment(void)
{
	int i;
	char **env = environ;

	for (i = 0; env[i]; i++)
	{

		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
