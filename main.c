#include "shell.h"
/**
 * main - The main function for the shell.
 * Return: 0 if the shell exits successfully, -1 otherwise.
 * @argc: The number of arguments passed to the shell.
 * @argv: The arguments passed to the shell.
*/
int main(int argc, char **argv)
{
	/* To store the user input. */
	char *userInput = NULL;
	/* To store the parsed command. */
	char **parsedCommand = NULL;
	/* To store the execution status and command count. */
	int executionStatus = 0, i = 0;
	(void)argc; /* Unused variable, common in C for command line arguments. */
	/* Infinite loop to keep the shell running. */
	while (1)
	{	/* Read user input. */
		userInput = read_user_input();
		/* Check if the input is NULL (EOF or error). */
		if (userInput == NULL)
		{	/* If standard input is a terminal, print a new line. */
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			/* Exit the shell with the current execution status. */
			return (executionStatus);
		}
		/* Increment the command count. */
		i++;
		userInput = filterOutComments(userInput);
		/* Split the input into tokens (parsed command). */
		parsedCommand = splitStringIntoTokens(userInput);
		/* Continue to the next iteration if parsing failed. */
		if (!parsedCommand)
		{
			continue;
		}
		/* Check if the command is a built-in command. */
		if (CheckTheGivenCommandIsBuiltIn(parsedCommand[0]))
		{	/* Execute the built-in command. */
			executeBuiltinCommand(parsedCommand, argv, &executionStatus, i);
		}
		else
		{	/* Execute a non-built-in command. */
			executionStatus = runCommand(parsedCommand, argv, i);
		}
	}
}
