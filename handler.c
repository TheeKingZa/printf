#include "main.h"

/**
 * handle_print - Handles the format specifier and calls the appropriate function
 * @fmt: Format string
 * @i: Pointer to the current index of the format string
 * @list: Variable argument list
 * @buffer: Buffer to store the formatted output
 * @flags: Flags for formatting options
 * @width: Minimum field width
 * @precision: Precision for string and numeric conversions
 * @size: Length modifier size
 *
 * Return: Number of characters printed for the current format specifier
 */
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size)
{
    int j, count = 0;
    fmt_t format_specifiers[] = {
        {'d', print_int},
        {'i', print_int},
        {'b', print_binary},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hexadecimal},
        {'X', print_hexa_upper},
        {'S', print_non_printable},
        {'p', print_pointer},
        {'r', print_reverse},
        {'R', print_rot13string},
        {'\0', NULL}
    };

    for (j = 0; format_specifiers[j].fmt != '\0'; j++)
    {
        if (format_specifiers[j].fmt == fmt[*i])
        {
            count = format_specifiers[j].fn(list, buffer, flags, width, precision, size);
            break;
        }
    }

    if (format_specifiers[j].fmt == '\0')
    {
        buffer[0] = '%';
        buffer[1] = fmt[*i];
        count = 2;
        write(1, buffer, count);
    }

    (*i)++;

    return (count);
}

