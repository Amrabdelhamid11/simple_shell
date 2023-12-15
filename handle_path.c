#include "shell.h"

/**
 * path - Gets the full path of a command.
 * Return: The full path of the command if found, NULL otherwise.
 * --------------------------
 * Prototype: char *path(char *command);
 * --------------------------
 * @command: The command for which the full path is to be found.
 * --------------------------
 * By Amr Abdelhamid
 */
char *path(char *command)
{	char *pathEnvironment,	  /* To store the PATH environment variable. */
	    *completeCommandPath, /* To build the full path of the command. */
	    *directory;		  /* To store each directory in the PATH. */
	/* Used to check if the command exists in a directory. */
	struct stat fileStat;
	int i;
	/* Check if the command already contains a '/' character (i.e., it's a path)*/
	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{	/* Check if the path is valid and the file exists. */
			if (stat(command, &fileStat) == 0)
				return (duplicateString(command));/*Return the CMD if it's a valid path*/
			return (NULL); /* Return NULL if the path is not valid. */
		}
	}
	/* Get the PATH environment variable. */
	pathEnvironment = matchedEnv("PATH");
	if (!pathEnvironment)
		return (NULL); /* Return NULL if PATH is not set. */
	/* Tokenize the PATH variable to get each directory. */
	directory = strtok(pathEnvironment, ":");
	while (directory)
	{ completeCommandPath = /* Allocate memory for the full command path. */
		malloc(stringLength(directory) + stringLength(command) + 2);
		if (completeCommandPath)
		{ /* Construct the full path of the command. */
			copyString(completeCommandPath, directory);
			concatenateStrings(completeCommandPath, "/");
			concatenateStrings(completeCommandPath, command);
			/* Check if the command exists in this directory. */
			if (stat(completeCommandPath, &fileStat) == 0)
			{	free(pathEnvironment);		/* Free the PATH string. */
				return (completeCommandPath); /* Return the full path of the command. */
			} /* Free the allocated memory if the command is not found in this dir...*/
			free(completeCommandPath);
			completeCommandPath = NULL;
			directory = strtok(NULL, ":"); /* Move to the next directory in PATH. */
		} /* Free the PATH string and return NULL if the command is not found. */
	} free(pathEnvironment);
	return (NULL);
}
