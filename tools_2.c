/**
 * reverseStr - Reverses a string
 * @str: The string to be reversed
 * @len: The length of the string
*/
void reverseStr(char *str, int len)
{

	char tempChar;

	int startIndex = 0;

	int endIndex = len - 1;

	while (startIndex < endIndex)
	{

		tempChar = str[startIndex];

		str[startIndex] = str[endIndex];

		str[endIndex] = tempChar;

		endIndex--;

		startIndex++;
	}
}

/**
 * st_to_int - Converts a string to an integer
 * @s: The string to be converted
 * Return: The converted integer
*/
int st_to_int(char *s)
{
	int i;
	int number = 0;

	for (i = 0; s[i]; i++)
	{

		number *= 10;

		number += (s[i] - '0');
	}
	return (number);
}

/**
 * is_numeric_string - Checks if a string is a number
 * @s: The string to be checked
 * Return: 1 if the string is a number, 0 otherwise
*/
int is_numeric_string(char *s)
{

	int i;

	if (!s)
	{
		return (0);
	}
	for (i = 0; s[i]; i++)
	{

		if (s[i] < '0' || s[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}
