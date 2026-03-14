#include "main.h"

/**
 * _strpbrk - searches a string for any set of bytes
 * @s: string to search
 * @accept: bytes to match
 *
 * Return: pointer to matching byte or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				return (&s[i]);
			}
		}
	}

	return (0);
}
