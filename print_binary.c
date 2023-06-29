#include "main.h"

/**
 * print_binary - Prints an unsigned integer in
 *			binary format to the standard output
 * @num: The unsigned integer to be printed
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{

int count = 0;

if (num / 2)
{
	count += print_binary(num / 2);
}

_putchar('0' + num % 2);
count++;

return (count);
}

