#include "shell.h"
/**
 * CheckTheGivenCommandIsBuiltIn - Checks if the given command is a built-in
 * @command: The command to be checked.
 * Return: 1 if the command is a built-in command, 0 otherwise.
*/
int CheckTheGivenCommandIsBuiltIn(char *command)
{
	/* List of built-in commands supported by the shell. */
	char *builtinCommands[] = {"exit", "matchedEnv", "setenv", "cd", NULL};
	int i;

	/* Loop through the list of built-in commands. */
	for (i = 0; builtinCommands[i]; i++)
	{

		/* Compare the given command with each built-in command. */
		if (compareStrings(command, builtinCommands[i]) == 0)
		{
			return (1); /* Return 1 if the command is a built-in command. */
		}
	}

	return (0); /* Return 0 if the command is not a built-in command. */
}

/* Function to execute a built-in command. */
void executeBuiltinCommand(char **command, char **argv,
int *processStatus, int idx)
{
	/* Check if the command is 'exit' and execute it. */
	if (compareStrings(command[0], "exit") == 0)
	{
		terminateShell(command, argv, processStatus, idx);
	}
	/* Check if the command is 'matchedEnv' and execute it. */
	else if (compareStrings(command[0], "env") == 0)
	{
		displayEnvironmentVariables(command, processStatus);
	}
	else if (compareStrings(command[0], "setenv") == 0)
	{
		process_EnvSetting(command, processStatus);
	}
}

/**
 * terminateShell - Terminates the shell.
 * @command: The command to be executed.
 * @argv: The arguments passed to the command.
 * @processStatus: The process status.
 * @idx: The index of the command in the array of commands.
*/
void terminateShell(char **command, char **argv, int *processStatus, int idx)
{
	int exitStatus = (*processStatus);

	char errorMessage[] = ": exit: Illegal number: ";
	char *index;

	/* Check if an argument is provided with the exit command. */
	if (command[1])
	{
		/* If the argument is a numeric string, convert it to an integer. */
		if (is_numeric_string(command[1]))
		{
			exitStatus = st_to_int(command[1]);
		}
		else
		{
			/* If the argument is not numeric, print an error message. */
			index = integer_to_string(idx);

			write(STDERR_FILENO, argv[0], stringLength(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, stringLength(index));
			write(STDERR_FILENO, errorMessage, stringLength(errorMessage));
			write(STDERR_FILENO, command[1], stringLength(command[1]));
			write(STDERR_FILENO, "\n", 1);

			free(index);

			free2DArray(command);

			(*processStatus) = 2;
			return;
		}
	}

	/* Free the command array and exit the shell with the specified status. */
	free2DArray(command);
	exit(exitStatus);
}

/**
 * displayEnvironmentVariables - Displays the environment variables.
 * @command: The command to be executed.
 * @processStatus: The process status.
*/
void displayEnvironmentVariables(char **command, int *processStatus)
{
	int i;
	/* Loop through and print all environment variables. */
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], stringLength(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	/* Free the command array and set the process status to 0. */
	free2DArray(command);
	(*processStatus) = 0;
}
