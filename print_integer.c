#include "main.h"

/**
 * print_integer - Prints an integer to the standard output
 * @num: The integer to be printed
 *
 * Return: The number of characters printed.
 */
int print_integer(int num)
{
/* char buffer[1024]; */

int count = 0;

if (num < 0)
{
	_putchar('-');
	count++;
	num = -num;
}

if (num / 10)
{
	count += print_integer(num / 10);
}

	_putchar('0' + num % 10);
	count++;

	return (count);
}

