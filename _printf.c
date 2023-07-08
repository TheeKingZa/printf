#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    unsigned int i = 0, count = 0;
    va_list args;
    va_start(args, format);
    if (!format)
        return (-1);
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c')
            {
                _putchar(va_arg(args, int));
                count++;
            }
            else if (format[i + 1] == 's')
            {
                count += print_string(va_arg(args, char *));
            }
            else if (format[i + 1] == '%')
            {
                _putchar('%');
                count++;
            }
            else if (format[i + 1] == 'i' || format[i + 1] == 'd')
            {
                count += print_int(va_arg(args, int));
            }
            else if (format[i + 1] == 'b')
            {
                count += print_binary(va_arg(args, int));
            }
            /*
                       else if (format[i + 1] == 'u')
            {
                count += print_unsigned(va_arg(args, unsigned int));
            }
            else if (format[i + 1] == 'o')
            {
                count += print_octal(va_arg(args, unsigned int));
            }
            else if (format[i + 1] == 'x')
            {
                count += print_hex_low(va_arg(args, unsigned int));
            }
            else if (format[i + 1] == 'X')
            {
                count += print_hex_upp(va_arg(args, unsigned int));
            }
            else if (format[i + 1] == 'S')
            {
                count += print_non(va_arg(args, char *));
            }
            */
            else
            {
                _putchar(format[i]);
                count++;
            }
            i++;
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}
