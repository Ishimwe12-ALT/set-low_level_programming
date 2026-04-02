#include "main.h"
char *_strcpy(char *dest, char *src)
{
	int i = -1;
	while ((dest[++i] = src[i])) ;
	return (dest);
}
