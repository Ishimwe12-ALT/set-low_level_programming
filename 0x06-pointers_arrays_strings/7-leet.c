#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: pointer to encoded string
 */
char *leet(char *s)
{
	int i, j;
	char lower[] = "aeotl";
	char upper[] = "AEOTL";
	char leet[] = "43071";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (s[i] == lower[j] || s[i] == upper[j])
			{
				s[i] = leet[j];
			}
		}
	}

	return (s);
}
