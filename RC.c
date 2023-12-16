#include "shell.h"

/**
 * filterOutComments - Removes comments from a string
 * Return: The string without comments
 * @sourceString: The string to remove comments from
 */

char *filterOutComments(char *sourceString)
{
	int stringIndex = 0;

	while (sourceString[stringIndex] != '\0')
	{
		switch (sourceString[stringIndex])
		{
		case '#':
			sourceString[stringIndex] = '\0';
			break;
		default:
			break;
		}

		stringIndex++;
	}

	return (sourceString);
}
