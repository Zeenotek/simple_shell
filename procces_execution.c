#include "shell.h"



/**
 * execute_child_process - A function that Execute a command in a child process with full path.
 * @command: The command to execute.
 * @args: The arguments for the command.

 */
void execute_child_process(char *command, char *arguments[])
{
    char *path = find_full_path(command);

    if (path != NULL)
    {
        if (execve(path, arguments, NULL) == -1)
        {
            perror("execve");
            _exit(EXIT_FAILURE);
        }
    }
    else if (access(command, X_OK) == 0)
    {
        if (execve(command, arguments, NULL) == -1)
        {
            perror("execve");
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        perror("./hsh");
        _exit(EXIT_FAILURE);
    }
}


/**
 * execute_ - A function that Execute a command with arguments
 * @command_with_args: The command with its arguments.
 * Return: 0 on success, -1 on failure.
 */
int execute_(char *command_with_args)
{
	pid_t child_pid;
	int status;
	int arg_count = 0;
	char *token, *args[MAX_INPUT / 2 + 2];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failedd");
		return (-1);
	}
	if (child_pid == 0)
	{

		token = strtok(command_with_args, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execute_child_process(args[0], args);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
