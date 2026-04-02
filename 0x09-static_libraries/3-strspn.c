#include "main.h"
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int i, j, match;
	for (i = 0; s[i]; i++)
	{
		match = 0;
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
		}
		if (!match) return (n);
		n++;
	}
	return (n);
}
