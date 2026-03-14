#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string
 *
 * Return: pointer to str
 */
char *cap_string(char *str)
{
	int i = 0;
	int cap = 1;

	while (str[i] != '\0')
	{
		if (cap && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}

		cap = (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			   str[i] == ',' || str[i] == ';' || str[i] == '.' ||
			   str[i] == '!' || str[i] == '?' || str[i] == '"' ||
			   str[i] == '(' || str[i] == ')' || str[i] == '{' ||
			   str[i] == '}');

		i++;
	}

	return (str);
}
