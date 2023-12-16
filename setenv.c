#include "shell.h"

/**
 * handle_Setenv - Handle the setenv built-in command
 * Return: 1 if there's an error in the setenv input, 0 otherwise
 * @CMD: Array containing the user's input command
 * @stat: Pointer to the execution status
 */
int handle_Setenv(char **CMD, int *stat)
{
	if (VSA(CMD, stat) == 1)
	{
		return (1);
	}
	if (SEV(CMD[1], CMD[2]) == -1)
	{
		*stat = 2;
		return (1);
	}
	free2DArray(CMD);
	return (0);
}

/**
 * VSA - Validate the setenv arguments
 * Return: 1 if there's an error in the setenv input, 0 otherwise
 * @CMD: Array containing the user's input command
 * @stat: Pointer to the execution status
 */
int VSA(char **CMD, int *stat)
{
	if ((CMD[1] == NULL) || (CMD[2] == NULL) || (CMD[3] != NULL))
	{

		free2DArray(CMD);
		*stat = 2;
		return (1);
	}
	return (0);
}

/**
 * SEV - Set an environment variable
 * Return: 0 on success, -1 on failure
 * @var: The environment variable to set
 * @val: The value to set for the environment variable
 */
int SEV(char *var, char *val)
{
	if (setenv(var, val, 1) == -1)
	{
		return (-1);
	}
	return (0);
}
