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
va_list args;
int count = 0;

va_start(args, format);

	while (*format)
{
	if (*format == '%')
	{
	format++;
	if (*format == 'd' || *format == 'i')
	{
/* Handle integer conversion specifier */
	int num = va_arg(args, int);

	count += print_integer(num);
	}
	else
	{
/* Handle unsupported conversion specifier */
	_putchar('%');
	_putchar(*format);
	count += 2;
	}
	}
	else
	{
/* Handle regular characters */
	_putchar(*format);
	count++;
	}
	format++;
}
va_end(args);
return (count);
}

/**
 * print_integer - Prints an integer to the standard output
 * @num: The integer to be printed
 *
 * Return: The number of characters printed.
 */

int print_integer(int num)
{
int count = 0;

if (num < 0)
	{
	/* Handle negative numbers */
	_putchar('-');
	count++;
	num = -num;
	}

if (num / 10)
	{
	count += print_integer(num / 10);
	}
	/* Print the digits */
	_putchar('0' + num % 10);
	count++;

	return (count);
}
