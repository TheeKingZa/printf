#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_octal - Prints an octal number
 * @types: Variable argument list
 * @buffer: Buffer to store the formatted output
 * @flags: Flags for formatting options (+, space, #)
 * @width: Minimum field width
 * @precision: Precision for numeric conversions
 * @size: Length modifier size (l, h)
 *
 * Return: Number of characters printed
 */
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned int num = va_arg(types, unsigned int);
    int count = 0;

    // Handle field width and precision
    count += snprintf(buffer, BUFFER_SIZE, "%*.*o", width, precision, num);

    write_buffer(buffer, count);

    return (count);
}

