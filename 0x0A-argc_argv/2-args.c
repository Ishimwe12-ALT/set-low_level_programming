#include "main.h"

/**
 * main - prints all arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i, j;

	for (i = 0; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			_putchar(argv[i][j]);
			j++;
		}
		_putchar('\n');
	}

	return (0);
}
