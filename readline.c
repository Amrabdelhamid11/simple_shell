#include "shell.h"
/**
 * read_user_input - Reads a line of input from the user.
 * Return: The line read from the user, or NULL
 * if an error occurs or EOF is reached.
*/
char *read_user_input(void)
{
	char *line = NULL; /* Pointer to the line to be read. */
	size_t len = 0;	   /* Length of the buffer. */
	ssize_t n;		   /* Number of characters read. */

	/* Check if the standard input is a terminal (as opposed to a file or pipe) */
	if (isatty(STDIN_FILENO))
	{
		/* If it is a terminal, display a prompt. */
		write(STDOUT_FILENO, "$ ", 2);
	}

	/* Read a line from the standard input. */
	n = getline(&line, &len, stdin);

	/* Check if getline failed (e.g., due to an EOF or an error). */
	if (n == -1)
	{
		free(line);	   /*  Free the allocated buffer. */
		return (NULL); /*  Return NULL to indicate failure or EOF. */
	}
	return (line); /* Return the line read from the user. */
}
