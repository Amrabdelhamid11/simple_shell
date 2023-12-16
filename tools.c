#include "shell.h"

/**
 * free2DArray - Frees a 2D array of strings
 * @array: The 2D array to be freed
*/
void free2DArray(char **array)
{
	int i;

	if (!array)
	{
		/* No need to free if the array is NULL */
		return;
	}
	for (i = 0; array[i]; i++)
	{

		free(array[i]);

		array[i] = NULL;
	}
	/*  Free the array itself */
	free(array);
	/*  Set the pointer to NULL to prevent further access */
	array = NULL;
}

/**
 * displayError - Displays an error message
 * @name: The name of the shell
 * @parsedCommand: The parsed command
 * @idx: The index of the command
*/
void displayError(char *name, char *parsedCommand, int idx)
{

	char *index;
	/*  Fixed a typo in the error message */
	char errorMessage[] = ": not found\n";

	index = integer_to_string(idx);

	write(STDERR_FILENO, name, stringLength(name));

	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, index, stringLength(index));

	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, parsedCommand, stringLength(parsedCommand));

	write(STDERR_FILENO, errorMessage, stringLength(errorMessage));

	free(index);
}

/**
 * integer_to_string - Converts an integer to a string
 * @num: The integer to be converted
 * Return: The string representation of the integer
*/
char *integer_to_string(int num)
{

	char numBuffer[20];

	int i = 0;

	if (num == 0)
	{

		numBuffer[i++] = '0';
	}
	else
	{
		while (num > 0)
		{

			numBuffer[i++] = (num % 10) + '0';

			num /= 10;
		}
	}

	numBuffer[i] = '\0';

	reverseStr(numBuffer, i);

	return (duplicateString(numBuffer));
}

