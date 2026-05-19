#include <stdio.h>

/**
 * tortoise - prints before main function
 */
void __attribute__((constructor)) tortoise(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
