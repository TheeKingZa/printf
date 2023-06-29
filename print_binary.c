#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_binary - Prints a binary number
 * @types: Variable argument list
 * @buffer: Buffer to store the formatted output
 * @flags: Flags for formatting options
 * @width: Minimum field width
 * @precision: Precision for string and numeric conversions
 * @size: Length modifier size
 *
 * Return: Number of characters printed
 */
int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int num = va_arg(types, unsigned int);
	int count = 0;


/* Implementation logic for printing a binary number */

	unsigned int temp = num;
	int binaryDigits = 0;

/* Count the number of binary digits */

	while (temp > 0)
	{

	temp >>= 1;
	binaryDigits++;
}

/* Allocate enough space in the buffer for the binary representation */
	for (int i = binaryDigits - 1; i >= 0; i--)
	{
	buffer[bufferIndex++] = ((num >> i) & 1) + '0';
	}
	buffer[bufferIndex] = '\0';
/* Null-terminate the buffer */
	count = snprintf(buffer, BUFFER_SIZE, "%.0s%s", buffer, buffer);


return (count);
}
