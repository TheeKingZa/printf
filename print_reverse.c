#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * print_reverse - Prints a reversed string
 * @types: Variable argument list
 * @buffer: Buffer to store the formatted output
 * @flags: Flags for formatting options
 * @width: Minimum field width
 * @precision: Precision for string and numeric conversions
 * @size: Length modifier size
 *
 * Return: Number of characters printed
 */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int length = strlen(str);
	int count = 0;

/* Handle the - flag character */
	if (flags & FLAG_MINUS)
	{
/* Print the reversed string */
	for (int i = length - 1; i >= 0; i--)
	{
	count += snprintf(buffer + count, BUFFER_SIZE - count, "%c", str[i]);
	}
	}
	else
	{
/* Print leading spaces if necessary */
	if (width > length)
	{
	int spaces = width - length;

	for (int i = 0; i < spaces; i++)
	{

		count += snprintf(buffer + count, BUFFER_SIZE - count, " ");
	}
        }
/* Print the reversed string */
	for (int i = length - 1; i >= 0; i--)
	{
	count += snprintf(buffer + count, BUFFER_SIZE - count, "%c", str[i]);
	}
	}
return (count);
}
