#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int count;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = handler(format, args, buffer, &count);
	va_end(args);

	write(1, buffer, count);

	return (count);
}

