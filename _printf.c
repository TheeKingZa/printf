#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char buffer[BUFFER_SIZE];
    char *buffer_ptr = buffer;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            /* Handle conversion specifier */
            count += handler(format, args, buffer_ptr, &count);
        }
        else
        {
            /* Regular character, copy to buffer */
            *buffer_ptr = *format;
            buffer_ptr++;
            count++;
        }

        format++;

        /* Flush the buffer if it is full */
        if (buffer_ptr == buffer + BUFFER_SIZE)
        {
            write(1, buffer, BUFFER_SIZE);
            buffer_ptr = buffer;
        }
    }

    /* Write any remaining characters in the buffer */
    if (buffer_ptr != buffer)
    {
        write(1, buffer, buffer_ptr - buffer);
    }

    va_end(args);

    return (count);
}

