#include "shell.h"


/**
 * get_env - A function that Get environment variable.
 * @var_name: The name of the environment variable.
 
 * Return: A pointer to the value of the environment variable if found,
 * otherwise NULL.
 */

char *get_env(const char *var_name)
{
	int i, name_len;
	char **env;
	char *value;
	
	if (!var_name)
	return (NULL);
	
	env = environ
	
	for (i = 0; env[i]; i++)
	{
	for (name_len = 0; env[i][name_len] != '='; name_len++)
	;
	
	if (_strncmp(var_name, env[i], name_len) == 0)
	{
		value = &env[i][name_len + 1];
	return (value);
	}
	}

	return (NULL);
}


/**
 * find_full_path - A function that Find the full path of a command.
 * @cmd: The command for which to determine the full path.
 * Return: A dynamically allocated string containing the full path of the
 */
char *find_full_path(char *cmd)
{
	char *path, *full_path, *path_env = get_env("PATH");
	size_t path_len, full_path_len, cmd_len;

	if (path_env == NULL)
	{
	return (NULL);
	}

	path = strtok(path_env, ":");
	while (path != NULL)
	{
	path_len = _strlen(path);
	cmd_len = _strlen(cmd);
	full_path_len = path_len + cmd_len + 2;

	full_path = malloc(full_path_len);
	if (full_path == NULL)
	{
	perror("malloc");
	return (NULL);
	}

	_strcpy(full_path, path);
	full_path[path_len] = '/';
	_strcpy(full_path + path_len + 1, cmd);

	if (access(full_path, X_OK) == 0)
	{
	return (full_path);
	}

	free(full_path);
	path = strtok(NULL, ":");
	}
	return (NULL);
}
