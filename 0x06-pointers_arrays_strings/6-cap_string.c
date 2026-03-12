#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: pointer to modified string
 */
char *cap_string(char *s)
{
	int i;
	int capitalize_next;

	capitalize_next = 1;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' && capitalize_next)
		{
			s[i] = s[i] - 32;
			capitalize_next = 0;
		}
		else if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
			s[i] == ',' || s[i] == ';' || s[i] == '.' ||
			s[i] == '!' || s[i] == '?' || s[i] == '"' ||
			s[i] == '(' || s[i] == ')' || s[i] == '{' ||
			s[i] == '}')
		{
			capitalize_next = 1;
		}
		else
		{
			capitalize_next = 0;
		}
	}

	return (s);
}
