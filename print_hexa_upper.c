#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_hexa_upper - Prints an unsigned integer in uppercase hexadecimal format
 * @types: Variable argument list
 * @buffer: Buffer to store the formatted output
 * @flags: Flags for formatting options (+, space, #, 0, -)
 * @width: Minimum field width
 * @precision: Precision for string and numeric conversions
 * @size: Length modifier size
 *
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int num = va_arg(types, unsigned int);
	int count = 0;


/* Handle the 0 flag character */

	if (flags & FLAG_ZERO)
	{

/* Use the specified width and precision with leading zeros */

		count += snprintf(buffer + count, BUFFER_SIZE - count, "%0*.*X", width, precision, num);

	}
	else if (flags & FLAG_MINUS)
	{

/* Use the specified width and precision with left justification */

	count += snprintf(buffer + count, BUFFER_SIZE - count, "%-*.*X", width, precision, num);

	}
	else
	{

/* Use the specified width with leading zeros */

count += snprintf(buffer + count, BUFFER_SIZE - count, "%*.*0X", width, precision, num);
}

return (count);
}

