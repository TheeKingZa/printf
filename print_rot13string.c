#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/* Helper function to perform the rot13 transformation */
char rot13(char c)
{

if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))

return (c + 13);

else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))

	return (c - 13);

else


return (c);
}

/**
 * print_rot13string - Prints a rot13'ed string
 * @types: Variable argument list
 * @buffer: Buffer to store the formatted output
 * @flags: Flags for formatting options
 * @width: Minimum field width
 * @precision: Precision for string and numeric conversions
 * @size: Length modifier size
 *
 * Return: Number of characters printed
 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int count = 0;
	int length = strlen(str);


/* Print leading spaces if necessary */

	if (width > length)

	{

	int spaces = width - length;

	for (int i = 0; i < spaces; i++)
        
	{

	count += snprintf(buffer + count, BUFFER_SIZE - count, " ");

	}

}

/* Perform the rot13 transformation and print the string */
	for (int i = 0; i < length; i++)
	{

	count += snprintf(buffer + count, BUFFER_SIZE - count, "%c", rot13(str[i]));
	}

return (count);
}

