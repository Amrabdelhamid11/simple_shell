#include "shell.h"

/**
 * splitStringIntoTokens - Splits a string into tokens.
 * Return: An array of tokens.
 * @line: The string to be split.
*/
char **splitStringIntoTokens(char *line)
{
	char *currentToken = NULL, /* Pointer to the current token. */
	    *tempLine = NULL;	   /* Temporary duplicate of the input line. */
	char **command = NULL;	   /* Array to hold the tokens. */
	int currentTokenCount = 0, /* Count of tokens found. */
	    i = 0;			   /* Iterator for the loop. */
	if (!line) /* Return NULL if the input line is NULL. */
		return (NULL);
	/* Duplicate the input line to avoid modifying the original. */
	tempLine = duplicateString(line);
	/* Get the first token. */
	currentToken = strtok(tempLine, DELIM);
	/* If no tokens are found, free memory and return NULL. */
	if (currentToken == NULL)
	{	free(line), line = NULL;
		free(tempLine), tempLine = NULL;
		return (NULL);
	}
	/* Count the number of tokens. */
	while (currentToken)
	{	currentTokenCount++;
		currentToken = strtok(NULL, DELIM);
	}
	/* Free the temporary line after counting tokens. */
	free(tempLine), tempLine = NULL;
	/* Allocate memory for the array of tokens. */
	command = malloc(sizeof(char *) * (currentTokenCount + 1));
	if (!command)
	{	free(line);
		return (NULL);
	} /* Tokenize the original line and store the tokens in the array. */
	currentToken = strtok(line, DELIM);
	while (currentToken)
	{	command[i] = duplicateString(currentToken);
		currentToken = strtok(NULL, DELIM);
		i++;
	}
	/* Free the original line and mark the end of the array with NULL. */
	free(line), line = NULL;
	command[i] = NULL;
	return (command); /* Return the array of tokens. */
}
