#include "shell.h"

/**
 * process_EnvSetting - Process the 'setenv' built-in command
 * Return: 1 if there's an error in the setenv input, 0 otherwise
 * @InputCmd: Array containing the user's input command
 * @execStatus: Pointer to the execution status
 */
int process_EnvSetting(char **InputCmd, int *execStatus)
{
	if (validate_SetEnvArgs(InputCmd, execStatus) == 1)
	{
		return (1);
	}
	if (apply_EnvChange(InputCmd[1], InputCmd[2]) == -1)
	{
		*execStatus = 2;
		return (1);
	}
	free2DArray(InputCmd);
	return (0);
}

/**
 * validate_SetEnvArgs - Check the validity of setenv arguments
 * Return: 1 if there's an error in the setenv input, 0 otherwise
 * @InputCmd: Array containing the user's input command
 * @execStatus: Pointer to the execution status
 */
int validate_SetEnvArgs(char **InputCmd, int *execStatus)
{
	if ((InputCmd[1] == NULL) || (InputCmd[2] == NULL) || (InputCmd[3] != NULL))
	{
		releaseMemory(InputCmd);
		*execStatus = 2;
		return (1);
	}
	return (0);
}

/**
 * apply_EnvChange - Apply changes to an environment variable
 * Return: 0 on success, -1 on failure
 * @envVar: The environment variable to modify
 * @envValue: The value to assign to the environment variable
 */
int apply_EnvChange(char *envVar, char *envValue)
{
	if (setenv(envVar, envValue, 1) == -1)
	{
		return (-1);
	}
	
	return (0);
}
