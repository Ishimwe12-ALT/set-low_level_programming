#include <stdio.h>
#include "main.h"

/**
 * main - prints the number of arguments passed into it
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	int count = argc - 1;

	if (count >= 10)
	{
		/* This handles two digit numbers if necessary */
		_putchar((count / 10) + '0');
	}
	_putchar((count % 10) + '0');
	_putchar('\n');

	return (0);
}
