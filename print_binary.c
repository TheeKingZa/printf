#include "main.h"

/**
 * print_binary - Print an unsigned integer in binary format.
 *
 * @num: The unsigned integer to be printed in binary.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
	int count = 0, binary[32], i;

	if (num == 0)
	{
		_putchar('0');
		count++;

		return (count);

	}

	for (i = 0; num > 0; i++)
	{
	binary[i] = num % 2;
	num /= 2;
	}

	for (i = i - 1; i >= 0; i++)
	{
		_putchar('0' + binary[i]);
		count++;
	}

	return (count);
}
