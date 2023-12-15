#include "shell.h"
/**
 * runCommand - Reads a line of input from the user.
 * Return: The line read from the user, or NULL
 * if an error occurs or EOF is reached.
 * @command: The command to be executed.
 * @argv: The arguments passed to the command.
 * @idx: The index of the command in the array of commands.
 */
int runCommand(char **command, char **argv, int idx)
{
	char *completeCommandPath;
	pid_t processID;
	int processStatus;
	/* Retrieve the full path of the command. */
	completeCommandPath = path(command[0]);
	/* If the command path is not found, display an error and return. */
	if (!completeCommandPath)
	{
		displayError(argv[0], command[0], idx);
		/* Free the memory allocated for the command array. */
		free2DArray(command);
		return (127); /* Returning 127 indicates a command not found error. */
	}
	/* Creating a new process. */
	processID = fork();
	/* The child process block. */
	if (processID == 0)
	{
		/* Execute the command. If execve fails, free the allocated memory. */
		if (execve(completeCommandPath, command, environ) == -1)
		{
			/* Free memory and handle any errors. */
			free(completeCommandPath), completeCommandPath = NULL;
			free2DArray(command);
		}
	}
	/* The parent process block. */
	else
	{
		/* Wait for the child process to complete. */
		waitpid(processID, &processStatus, 0);
		/* Free the memory allocated for the command and its complete path. */
		free2DArray(command);
		free(completeCommandPath), completeCommandPath = NULL;
	}
	/* Return the exit status of the child process. */
	return (WEXITSTATUS(processStatus));
}
