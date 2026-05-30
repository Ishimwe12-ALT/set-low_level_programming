#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char p[7], *c;
	int len, i, t;

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	c = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	len = strlen(argv[1]);

	p[0] = c[(len ^ 59) & 63];
	for (i = 0, t = 0; i < len; i++)
		t += argv[1][i];
	p[1] = c[(t ^ 79) & 63];
	for (i = 0, t = 1; i < len; i++)
		t *= argv[1][i];
	p[2] = c[(t ^ 85) & 63];
	for (i = 0, t = 0; i < len; i++)
		if (argv[1][i] > t)
			t = argv[1][i];
	srand(t ^ 14);
	p[3] = c[rand() & 63];
	for (i = 0, t = 0; i < len; i++)
		t += (argv[1][i] * argv[1][i]);
	p[4] = c[(t ^ 239) & 63];
	for (i = 0; i < argv[1][0]; i++)
		t = rand();
	p[5] = c[(t ^ 229) & 63];
	p[6] = '\0';

	printf("%s", p);
	return (0);
}
