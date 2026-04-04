#include "main.h"

/**
 * print_number - prints an integer using _putchar
 * @n: the integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	if (n >= 10)
		print_number(n / 10);
	_putchar('0' + (n % 10));
}

/**
 * main - adds positive numbers passed as arguments
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i;
	int j;
	int sum;

	sum = 0;
	if (argc == 1)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				_putchar('E');
				_putchar('r');
				_putchar('r');
				_putchar('o');
				_putchar('r');
				_putchar('\n');
				return (1);
			}
			sum = sum * 10 + (argv[i][j] - '0');
			j++;
		}
		i++;
	}
	print_number(sum);
	_putchar('\n');
	return (0);
}
