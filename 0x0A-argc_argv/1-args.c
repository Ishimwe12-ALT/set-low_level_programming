#include "main.h"

/**
 * main - prints number of arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int n = argc - 1;

	(void)argv;

	if (n == 0)
		_putchar('0');
	else if (n == 1)
		_putchar('1');
	else if (n == 2)
		_putchar('2');
	else if (n == 3)
		_putchar('3');
	else if (n == 4)
		_putchar('4');
	else if (n == 5)
		_putchar('5');
	else if (n == 6)
		_putchar('6');
	else if (n == 7)
		_putchar('7');
	else if (n == 8)
		_putchar('8');
	else if (n == 9)
		_putchar('9');

	_putchar('\n');

	return (0);
}
