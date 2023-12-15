#include "shell.h"
/**
 * matchedEnv - Gets the value of an environment variable.
 * Return: The value of the environment variable if found, NULL otherwise.
 * @variable: The name of the environment variable.
*/
char *matchedEnv(char *variable)
{
	char *tempLine,  /* Temporary variable to store the environment string. */
	    *envKey,     /* To store the key part of the environment variable. */
	    *envValue,   /* To store the value part of the environment variable. */
	    *matchedEnv; /* The matching environment variable's value to be returne */
	int i;
	/* Loop through the environment variables. */
	for (i = 0; environ[i]; i++)
	{
		/* Duplicate the current environment string for manipulation. */
		tempLine = duplicateString(environ[i]);

		/* Extract the key part of the environment string. */
		envKey = strtok(tempLine, "=");

		/* Compare the extracted key with the variable we are looking for. */
		if (compareStrings(envKey, variable) == 0)
		{
			/* If the keys match, extract the value part of the environment string. */
			envValue = strtok(NULL, "\n");

			/* Duplicate the value for returning. */
			matchedEnv = strdup(envValue);

			/*Free the temporary line and return the*/
			/*matched environment variable's value*/
			free(tempLine);
			return (matchedEnv);
		}
		/* Free the temporary line if no match is found. */
		free(tempLine);
		tempLine = NULL;
	}

	/* Return NULL if no matching environment variable is found. */
	return (NULL);
}
