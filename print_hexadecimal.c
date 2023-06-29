#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_hexadecimal - Prints a hexadecimal number in lowercase
 * @types: Variable argument list
 * @buffer: Buffer to store the formatted output
 * @flags: Flags for formatting options (+, space, #, 0, -)
 * @width: Minimum field width
 * @precision: Precision for numeric conversions
 * @size: Length modifier size (l, h)
 *
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned int num = va_arg(types, unsigned int);
    int count = 0;

    /* Handle the 0 flag character */
    if (flags & FLAG_ZERO)
        count += snprintf(buffer + count, BUFFER_SIZE - count, "%0*.*x", width, precision, num);
    else if (flags & FLAG_MINUS)
        count += snprintf(buffer + count, BUFFER_SIZE - count, "%-*.*x", width, precision, num);
    else
        count += snprintf(buffer + count, BUFFER_SIZE - count, "%*.*x", width, precision, num);

    write_buffer(buffer, count);

    return (count);
}

