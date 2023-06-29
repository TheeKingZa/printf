#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_string - Prints a string with special handling for
 *                non-printable characters
 * @types: Variable argument list
 * @buffer: Buffer to store the formatted output
 * @flags: Flags for formatting options
 * @width: Minimum field width
 * @precision: Precision for string and numeric conversions
 * @size: Length modifier size
 *
 * Return: Number of characters printed
 */
int print_string(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
char *str = va_arg(types, char*);
int count = 0;
int i = 0;


if (str == NULL)
str = "(null)";

while (str[i] != '\0')
{
if (str[i] < ' ' || str[i] >= 127)
{
count += snprintf(buffer + count, BUFFER_SIZE - count, "\x%02X", (unsigned char)str[i]);
}
else
{
buffer[count++] = str[i];
}
if (count >= BUFFER_SIZE - 1)
{
/* Buffer is full, write it to standard output */
write_buffer(buffer, count);
count = 0;
}
i++;
}
/* Write remaining characters in the buffer to standard output */
write_buffer(buffer, count);
return (i);
}
