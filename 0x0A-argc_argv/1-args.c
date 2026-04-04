#include "main.h"

/**
 * main - prints the number of arguments passed to it
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	(void)argv;
	int num;
	int remainder;

	num = argc - 1;
	if (num == 0)
	{
		_putchar('0');
	}
	else
	{
		if (num >= 10)
		{
			remainder = num / 10;
			_putchar('0' + remainder);
		}
		_putchar('0' + (num % 10));
	}
	_putchar('\n');
	return (0);
}
