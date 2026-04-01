#include "main.h"

/**
 * _strspn - gets length of prefix substring
 * @s: string to scan
 * @accept: accepted bytes
 *
 * Return: number of matching bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;
	int found;

	for (i = 0; s[i] != '\0'; i++)
	{
		found = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}

		if (!found)
		{
			break;
		}
	}

	return (i);
}
