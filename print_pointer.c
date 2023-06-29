#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_pointer - Prints the memory address in hexadecimal
 * @types: Variable argument list
 * @buffer: Buffer to store the formatted output
 * @flags: Flags for formatting options
 * @width: Minimum field width
 * @precision: Precision for string and numeric conversions
 * @size: Length modifier size
 *
 * Return: Number of characters printed
 */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    void *ptr = va_arg(types, void *);
    unsigned long int address = (unsigned long int)ptr;
    int count = 0;

    count += snprintf(buffer, BUFFER_SIZE, "0x%lx", address);

    write_buffer(buffer, count);

    return (count);
}

