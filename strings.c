#include "shell.h"

/**
 * duplicateString - Duplicates a string
 * Return: A pointer to the duplicated string
 * @str: The string to be duplicated
*/
char *duplicateString(char *str)
{
	char *newString;
	int len = 0;
	int i;

	/*     Check if input string is NULL */
	if (str == NULL)
	{

		return (NULL);
	}

	/*  Calculate the length of the input string */
	while (str[len])
	{

		len++;
	}

	/*  Allocate memory for the new string */
	newString = malloc(sizeof(char) * (len + 1));

	/* Check if memory allocation was successful */
	if (newString == NULL)
	{

		return (NULL);
	}

	/* Copy the characters from the input string to the new string */
	for (i = 0; i <= len; i++)
	{

		newString[i] = str[i];
	}

	return (newString);
}

/**
 * compareStrings - Compares two strings
 * Return: 1 if the strings are equal, 0 otherwise
 * @str1: The first string
 * @str2: The second string
*/
int compareStrings(char *str1, char *str2)
{
	int comparisonResult;

	/* Compare characters in the strings until a difference is found */
	comparisonResult = (int)*str1 - (int)*str2;

	while (*str1)
	{

		if (*str1 != *str2)
		{

			break;
		}
		str1++;

		str2++;

		comparisonResult = (int)*str1 - (int)*str2;
	}

	return (comparisonResult);
}

/**
 * stringLength - Returns the length of a string
 * Return: The length of the string
 * @str: The string to be measured
*/
int stringLength(char *str)
{
	int len = 0;

	/* Count the characters in the string until the null terminator is reached */
	while (str[len])
	{

		len++;
	}
	return (len);
}

/**
 * concatenateStrings - Concatenates two strings
 * Return: A pointer to the concatenated string
 * @dest: The destination string
 * @src: The source string
*/
char *concatenateStrings(char *dest, char *src)
{
	char *destPtr = dest;

	/* Move the destination pointer to the end of the destination string */
	while (*destPtr)
	{

		destPtr++;
	}

	/* Copy characters from the source string to the destination string */
	while (*src)
	{

		*destPtr = *src;

		destPtr++;

		src++;
	}

	/* Add a null terminator to the end of the concatenated string */
	*destPtr = '\0';

	return (dest);
}

/**
 * copyString - Copies a string
 * Return: A pointer to the copied string
 * @dest: The destination string
 * @src: The source string
*/
char *copyString(char *dest, char *src)
{
	int i = 0;

	/*  Copy characters from the source string to the destination string */
	while (src[i])
	{

		dest[i] = src[i];

		i++;
	}

	/* Add a null terminator to the end of the destination string */
	dest[i] = '\0';

	return (dest);
}
