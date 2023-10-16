#include "shell.h"

/**
 * prompt - A function that Display the shell prompt.
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
}
