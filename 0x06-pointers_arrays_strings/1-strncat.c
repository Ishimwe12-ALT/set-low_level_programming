#include "main.h"

/**
 * _strncat - concatenates two strings with byte limit
 * @dest: destination string
 * @src: source string
 * @n: maximum bytes to use from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
